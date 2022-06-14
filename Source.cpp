// virtual.cpp 
#include<iostream>

#include "Stack.h"

int main() 
{
	Stack mystack; 
	long age;

	double gpa; 

	mystack.push((char*)"Lynne", String); 
	age = 25;
	gpa = 3.8; 
	mystack.push(&age, Long); 
	mystack.push(&gpa, Double); 

	std::cout << mystack;
	std::cout << std::endl; 

	void* val; 
	short type;
	val = mystack.pop(&type);

	std::cout << mystack; 

	return 0; 


}