#include "Stack.h"



/* Void function increases size of the stack by at least 10 */
void Stack::growStack() 
{
	void** tmp1 = 0; 
	short* tmp2 = 0; 

	tmp1 = new void* [space + 10]; // An array of at least 10 elements of type void pointers holds data
	tmp2 = new short[space + 10];  // An arry of at least 10 elements of type short

	// copy from old array to new array 
	memcpy(tmp1,storage,sizeof(void*) * space); // copy data from old array to new array
	memcpy(tmp2,types,sizeof(short) * space); // copy enum values from old array to new array

	// delete old arrays 
	delete storage;
	delete types; 

	storage = tmp1; 
	types = tmp2; 

	space += 10; 
}

Stack::Stack() 
{
	storage = 0; 
	types = 0; 
	top = space = 0; 
}

Stack::~Stack() 
{
	int i = 0;

	for (i = 0; i < top; i++) 
	{
		delete storage[i]; // destruct and delete data in array of void pointers
	}

	delete types; 
	delete storage; 
	storage = 0; 
	types = 0; 
	top = space = 0; 
}

void Stack::push(void *val, short type) 
{
	// void pointer hold address of any data 
	void* tmp = 0; 
	// len for array like data types
	int len = 0;
	if (!val) 
	{
		return; 
	}

	switch (type) 
	{
	case Long:
		tmp = (void*) new long; 
		std::memcpy(tmp,val,sizeof(long));
		break;
	case Double:
		tmp = (void*) new double; 
		std::memcpy(tmp,val,sizeof(double));
		break; 
	case String:
		len = strlen((char*)val); 
		tmp = (void*) new char[len + 1]; 
		strcpy((char* )tmp,(char*) val); // copy charactes to tmp 
		break;
	default:
		std::cout << "Unknown type <" << type << ">" << std::endl; 
		return; 
	}
	// We get a copy of the data now place it on the stack!

	// If we are ontop of the stack grow it and push 
	if (top == space) 
	{
		growStack(); 
	}

	storage[top] = tmp; 
	types[top] = type; 
	top++; 
}

void* Stack::pop(short* type)
{
	if (top)
	{
		top--; 
		*type = types[top]; 
		return storage[top];
	}
	else 
	{
		std::cout << "Stack empty!" << std::endl; 
	}

	return 0; 
}

std::ostream& operator << (std::ostream& stream, Stack& obj) 
{
	int i = 0; 
	std::cout << "Top of STACK" << std::endl; 
	for (i = (obj.top - 1); i >= 0; --i) 
	{
		switch (obj.types[i])
		{
		case Long:
			std::cout << *((long*)obj.storage[i]) << std::endl; 
			break; 
		case Double:
			std::cout << *((double*)obj.storage[i]) << std::endl; 
			break; 
		case String: 
			std::cout << ((char*)obj.storage[i]) << std::endl; 
			break; 
		default:
			std::cout << "Unknown type <" << obj.types[i] << ">" << std::endl; 
			return stream; 
		}
	}
	return stream; 
}

void exhausted() 
{
	std::cout << "Exhausted the free store!" << std::endl; 
	exit(1);
}


