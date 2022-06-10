#include<iostream>
#include<cstdarg>
/*
	Assignment will mix both strings adn dynamic memory management.
	Create a string_concat function that uses varialbe argements. 
	The purpose of the function is toallow any number of string
	to be combined into a single string. The function should
	allocate the string that is returned; 
*/



char* string_concat(const char* str ...); 

int main() 
{
	char* concat_str = string_concat("hello", " what is", "your name", nullptr);

	printf("%s",concat_str);


	return 0; 
}

/*Char pointer returning functions takes varialble char* arguments and
	returns a pointer to a string allocated in the heap */ 
char* string_concat(const char* str...) 
{
	if (str == nullptr) { return nullptr; } // return nullptr if arg nullptr

	// arg holds list of arguments 
	std::va_list arg;  
	std::va_list arg2; 
	
	int size = 0;
	va_start(arg, str); // must initalze start with variable list before call to va_arg
	va_copy(arg2, arg); // copy src arg to des arg2
	// Out for loop iterate each argument
	for (const char* arg_ptr = str; (int*)(arg_ptr) != (nullptr); arg_ptr = va_arg(arg, char*))
	{
		// iterate through each character of arg string
		for (const char* ptr = arg_ptr; *ptr != '\0'; ++ptr)
		{
			++size; // get size
		}
	}
	va_end(arg); // clean up list
	// va_arg calls moves to next arguement

	char* temp = new char[++size]; // new string array 
	int i = 0;
	va_start(arg2, str); // arg2 starts with 1st arg in str
	// now copy each character from arguments to dynamic array 
	for (const char* arg_ptr = str; (int*)(arg_ptr) != (nullptr); arg_ptr = va_arg(arg2, char*))
	{
		// iterate through each character of arg string
		for (const char* ptr = arg_ptr; *ptr != '\0'; ++ptr,++i)
		{
			*(temp + i) = *ptr; // copy data 
		}
	}
	temp[--size] = '\0'; 
	va_end(arg2); // clean up list
	return temp; 

}