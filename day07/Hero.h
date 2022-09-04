#include<iostream>
#include "Weapon.h"
#include<string>
using namespace std;

class Monster;
class Hero
{
public:
    string m_Name;//人名
    int m_Atk;//攻击力
    int m_Def;//防御力
    int m_Hp;//血量

    Weapon * weapon;//武器
    void EquipWeapon(Weapon * weapon);//装备武器
    void Attack(Monster * monster);//攻击武器

};