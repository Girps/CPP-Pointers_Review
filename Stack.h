#ifndef Stack
#define Stack 
#undef Stack 
#include <iostream>
#include<string>
enum Type {Long, Double, String}; 

class Stack 
{
	void** storage; // array holds pointer of generic data types
	short* types; // keeps track of what type of data is on the stack
	int top; // index on to top of stack of constructed type
	int space; // amount of allocated space on the heap 
	void growStack();
	public: 
		Stack(); 
		~Stack(); 
		void push(void* val, short type); 
		void* pop(short* type);
		friend std::ostream& operator << (std::ostream& stream, Stack& obj); 
};


#endif 