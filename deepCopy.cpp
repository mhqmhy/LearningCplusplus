#include<iostream>
#include<string.h>
using namespace std;

class Person 
{
public:
    Person(){}
    Person(char * name, int age) 
    {
        m_Name = (char*)malloc(strlen(name)+1);
        strcpy(m_Name, name);
        m_age = age;
    }   
    ~Person() 
    {
        cout<<"deconstructor"<<endl;
        if(m_Name != NULL) 
        {
            free(m_Name);
            m_Name = NULL;
        }
    }
    //拷贝构造(深拷贝)
    Person (const Person &p) 
    {
        m_age = p.m_age;
        m_Name = (char*)malloc(strlen(p.m_Name) + 1);
        strcpy(m_Name, p.m_Name);
    }
    char * m_Name;
    int m_age;
};

void test01() {
    Person p1("abc", 10);
    Person p2(p1);
}
int main() {
    test01();
    return 0;

}