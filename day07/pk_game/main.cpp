#include<iostream>
#include "Monster.h"
#include "Hero.h"
#include "Weapon.h"
#include "Knife.h"
#include "DragonSword.h"

using namespace std;


void play()
{   
    //创建怪物
    Monster * monster = new Monster();
    //创建英雄
    Hero * hero = new Hero();
    //创建武器
    Weapon * knife = new Knife();
    Weapon * dragon = new DragonSword();
    cout << "请选择武器：" << endl;
    cout <<"1.赤手空拳"<<endl;
    cout <<"2.小刀"<<endl;
    cout <<"3.屠龙宝刀"<<endl;
    int operation;
    cin >> operation;
    switch (operation)
    {
    case 1:
        cout << "你真牛X, 你还是太年轻了!" << endl;
		break;
    case 2:
        hero->EquipWeapon(knife);
        break;
    case 3:
        hero->EquipWeapon(dragon);
        break;
    }
    getchar();
    int round = 1;

    while (true)
    {
        getchar();
        system("cls");
        cout << "-----当前第" << round <<"回合-----" << endl;
        if (hero -> m_Hp <= 0)
        {
            cout <<"英雄"<<hero->m_Name<<"已挂，游戏结束"<< endl;
            break;
        }
        hero->Attack(monster);
        if (monster -> m_Hp <= 0)
        {
            cout <<"怪物"<<monster->m_Name<<"已挂，顺利通关"<< endl;
            break;
        }
        monster->Attack(hero);
        cout << "英雄" << hero->m_Name << "剩余血量" << hero->m_Hp << endl;
        cout << "怪物" << monster->m_Name << "剩余血量" << monster->m_Hp << endl;
        round += 1; 
    }

}
int main()
{
    play();
    return 0;
}