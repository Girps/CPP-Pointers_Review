
#include "listbase.h"

int main() 
{
	

	dNode* ip = 0; 
	DList mylist;
	

	mylist << new intNode(10) << new intNode(20) << new intNode(30);

	ip = new intNode(40);
	mylist << ip; 
	ip = new intNode(50);
	mylist << ip;
	ip = new intNode(60);
	mylist << ip;
	
	std::cout << "mylist: " << std::endl;
	std::cout << mylist; 
}