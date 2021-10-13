#include<iostream>

using namespace std;
struct someStruct
{
	int value;
	string name;

	someStruct(int val = 0, string new_name = "name")
	{
		name = new_name;
		value = val;
	}
	someStruct(const someStruct& R)
	{
		name = R.name;
		value = R.value;
	}

	

	friend ostream& operator <<(ostream& out, const someStruct& R)
	{
		out << "StructName(" << R.value << ", \'" << R.name << "\')";
		return out;
	}

	someStruct& operator =(const someStruct& R)
	{
		name = R.name;
		value = R.value;
		return *this;
	}

};

class OneList
{
	OneList* begin;
	OneList* next;
	someStruct* value;
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

	~OneList();

	void append(const someStruct& object);
	void print();

	friend ostream& operator <<(ostream& out, const OneList& R);
	OneList& operator [](int i);
	OneList& operator =(const OneList& R);

};

