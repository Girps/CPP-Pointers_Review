
#include<iostream>
#include<stdlib.h>
#include<string.h>

struct Base 
{
	int a; 
	char name[5]; 
};

/*Deriv aggregates Base type, technically we reused code from Base 
	class to Deriv clases */
struct Deriv 
{
	Base inherit;
	int B; 
};

void printBase(Base *bp) 
{
	std::cout << "Base member - A: " << bp->a; 
	std::cout << "\n - name: " << bp->name << "\n"; 
}


int main() 
{
	Deriv* dp = new Deriv; 

	if (!dp) {
		exit(0);
	}

	Base* bp = (Base*)dp; // down cast to base pointer

	bp->a = 10; 
	dp->B = 20; 
	strcpy_s(bp->name, "mike");
	std::cout << "Deriv: " << std::endl; 
	std::cout << " A : " << ((Base*)dp)->a << std::endl; 
	std::cout << " name :" << ((Base*)dp)->name << std::endl;
	std::cout << " B : " << dp->B << std::endl; 
	printBase(bp); 

	std::cout << "Base address: " << bp << "\n";
	std::cout << "Derived address: " << dp << "\n" << std::hex; 

	delete dp; 


	return 0; 
}