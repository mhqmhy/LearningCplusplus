#include<iostream>
#include "MyString.h"
using namespace std;

void test01()
{
    MyString str = "abc";
    cout << str << endl;

    // cin >> str;
    // cout << str << endl;

    MyString str2(str);
    MyString str3 = "aaaaa";
    str3 = str2;
    str3 = "aaaa";
    cout << "str3 = " << str3 << endl;
    str3[0] = 'w';
    cout << str3[0] << endl;
    MyString str4 = "";
    str4 = str2 + str3;
    cout << "str4 为" << str4 << endl;

    if (str3 == str4)
    {
        cout << "str3与str4相等" << endl;
    }
    else
    {
        cout << "str3与tr4不相等" << endl;
    }
}

int main()
{
    test01();
    return 0;
}