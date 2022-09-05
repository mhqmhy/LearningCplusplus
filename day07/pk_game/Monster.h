#pragma once 
#include <iostream>
#include <string>
#include "Hero.h"
#include "Weapon.h"

using namespace std;


class Hero;

class Monster
{
public:
    Monster();

    string m_Name; //怪物名称
    int m_Atk; //攻击值
    int m_Def; //防御值
    int m_Hp; //血量
    bool m_Hold; //是否定身

    void Attack(Hero * hero);
};