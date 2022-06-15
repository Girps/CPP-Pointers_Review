#include<stdio.h>
#include<stdlib.h>

void stdError(char *str, short fatal)
{
    printf("%s",str);
    if(fatal)
        exit(1);
}

typedef struct Base Base;
typedef Base *Basep;


/* V table*/
typedef struct vTbl vTbl;
typedef vTbl *vTblp;
struct vTbl
{
    int A;
    // Struct contains function pointer hold address of function of void return and Base* args
    void (*print)(Basep this);
    void (*set)(Basep this);
};

// Simple Base Class
struct Base
{
    int A;
    void (*construct)(Basep this);
    void (*destruct)(Basep this);
    vTblp vptr; // vTable structure in Base
};

void construct_Base(Basep this)
{
    printf("Calling base constructor.\n");
    this->A = 0;
    this->vptr = (vTblp)malloc(sizeof(vTbl)); // allocate a vTbl in the heap contains two function pointers
    if(!this->vptr){stdError("Allocation Error\n",1); }
}

void destruct_Base(Basep this)
{
    printf("Calling Base Destructor.\n");
    this->A = 0;
    free(this->vptr); // deallocate vTable
}

Base INITBase = {0,construct_Base,destruct_Base,0};

/*Simple Deriv1 Class*/
typedef struct Deriv1 Deriv1;
typedef Deriv1 *Deriv1p;
struct Deriv1
{
    Base base;
    int B;
    // Deriv1 struct contains 4 void pointers
    void (*construct)(Deriv1p this);
    void (*destruct) (Deriv1p this);
    void (*print)(Basep this); // will override the base function print
    void (*set)(Basep this);  // will override the base function set
};

void print_Deriv1(Basep this)
{
    printf("A: %d",this->A);
    printf("B: %d",(((Deriv1p)this)->B));
}

void set_Deriv1(Basep this)
{
    printf("A: ");
    scanf("%d",&(this->A));
    printf("B: ");
    scanf("%d",&(((Deriv1p)this)->B));
}

void construct_Deriv1(Deriv1p this)
{
    construct_Base((Basep)this);
    this->base.vptr->print = print_Deriv1; // base vptr print is now assigned to overrided fucntion label
    this->base.vptr->set = set_Deriv1; // base vptr set is now assigned to overrided function label
    printf("Calling Deriv1 Constructor.\n");
}

void destruct_Deriv1(Deriv1p this)
{
    printf("Calling Deriv1 Destructor.\n");
    this->B = 0; // destructing memebr B of derive structure
    destruct_Base((Basep)this); // destructing memeber of Base structure
}
// global struct
Deriv1 INITDeriv1 = {{0,0},0,construct_Deriv1,destruct_Deriv1,print_Deriv1,set_Deriv1};

// Simple Deriv2 class
typedef struct Deriv2 Deriv2;
typedef Deriv2 *Deriv2p;
struct Deriv2
{
    Base base;
    int C;
    void (*construct)(Deriv2p this);
    void (*destruct)(Deriv2p this);
    void (*print)(Basep this);
    void (*set)(Basep this);
};

void print_Deriv2(Basep this)
{

    printf("A : %d.\n",this->A);
    printf("C : %d.\n",((Deriv2p)this)->C);
}

void set_Deriv2(Basep this)
{
    printf("A : ");
    scanf("%d",&(this->A));
    printf("C: ");
    scanf("%d",&(((Deriv2p)this)->C));
}

void construct_Deriv2(Deriv2p this)
{
    construct_Base((Basep)this);
    this->base.vptr->print = print_Deriv2;
    this->base.vptr->set = set_Deriv2;
    printf("Calling Deriv2 Constructor.\n");
    this->C = 0;
}

void destruct_Deriv2(Deriv2p this)
{
    printf("Calling Deriv2 Destructor.\n");
    this->C = 0;
    destruct_Base((Basep)this);
}

// global struct
Deriv2 INITDeriv2 = {{0,0},0,construct_Deriv2,destruct_Deriv2,print_Deriv2,set_Deriv2};


int main()
{
    Deriv1 ob1;
    Deriv2 ob2;
    Basep bp1,bp2;
    // initialize memebers function pointers
    ob1 = INITDeriv1;
    ob2 = INITDeriv2;

    ob1.construct(&ob1); // call constructor to initlalize base memebers
    ob2.construct(&ob2);

    // Base pointer initlaize to address of deriv memeber base
    bp1 = (Basep) &ob1;
    bp2 = (Basep) &ob2;

    printf("Base Pointer->Deriv1 Object.\n");
    bp1->vptr->set(bp1);
    bp1->vptr->print(bp1);
    printf("\n");

    printf("Base Pointer->Deriv2 Object.\n");
    bp2->vptr->set(bp2);
    bp2->vptr->print(bp2);

    ob1.destruct(&ob1);
    ob2.destruct(&ob2);

    return 0;
}
