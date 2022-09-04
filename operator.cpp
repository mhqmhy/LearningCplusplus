#include<iostream>
using namespace std;

class Person 
{
public:
    Person(){}
    Person(int a, int b) 
    {
        this -> m_A = a;
        this -> m_B = b;
    }
    int m_A;
    int m_B;
    // void operator<< ()
    // {
        
    // }
};

void operator<<()
{
    
}

void test01()
{
    Person p1(10, 10);
    cout << p1.m_A << endl;
    // cout << p1 << endl;
}

int main()
{
    test01();
    return 0;
}