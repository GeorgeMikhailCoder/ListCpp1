// Task6.cpp : Defines the entry point for the application.
//

#include "Task6.h"

using namespace std;


int main()
{
	OneList one;

	one.append(someStruct(1, "qwe"));
	one.append(someStruct(2, "asd"));
	one.append(someStruct(3, "uio"));
	one.append(someStruct(5, "vbn"));
	
	one.popValue(2);
	one.print();
	

	system("pause");
	return 0;
}
