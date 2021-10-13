#include"List.h"



OneList::OneList()
{
	value = nullptr;
	next = nullptr;
	begin = nullptr;
}

OneList::OneList(const someStruct& s)
{
	value = new someStruct(s);
	next = nullptr;
	begin = this;
}

OneList::OneList(const int length, const someStruct&  s)
{
	value = new someStruct(s);
	next = nullptr;
	begin = this;

	OneList* curElem = this;
	OneList* nextElem = nullptr;

	for (int i=1;i<length; ++i)
	{
		nextElem = new OneList(s);
		curElem->next = nextElem;
		curElem = nextElem;
		curElem->begin = this;
	}
}

OneList::~OneList()
{
	if (next != nullptr)
		delete next;
	delete value;
}



void OneList::append(const someStruct& object)
{
	if (begin == nullptr)
	{
		value = new someStruct(object);
		begin = this;
		return;
	}

	OneList* curElem = this;
	for (; curElem->next != nullptr; curElem = curElem->next);

	curElem->next = new OneList(object);
	curElem = curElem->next;
	curElem->begin = begin;
}

void OneList::print()
{
	if (begin == nullptr)
		cout << "Empty list" << endl << endl;
	else
	{
		cout << "List of:" << endl;
		for (OneList* curList = begin; curList != nullptr; curList = curList->next)
		{
			cout << "Item = " << curList << "  Value";
			cout << *(curList->value);
			cout << "  Next = " << curList->next << endl;

		}
		cout << "end list" << endl << endl;
	}
}

ostream& operator<<(ostream& out, const OneList& R)
{
	if (R.begin == nullptr)
		cout << "Empty list" << endl;
	else
	{
		out << "Item = " << &R << "  Value";
		out << *R.value;
		out << "  Next = " << R.next << endl;
	}
	

	//  out << "List of:" << endl;
	//  for (OneList* curList = R.begin; curList != nullptr; curList = curList->next)
	//  {
	//  	out << "Item = " << curList << "  Value" ;
	//  	out << *(curList->value);
	//  	out<< "  Next = " << curList->next << endl;
	//  	
	//  }
	//  out << "end list" << endl << endl;;
	return out;
}

OneList& OneList::operator [](int i)
{
	OneList* curElem(this);
	for (int j = 0; j < i && curElem != nullptr; ++j)
		curElem = curElem->next;

	if (curElem == nullptr)
	{
		cout << ("Operator []: Index out of range in oneList") << endl;
		curElem = new OneList();
	}
	return *curElem;
}

OneList& OneList::operator =(const OneList& R)
{
	value = new someStruct(*R.value);
	begin = this;
	next = nullptr;
	return *this;
}