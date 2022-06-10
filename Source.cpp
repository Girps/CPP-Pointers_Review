#include "little.h"


// Copy constructor demonstration
int main()
{
	little_* lp1 = nullptr, * lp2 = nullptr, * lp3 = nullptr, * lp4 = nullptr, * lp5 = nullptr, * lp6 = nullptr;

	lp1 = new little_;
	lp2 = new little_;
	lp3 = new little_;
	lp4 = new little_;
	lp5 = new little_;

	delete lp2;
	delete lp1;

	lp1 = new little_;
	lp2 = new little_;

	lp1->setnum(10);
	std::cout << "number in object 1 is ";
	lp1->prtnum();
	std::cout << "\n";
	// now exhaust free store
	lp6 = new little_;

	return 0;
}