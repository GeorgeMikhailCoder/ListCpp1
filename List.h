#pragma once

#include<iostream>
#include<fstream>
#include<regex>
#include"someStruct.h"
using namespace std;

class OneList
{
	OneList* begin;
	OneList* next;
	someStruct* value;

	static void insertBetween(OneList* Left, OneList* Right, OneList* Item);
	void insertBegin(OneList* Item);

	static OneList& removeItem(OneList* Left, OneList* deleteItem, OneList* Right);
	OneList& removeBegin();
public:
	
	//  class iterator {
	//  	structName* p;
	//  public:
	//  	iterator(structName* p) : p(p) {}
	//  
	//  	inline iterator& operator ++() {
	//  		
	//  		return *this;
	//  	}
	//  	inline structName* operator -> () {
	//  		return p;
	//  	}
	//  	inline structName& operator* () {
	//  		return *p;
	//  	}
	//  	auto operator ==(iterator const& R) const
	//  	{
	//  		return p == R.p;
	//  	}
	//  	auto operator !=(iterator const& R) const
	//  	{
	//  		return p != R.p;
	//  	}
	//  };
	//  
	//  iterator begin() { return iterator(&value); };
	//  iterator end() { return iterator(&value); };

	OneList();
	OneList(const someStruct& s);
	OneList(const int length, const someStruct& s = {});

	OneList(const OneList& s);

	~OneList();

	someStruct getValue()const;

	void append(const someStruct& object);
	void append(const someStruct& object, int index);
	void appendSortVal(const someStruct& object);
	void pop(int index = 0);
	
	template<typename T>void popValue(const T& object)
	{
		if (*this == object)
		{
			OneList* c = &removeBegin();
			cout << "Deleted  " << *c << endl;
			delete c;
		}
		else
		{
			for (OneList* curList = begin; curList != nullptr; curList = curList->next)
			{
				if (curList->next == nullptr)
				{
					cout << "Index out of range while deliting object \'"<<object<<"\'" << endl;
					break;
				}
				if (*curList->next == object)
				{

					OneList* c = &removeItem(curList, curList->next, curList->next->next);
					cout << "Deleted  " << *c << endl;
					delete c;
					break;
				}
			}

		}
	}

	template<typename T>OneList find(const T& object)
	{
		if (*this == object)
		{
			cout << "For  "<<object<<"  found  " << *this << endl;
			return *new OneList(*this);
		}
		else
		{
			for (OneList* curList = begin; curList != nullptr; curList = curList->next)
			{
				if (*curList == object)
				{
					cout << "For  \'" << object << "\'  found  " << *curList << endl;
					return *new OneList(*curList);
				}
			}
			cout << "Error: Item not found. Empty list returned" << endl;
		}

		return OneList();
	}
	
	int length();
	void print();

	void fromFile(string fileName);


	bool isItemEq(const OneList& Right);

	friend ostream& operator <<(ostream& out, const OneList& R);
	OneList& operator [](int i);
	OneList& operator =(const OneList& R);
	bool operator == (const OneList& R);
	bool operator == (const someStruct& R);
	bool operator == (const string& R);
	bool operator == (const int& R);
	bool operator != (const OneList& R)
	{
		return !(operator ==(R));
	}
};

