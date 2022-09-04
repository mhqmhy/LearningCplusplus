#include"Hero.h"

Hero :: Hero()
{
    this->m_Hp = 500;
    this->m_Atk = 50;
    this->m_Def = 50;
    this->m_Name = "liu fa shi";
    this->weapon = NULL;


}

void Hero::EquipWeapon(Weapon * weapon)
{
    this->weapon = weapon;
    cout << "hero:"<< this->m_Name << "equiped" << this->weapon->m_WeaponName;
}

void Hero::Attack(Monster * monster)
{  

}