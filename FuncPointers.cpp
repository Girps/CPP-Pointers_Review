#include<iostream>
#include<stdlib.h>
#include<string>
#include<ctype.h>

long add_em(int a, int b) 
{
	return ((a + b)); 
}

long sub_em(int a, int b)
{
	return ((a - b));
}

long mult_em(int a, int b) 
{
	return ((a*b)); 
}

void upcase(char** instr) 
{
	int i, len; 

	if (instr) 
	{
		len = strlen(*instr);
		for (i = 0; i < len; i++) 
		{
			if (islower((*instr)[i])) 
			{
				(*instr)[i] = toupper((*instr)[i]); 
			}
		}
	}
}

char* reverse_em(char* instr) 
{
	int i, j, len;

	char* outstr = nullptr;

	if (instr) 
	{
		len = strlen(instr);
		outstr = (char*)malloc(sizeof(char) * (len + 1));
		if (outstr) 
		{
			for (i = 0, j = len - 1; i < len; i++, j--) 
			{
				outstr[i] = instr[j]; 
			}
		}
		outstr[len] = '\0'; 
	}
	return outstr;
}

int main()
{
	// function pointer called math that holds arrdress of a function taking in two int arg and returns a long
	long(*math)(int a, int b); 

	// Function pointer to an array of 3 function pointers of long return and 2 int args
	long (*math_array[3])(int a, int b); 

	enum ops {add,sub,mult};

	// function pointer to fp hold address of a functino of double char pointer returning void
	void (*fp)(char** str); 

	char* (*fp2)(char* str); 

	char* str1; 

	int var1, var2, i, j;
	long answer; 

	fp = upcase;
	fp2 = reverse_em; 

	std::cout << "Address of upcase function is " << fp << std::endl;
	std::cout << "Address if reverse_em function is " << fp2 << std::endl; 

	str1 = (*fp2)((char*)"junk"); 

	std::cout << "After deferencing fp2, str1 is " << str1 << std::endl; 

	(*fp)(&str1); 

	std::cout << "After deferencing fp1, str1 is " << str1 << std::endl;
	std::cout << std::endl; 

	math_array[add] = add_em;
	math_array[sub] = sub_em; 
	math_array[mult] = mult_em; 

	std::cout << "Function pointer Array: " << std::endl; 

	var1 = 1; var2 = 2; 
	std::cout << "varl is " << var1 << " var2 is " << var2 << std::endl; 

	for (i = 0; i < 10; i++) 
	{
		for (j = 0; j < 3; j++) 
		{
			answer = (*math_array[j])(var1, var2); 
			var1 = answer; 
		}
		std::cout << "Answer is " << answer << std::endl; 
	}
	return 0;
}