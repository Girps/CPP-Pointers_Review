// virtual.cpp 
#include<iostream>

class Base 
{
	protected: 
		int A;
	public:
		Base() { A = 0; }
		~Base() {}
		virtual void get() { std::cin >> A; }
		virtual void prrt() { std::cout << A;  }
};


class Deriv : public Base 
{
	protected : 
		int B;
	public:
		Deriv() { B = 0; }
		~Deriv() {}
		void get()
		{ 
			std::cout << "Enter A: ";
			std::cin >> A; 
			std::cout << "Enter B: ";
			std::cin >> B; 
		}
		void prt() 
		{
			std::cout << "\nA : " << A << std::endl; 
			std::cout << "B: " << B << std::endl; 
		}
};


int main() 
{
	Base* bp = 0; 
	Deriv dObj, * dp = 0; 

	bp = &dObj; 
	dp = &dObj; 
	bp->get(); 
	dp->prt();

	return 0; 


}