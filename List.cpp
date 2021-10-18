#include"List.h"

void OneList::insertBetween(OneList* Left, OneList* Right, OneList* Item)
{
	Item->next = Right;
	Left->next = Item;
	Item->begin = Left->begin;
}

void OneList::insertBegin(OneList* Item)
{
	insertBetween(begin, next, Item);
	someStruct c;
	c = *Item->value;
	*Item->value = *begin->value;
	*begin->value = c;
}

OneList& OneList::removeItem(OneList* Left, OneList* deleteItem, OneList* Right)
{
	// удаляет текущий объект из списка
	Left->next = Right;
	
	deleteItem->next = nullptr;
	deleteItem->begin = deleteItem;
	return *deleteItem;
}

OneList& OneList::removeBegin()
{
	// удаляет первый объект из списка
	OneList* deletedList = new OneList(*begin->value);
	OneList* secound = next;
	*begin->value = *next->value;
	begin->next = secound->next;
	secound->next = nullptr;
	delete secound;
	return *deletedList;
}

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

OneList::OneList(const OneList& R)
{
	value = new someStruct(*R.value);
	next = nullptr;
	begin = this;
}

OneList::~OneList()
{
	if (next != nullptr)
		delete next;
	delete value;
}

someStruct OneList::getValue()const
{
	return *value;
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

void OneList::append(const someStruct& object, int index)
{
	if (begin == nullptr)
		append(object);
	else 
		if (index == 0)
		{
			OneList* secound = next;
			OneList* newItem = new OneList(*begin);
			begin->next = newItem;
			newItem->next = secound;
			begin->value = new someStruct(object);
		}
		else
		{
			OneList* curElem;
			curElem = begin;
			int i = 0;
			for (; curElem->next != nullptr && i < index - 1; curElem = curElem->next, ++i);
			insertBetween(curElem, curElem->next, new OneList(object));
		}
}

void OneList::appendSortVal(const someStruct& object)
{
	if (begin == nullptr)
	{
		append(object);
		cout << "Appended  " << object << endl;
	}
	else
	{
		OneList* curElem = begin;
		OneList* prev = begin;
		for (curElem = begin; curElem != nullptr; curElem = curElem->next)
		{
			if (object.value > curElem->value->value)
			{
				prev = curElem;
			}
			else
			{
				if (curElem == begin)
					insertBegin(new OneList(object));
				else
					insertBetween(prev, curElem, new OneList(object));
				cout << "Appended  " << object << endl;
				break;
			}
		}
		if (curElem == nullptr)
			append(object);
		cout << "Object " << object << " appended by value" << endl;
	}
}

void OneList::pop(int index)
{
	
	if (index == 0)
	{
		OneList* c = &removeBegin();
		delete c;
	}
	else
	{
		int i = 0;
		for (OneList* curList = begin; curList != nullptr; curList = curList->next)
		{
			++i;
			if (i == index)
			{
				if (curList->next == nullptr)
				{
					cout << "Index out of range: ";
					cout << "Tried to pop ListItem at " << i << ", but maximum existing index is " << i - 1 << endl;
					break;
				}
				OneList *c = &removeItem(curList, curList->next, curList->next->next);
				delete c;
				break;
			}
		}

	}


}

int OneList::length()
{
	int k = 0;
	for (OneList* curList = begin; curList != 0; curList = curList->next)++k;
	cout << "Length of list is " << k << endl;
	return k;
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

void OneList::fromFile(string fileName)
{
	fstream f(fileName);
	if (!f.is_open())
	{
		cout << "Error opening file: "<<fileName << endl;
		exit(0);
	}
	else
	{
		string str;
		int val;
		regex a(R"([[:digit:]]+)");
		smatch m;
		for (; !f.eof();)
		{
			f >> str;
			if (!regex_search(str, m, a))
			{
				cout << "Error reading item from file" << endl;
				continue;
			}
			val = stoi(m[0]);
			f >> str;
			append(someStruct(val, str));
		}
	}
}

bool OneList::isItemEq(const OneList& Right)
{
	return *value==*Right.value;
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

bool OneList::operator==(const OneList& R)
{
	bool b = true;
	OneList* CurList = begin;
	OneList* RightList = R.begin;
	for (; CurList != nullptr && RightList != nullptr; CurList = CurList->next, RightList = RightList->next)
		if (*CurList->value != *RightList->value)
		{
			b = false;
			break;
		}
	b &= (CurList == nullptr && RightList == nullptr);
	return b;
}

bool OneList::operator==(const someStruct& R)
{
	return *value==R;
}

bool OneList::operator==(const string& R)
{
	return value->name==R;
}

bool OneList::operator==(const int& R)
{
	return value->value==R;
}
