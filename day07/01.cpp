#include<iostream>
using namespace std;

class Animal
{
public:
     void speak()
    {
        cout<< "Animal speaking"<< endl;
    }
    // void eat()
    // {
    //     cout <<"Animal eating"<< endl;
    // }  
};

class Cat : public Animal
{
public:
    virtual void speak()
    {
        cout << "cat speaking" << endl;
    }
    void eat()
    {
        cout << "cat eating" << endl;
    }
};


void doSpeak(Animal & animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}

void test02()
{
    cout << sizeof(Animal) << endl;
    Animal * animal = new Cat;
    ((void(*)()) (*(int *)*(int *)animal)) ();
}

int main()
{
    test02();
    return 0;
}