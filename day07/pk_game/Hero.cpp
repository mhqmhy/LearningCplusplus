#include "Hero.h"

Hero :: Hero()
{
    this->m_Hp = 500;
    this->m_Atk = 50;
    this->m_Def = 50;
    this->m_Name = "法师";
    this->weapon = NULL;
}

void Hero::EquipWeapon(Weapon * weapon)
{
    this->weapon = weapon;
    cout << "英雄: "<< this->m_Name << "装备了武器: " << this->weapon->m_WeaponName << endl;
}

void Hero::Attack(Monster * monster)
{  
    int damage = 0;
    int addHp = 0;
    bool isSusk = false;
    bool isHold = false;
    bool isCrit = false;
    //如果武器为空 没有加成
    if (this->weapon == NULL)
    {
        damage = this->m_Atk;
    }
    //如果有武器
    else
    {
        //基础伤害
        damage = this->m_Atk + this->weapon->getBaseDamage(); 
        //计算吸血
        addHp = this->weapon->getSuckBlood();
        //计算定身
        isHold = this->weapon->getHold();
        //计算暴击
        isCrit = this->weapon->getCrit();
        if (isHold)
        {
            cout << "英雄的武器出发了定时效果，怪物停止攻击一回合" << endl;
        }
        if (isCrit)
        {
            damage = damage * 2;
            cout << "英雄的武器触发了暴击效果，怪物受到双倍伤害，伤害值为：" << damage << endl;
        }

        monster->m_Hold = isHold;
        int trueDamage = (damage - monster->m_Def) > 0 ? damage - monster->m_Def : 0;
        monster->m_Hp -= trueDamage;
        this->m_Hp += addHp;
        cout << "英雄" << this->m_Name << "攻击了敌人" << monster->m_Name <<", 造成了伤害:"<< trueDamage << endl;
    }

}