#include "listbase.h"


dNode::dNode() 
{
	_next = _prev = 0; 
} 

dNode::~dNode() {}

void dNode::link(dNode &other)
{
	_next = &other;
	other._prev = this; 
}

dNode* dNode::next() { return _next; }

dNode* dNode::prev() { return _prev; }

// DList Aggregates dNode



DList::DList() 
{
	_head = _tail = 0; 
	append = 1; 
}

DList::~DList() {}

DList& DList::operator <<(dNode *op) 
{
	if (append) 
	{
		if (_tail)
		{
			_tail->link(*op); 
			_tail = op; 
		}
		else 
		{
			// first node
			_head = op; 
			_tail = op; 
		}
	}
	else 
	{
		/*prepend*/
		std::cout << "prepending" << std::endl; 
	}
	return *this; 
}

// intNode is a dNode



std::ostream& operator << (std::ostream& stream, DList& other) 
{
	dNode* traverse = 0; 
	int cnt = 0; 
	for (traverse = other._head; traverse; traverse = traverse->next() ) 
	{
		traverse->print(stream);
		stream << " "; 
		cnt++; 
		if (cnt && !(cnt % 5))
			stream << std::endl; 
	}
	return stream; 
}

void exhausted() 
{
	std::cout << "Free store is exahusted. " << std::endl; 
}



