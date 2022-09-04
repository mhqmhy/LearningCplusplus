#include "MyString.h"
#include <cstring>
ostream& operator<< (ostream& cout, MyString & str)
{
    cout << str.pString;
    return cout;
}

istream& operator>> (istream& cin, MyString & str)
{
    if (str.pString != NULL) 
    {
        delete [] str.pString;
        str.pString = NULL;
    }
    char buf[1024];
    cin >> buf;
    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString, buf);
    str.m_Size = strlen(buf);
    return cin;
}

MyString::MyString(const char * str)
{
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}

MyString::MyString(const MyString & str)
{
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;
}

MyString::~MyString()
{
    if (this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }
}

char & MyString::operator[](int index)
{
    return this->pString[index];
}

MyString& MyString::operator=(const char * str)
{
    if (this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}


MyString& MyString::operator=(const MyString & str)
{
    if (this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;
}

MyString MyString::operator+(const char * str)
{
    int newSize = this->m_Size + strlen(str) + 1;
    char * tmp = new char[newSize];

    memset(tmp, 0, newSize);

    strcat(tmp, this->pString);
    strcat(tmp, str);

    MyString newStr(tmp);
    delete[] tmp;
    return newStr;
}

MyString MyString::operator+(const MyString & str)
{
    int newSize = this->m_Size + strlen(str.pString) + 1;
    char * tmp = new char[newSize];

    memset(tmp, 0, newSize);

    strcat(tmp, this->pString);
    strcat(tmp, str.pString);

    MyString newStr(tmp);
    delete[] tmp;
    return newStr;
}


bool MyString::operator==(const char * str)
{
    if (strcmp (this->pString, str) == 0 && this->m_Size == strlen(str))
    {
        return true;
    }
    return false;
}


bool MyString::operator==(const MyString & str)
{
    if (strcmp (this->pString, str.pString) == 0 && this->m_Size == strlen(str.pString))
    {
        return true;
    }
    return false;
}