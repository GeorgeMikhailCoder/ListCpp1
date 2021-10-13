// Task6.cpp : Defines the entry point for the application.
//

#include "Task6.h"

using namespace std;


int main()
{
	OneList someList;
	
	someList.print();
	someList.append(someStruct(1, "asd"));
	someList.append(someStruct(2, "qwe"));
	someList.append(someStruct(3, "dcv"));
	someList.print();
	cout << someList[1] << endl;

	OneList a = someList[1];
	OneList b;
	b = someList[1];


	cout << a << endl;
	system("pause");
	return 0;
}
