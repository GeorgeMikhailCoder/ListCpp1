#pragma once
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

	bool operator ==(const someStruct& R)
	{
		return name == R.name && value == R.value;
	}
	bool operator !=(const someStruct& R)
	{
		return name != R.name || value != R.value;
	}

};
