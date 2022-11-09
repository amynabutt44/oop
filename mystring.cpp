#include <iostream>
#include "mystring.h"
using namespace std;
mystring::mystring(const char* p)//parmaterized constructor
{
	lenght = lenghtfunction(p);
	str = new char[lenght];
	strcpyfunction(p);
}

mystring :: operator char* ()

{
	return this->str;
}
mystring::mystring(const mystring& p)//copy constructor
{
	cout << "copy constructor called";
	this->lenght = p.lenght;
	str = new char[lenght + 1];
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		str[i] = p.str[i];
	}
	str[lenght] = '\0';


}


mystring& mystring::operator++()//increment 
{
	for (int i = 0; i < lenght; i++)
	{
		str[i] += 1;
	}

	
	return *this;
}

int mystring::finds(const mystring& a)//finding first index of an array
{

	int count = 0;
	int start = 0;
	int end = 0;
	int index = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		end = 0;

		while (str[start] == a.str[end] && a.str[end] != '\0')
		{
			index = start - end;
			start++;
			end++;
			count++;
		}
		if (count == a.lenght)
		{
			return index;
		}


	}
	return -1;



}
int mystring::find(const mystring& a, int s)//finding first index of an array from user entered number
{
	int count = 0;

	int end = 0;
	int index = 0;
	for (int start = s; str[start] != '\0'; start++)
	{
		end = 0;

		while (str[start] == a.str[end] && a.str[end] != '\0')
		{
			index = start - end;
			start++;
			end++;
			count++;
		}
		if (count == a.lenght)
		{
			return index;
		}


	}
	return -1;




}
int mystring::rfinds(const mystring& a)// finding last occurence of substring 

{
	int count = 0;

	int end = 0;
	int index = -1;
	for (int start = 0; str[start] != '\0'; start++)
	{
		end = 0;

		while (str[start] == a.str[end] && a.str[end] != '\0')
		{
			index = start - end;
			start++;
			end++;
			count++;
		}


	}
	return index;
}


int mystring::rfind(const char h)// last occurence of the char 
{
	int k = -1;
	int i;
	for (i = 0; i < lenght; i++)
	{
		if (str[i] == h)
		{
			k = i;

		}

	}
	if (k == -1)
	{
		return -1;

	}
	else
		return k + 1;
}

int  mystring::find(const char h)//first occurence of the char
{

	int i;
	int k = 0;
	int flag = 0;
	for (i = 0; i < lenght && flag == 0; i++)
	{
		if (str[i] == h)
		{
			flag = 1;
			k = i;
		}
	}
	if (flag == 0)
	{
		return -1;
	}
	else
		return k + 1;
}
mystring ::operator int()//conversion of the string to int
{
	int i = 0;
	int f = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			f = f + 1;
		}

	}


	if (f == 0 || f != lenght)
	{
		return-1;
	}

	int a = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] -= 48;
		a = a * 10 + str[i];
	}
	return a;


}
mystring mystring::subString(int s, int e)// finding substring 
{
	int j = 0;
	mystring a;
	a.lenght = e - s + 1;
	a.str = new char[a.lenght + 3];
	for (int i = s; i <= e; i++)
	{
		a.str[j] = str[i];
		j++;
	}
	a.str[lenght + 1] = '\0';
	
	return a;

}
void  mystring::setvalue(const char* n)//setter function
{
	// if object is made through  default constructor then no memory is allocated so thats why
	if (str == nullptr)
	{
		lenght = lenghtfunction(n);

		str = new char[lenght];
	}
	strcpyfunction(n);
}
bool  mystring::operator<(const mystring& a)
{
	int flag = 0;
	if (lenght < a.lenght)
	{
		for (int i = 0; i < lenght && flag == 0;)
		{
			if (str[i] < a.str[i])
			{
				i++;
			}
			else
				flag = 1;
		}
		if (flag == 0)
		{
			return true;
		}
		else
			return false;


	}
	else
		return false;

}
bool mystring::operator<=(const mystring& a)

{
	int flag = 0;
	if (lenght <= a.lenght)
	{
		for (int i = 0; i < lenght && flag == 0;)
		{
			if (str[i] <= a.str[i])
			{
				i++;
			}
			else
				flag = 1;
		}
		if (flag == 0)
		{
			return true;
		}
		else
			return false;


	}
	else
		return false;

}


mystring mystring ::operator+(const mystring& a) const
{

	int x = 0;
	int i = 0;
	int j = 0;
	mystring ptr;
	ptr.lenght = lenght + a.lenght;
	ptr.str = new char[ptr.lenght + 3];
	while (i < lenght)
	{
		ptr.str[x] = str[i];
		x++;
		i++;
	}


	while (j < a.lenght)
	{
		ptr.str[x] = a.str[j];
		x++;
		j++;
	}
	return ptr;


}
bool  mystring ::operator==(const mystring& a)
{
	int k = 0;

	if (lenght == a.lenght)
	{
		for (int i = 0; i < lenght; i++)
		{
			if (str[i] == a.str[i])
			{
				k++;
			}
		}
	}
	if (k == lenght)
		return true;
	else
		return false;
}
const mystring& mystring:: operator=(const mystring& a)
{
	cout << " assignment operator called" << endl;
	if (this == &a)
	{
		return *this;
	}
	this->lenght = a.lenght;
	if (str != nullptr)
	{
		delete str;
		str = nullptr;
	}
	str = new char[lenght + 1];
	for (int i = 0; i < a.lenght; i++)
	{
		str[i] = a.str[i];
	}

	str[lenght] = '\0';

	return *this;
}
mystring& mystring:: operator+=(const mystring& a)

{
	int i = 0;
	mystring q;
	q.lenght = lenght;
	q.str = new char[q.lenght + 1];
	for (int i = 0; i < q.lenght; i++)
	{
		q.str[i] = str[i];
	}
	delete[]str;
	lenght += a.lenght;
	str = new char[lenght + 3];
	for (i = 0; i < q.lenght; i++)
	{
		str[i] = q.str[i];
	}


	for (int j = 0; j < a.lenght; j++)
	{
		str[i] = a.str[j];
		i++;
	}
	str[lenght] = '\0';
	return *this;


	
}


int mystring::getlenght()
{
	return lenght;
}
void mystring::displaystring()const
{
	cout << "the lenght of the string is " << lenght << endl;
	cout << "the string is " << endl;
	for (int i = 0; i < lenght; i++)
	{
		cout << str[i];

	}
}
void mystring::strcpyfunction(const char* n)
{
	for (int i = 0; i < lenght; i++)
	{
		str[i] = n[i];
	}

}
int mystring::lenghtfunction(const char* p)
{
	int j = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		j++;
	}
	return j + 1;
}
mystring::~mystring()
{
	cout << "destructor called" << endl;
	delete[]str;
	str = nullptr;

}
//ostream& operator<<(ostream& o, mystring& p)
//{
//	o << "the lenght is ";
//	o << p.lenght;
//	o << endl;
//	for (int i = 0; p.str[i] != '\0'; i++)
//	{
//		o << p.str[i];
//	}
//	return o;
//}
void mystring::resize()
{
	char* ko = new char[this->lenght * 2];
	for (int i = 0; i < this->lenght; i++)
	{
		ko[i] = this->str[i];
	}
	this->lenght = this->lenght * 2;
	delete[]this->str;
	this->str = ko;
}
