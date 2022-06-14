#pragma once
#include <iostream>
#include <new>


// abstract class
class dNode
{
	dNode* _next;
	dNode* _prev;
public:
	dNode();
	~dNode();
	void link(dNode& other);
	dNode* next();
	dNode* prev();
	virtual void print(std::ostream& stream) = 0; // pure virtual function abstract class

};

class DList
{
	dNode* _head;
	dNode* _tail;
	short append;
public:
	DList();
	~DList();
	// insert into list using operator overloading 
	DList& operator <<(dNode* op);
	dNode* head() { return _head; }
	dNode* tail() { return _tail; }
	friend std::ostream& operator <<(std::ostream& stream, DList& other);
};


class intNode : public dNode
{
	int _data;
public:
	intNode() {}
	~intNode() {}
	intNode(int indata) { _data = indata; }
	void print(std::ostream& stream) { stream << _data; } // overloaded virtual function of abstract dNode
};