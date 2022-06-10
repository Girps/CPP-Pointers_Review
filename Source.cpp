#include "little.h"


// Copy constructor demonstration
int main()
{
	little* lp1 = nullptr, * lp2 = nullptr, * lp3 = nullptr, * lp4 = nullptr, * lp5 = nullptr, * lp6 = nullptr;

	lp1 = new little;
	lp2 = new little;
	lp3 = new little;
	lp4 = new little;
	lp5 = new little;

	delete lp2;
	delete lp1;	// only 'deletes' this specific object in memory pool find its address 

	lp1 = new little;
	lp2 = new little;

	lp1->setnum(10);
	std::cout << "number in object 1 is ";
	lp1->prtnum();
	std::cout << "\n";
	// now exhaust free store
	lp6 = new little;

	return 0;
}