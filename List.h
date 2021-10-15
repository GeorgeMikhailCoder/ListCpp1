#include<iostream>
#include"someStruct.h"
using namespace std;

template<class T>
concept able = requires ()
{
	std::_Integer_like<T> || 
		typeid(T).name() == "string" ||
		typeid(T).name() == "someStruct";
};

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
			delete c;
		}
		else
		{
			for (OneList* curList = begin; curList != nullptr; curList = curList->next)
			{
				if (curList->next == nullptr)
				{
					cout << "Index out of range";
					break;
				}
				if (*curList->next == object)
				{

					OneList* c = &removeItem(curList, curList->next, curList->next->next);
					delete c;
					break;
				}
			}

		}
	}
	//  void popValue(const int& object);
	//  void popValue(const string& object);
	//  void popValue(const someStruct& object);
	
	OneList find(const int& object);
	OneList find(const string& object);
	OneList find(const someStruct& object);
	
	int length();

	void print();

	bool isItemEq(const OneList& Right);

	friend ostream& operator <<(ostream& out, const OneList& R);
	OneList& operator [](int i);
	OneList& operator =(const OneList& R);
	bool operator == (const OneList& R);
	bool operator == (const someStruct& R);
	bool operator == (const string& R);
	bool operator == (const int& R);
};

