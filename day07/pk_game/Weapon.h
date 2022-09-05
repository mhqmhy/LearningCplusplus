#pragma once 
#include<iostream>
#include<string>
using namespace std;

//abstract class
class Weapon
{
public:
    //��ȡ�����˺�
    virtual int getBaseDamage() = 0;
    //��ȡ��Ѫ
    virtual int getSuckBlood() = 0;
    //��ȡ�Ƿ���
    virtual bool getHold() = 0;
    //��ȡ�Ƿ񱩻�
    virtual bool getCrit() = 0;

    string m_WeaponName; //��������
    int m_BaseDamage; // �����˺�
};