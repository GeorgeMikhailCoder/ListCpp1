// Tests.cpp : Defines the entry point for the application.
//

#include "Tests.h"

using namespace std;

void test0_operatorEq()
{
	OneList one, two, three, four;
	one.append(someStruct(1, "qwe"));
	one.append(someStruct(2, "asd"));

	two.append(someStruct(1, "qwe"));
	two.append(someStruct(2, "asd"));

	three.append(someStruct(1, "qwe"));
	three.append(someStruct(3, "asd"));

	four.append(someStruct(1, "qwe"));
	four.append(someStruct(3, "asd"));
	four.append(someStruct(3, "asd"));

	cout << (one == two) << (one == three) << (one == four) << endl;
	cout << one.isItemEq(two) << endl;

	assert(one == two);
	assert(one != three);
	assert(one != four);
	assert(one.isItemEq(two));

}


void test1_sortVal()
{
	OneList one, two;

	one.append(someStruct(1, "asd"));
	one.append(someStruct(2, "qwe"));
	one.append(someStruct(3, "dcv"));
	one.append(someStruct(4, "nmp"));
	one.append(someStruct(5, "xzc"));
	

	two.append(someStruct(1, "asd"));
	two.append(someStruct(2, "qwe"));
	two.append(someStruct(3, "dcv"));
	two.append(someStruct(5, "xzc"));
	
	two.appendSortVal(someStruct(4, "nmp"));
	
	assert(one == two);
}

void test2_popVal()
{
	OneList one, two;

	one.append(someStruct(1, "asd"));
	one.append(someStruct(2, "qwe"));
	one.append(someStruct(3, "dcv"));
	one.append(someStruct(4, "nmp"));
	one.append(someStruct(5, "xzc"));


	two.append(someStruct(1, "asd"));
	two.append(someStruct(3, "dcv"));

	one.popValue("nmp");
	one.popValue(2);
	one.popValue(someStruct(5,"xzc"));
	one.popValue(8);

	assert(one == two);
}

void test3_find()
{
	OneList one;

	one.append(someStruct(1, "asd"));
	one.append(someStruct(2, "qwe"));
	one.append(someStruct(3, "dcv"));
	one.append(someStruct(4, "nmp"));
	one.append(someStruct(5, "xzc"));


	assert(one.find(3) == OneList(someStruct(3, "dcv")));
	assert(one.find("nmp") == OneList(someStruct(4, "nmp")));
}

void test4_length()
{
	OneList one;

	one.append(someStruct(1, "asd"));
	one.append(someStruct(2, "qwe"));
	one.append(someStruct(3, "dcv"));
	one.append(someStruct(4, "nmp"));
	one.append(someStruct(5, "xzc"));

	assert(one.length() == 5);
}

int main()
{
	test0_operatorEq();
	test1_sortVal();
	test2_popVal();
	test3_find();
	test4_length();
	return 0;
}
