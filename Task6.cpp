// Task6.cpp : Defines the entry point for the application.
//

#include "Task6.h"

using namespace std;

#include<array>

int getVal(fstream& f)
{
	string str;
	f >> str;
	regex isDigit(R"([[:digit:]]+)");
	smatch m;
	if (!regex_search(str, m, isDigit))
	{
		cout << "Error reading item from file" << endl;
		throw 1;
	}
	return stoi(str);
}

void applyCommands(string fileName, OneList& one)
{

	fileName = "C:\\Users\\george\\Documents\\Projects (Visual Studio)\\Сириус\\Лаб1\\Task6\\Commands.txt";
	fstream f(fileName);
	
	if (!f.is_open())
	{
		cout << "Error opening file" << endl;
		exit(0);
	}
	else
	{
		f.seekg(ios_base::beg);
		string str;
		int val;

		for (; !f.eof();)
		{
			f >> str;
			if (str == "add")
			{
				val = getVal(f);
				f >> str; // name
				one.appendSortVal(someStruct(val, str));
			}
			else if (str == "remove_value")
			{
				val = getVal(f);
				one.popValue(val);
			}
			else if (str == "remove_name")
			{
				f >> str;
				one.popValue(str);
			}
			else if (str == "search_value")
			{
				val = getVal(f);
				one.find(val);
			}
			else if (str == "search_name")
			{
				f >> str;
				one.find(str);
			}
			else if (str == "count")
			{
				one.length();
			}
			else if (str == "print")
			{
				one.print();
			}
			else
			{
				cout << "Unknown command:  " <<str<< endl;
			}
		
		}
	}
}

string* getParams(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error in console params\n\nUsage:\ntask6.exe path1 path2" << endl;
		exit(0);
	}
	else
	{
		string* res = new string[2];
		res[0] = argv[1];
		res[1] = argv[2];
		return res;
	}

}

int main(int argc, char ** argv)
{
	string* params = getParams(argc, argv);
	OneList one;
	one.fromFile(params[0]);
	applyCommands(params[1], one);

	return 0;
}
