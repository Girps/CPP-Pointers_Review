#ifndef little
#define little 

#include<iostream>
struct LittleBag;
class little_;

// storage globals 
LittleBag* store = nullptr;
int store_sz = 0;
int store_idx = 0;
int store_max = 5;	// such a tiny strt for demo purposes only

class little_
{
protected:
	int num;
public:
	little_();
	little_(int innum);
	void setnum(int innum);
	void prtnum();
	void* operator new(size_t bytes);
	void  operator delete(void* type);


};
// wrapper structure to store info on the status
// of the dynamic object incidcates what is free or deleted 
// in heap array
struct LittleBag
{
	little_ theobject;
	short free;
};

void exhausted();


// def cons
little_::little_() { this->num = 0; }
// Conversion cons
little_::little_(int innum) { num = innum; }
// setter cons
void little_::setnum(int innum) { num = innum; }
// void prints int
void little_::prtnum() { std::cout << num; }

// void pointer returning function, allocates an array of sizeof(LittleBag) and returns a freed node address 
void* little_::operator new(size_t bytes)
{
	little_* lp = 0;
	int i = 0;

	// store_sz is empty allocate array in the heap of size store_max of type littleBag
	if (!store_sz)
	{
		// Create store
		store = (LittleBag*)malloc(sizeof(LittleBag) * store_max);
		if (!store) // if store empty call exhausted()
			exhausted(); // means malloc failed to allocate memory on the heap 
		// initialze
		for (i = 0; i < store_max; i++)
		{
			store[i].free = 0;
		}
		store_sz = store_max; // set stored size equal to max 
		store_idx = 0;
	} // if store_idx is less than store max returns an freed spot	
	if (store_idx < store_max)
	{
		// return an open entry of uninitalized memory and increment to next sizeof(LittleBag) bytes! 
		std::cout << "Node " << store_idx << " is open.\n";
		return &(store[store_idx++].theobject);
	} // Now free spots avaliable
	else
	{
		std::cout << "No open entries.\n";
		// check if one is deleted
		for (i = 0; i < store_max; i++)
		{
			// check if the array has a free spot
			if (store[i].free)
			{
				std::cout << "Node. " << i << " is free.\n";
				store[i].free = 0; // No set flag to occupied
				return &(store[i].theobject); // Now return the address of free node
			}
		}

		// check if i == store_max means all heap space is used up 
		if (i == store_max)
		{
			// if none deleted 
			// expand store 
			// or return 0 - for now lets just exhaust the store
			exhausted();
		}
	}

	return 0;
}


void little_::operator delete(void* type)
{
	int i = 0;
	// mark as deleted
	// since our store is tiny we will do this with brute force

	if (!type)
	{
		return; // if type is null return 
	}
	// check the address that matches address held by the pointer
	for (i = 0; i < store_max; i++)
	{
		// if address matched set to free 
		if (type == &(store[i].theobject))
		{
			std::cout << "Deleting Node " << i << "\n";
			store[i].free = 1;
		}
	}
}

void exhausted()
{
	std::cout << "Exhausted the store.";
	exit(0);
}


#endif // !1
