#include<iostream>
#include<string>
using namespace std;

/*
多态、抽象类
设计一个英雄攻击程序，包含不同的英雄类，如亚瑟（Arthur）、安琪拉（Angela）等。
1. 英雄具有血量、护甲、姓名等属性
2. 不同英雄被攻击后有不同的表现，根据护甲不同扣除血量不同
3. 全局攻击函数（传入攻击力） -> 成员函数（成员变量：攻击力）
*/
class Hero {
protected:
	double mhp;
	double marmor;
	string mname;
public:
	Hero(double hp,double armor,string name)
		:mhp(hp)
		,marmor(armor)
		,mname(name)
	{ }

	virtual ~Hero(){}

	void show() {
		cout << mname << "|护甲：" << marmor << "|血量：" << mhp << endl;
	}
	virtual void beAttacked(double atk)  = 0;
};

class Tank :public Hero {
	double marmorRate=1.2;
public:
	Tank(double hp,double armor,string name)
		:Hero(hp,armor,name)
	{ }

	virtual ~Tank(){}

	void beAttacked(double atk) {
		double realAtk = atk - marmor * marmorRate;
		if (realAtk <= 0) realAtk = 0;
		mhp -= realAtk;
		if (mhp <= 0)	mhp = 0;
		cout << mname << "实际伤害为：" << realAtk << endl;
	}
};
class Master :public Hero {
	double marmorRate=0.8;
public:
	Master(double hp, double armor, string name)
		:Hero(hp, armor, name)
	{
	}

	virtual ~Master() {}
	void beAttacked(double atk) {
		double realAtk = atk - marmor * marmorRate;
		if (realAtk <= 0) realAtk = 0;
		mhp -= realAtk;
		if (mhp <= 0)	mhp = 0;
		cout <<mname<< "实际伤害为：" << realAtk << endl;
	}
};

void beAttacked(Hero &h,double atk) {
	h.beAttacked(atk);
}
int main() {
	Tank Arthur(5000, 500, "亚瑟");
	Master Angela(2000, 200, "安琪拉");	
	
	Arthur.show();
	Angela.show();

	beAttacked(Arthur, 1000);
	beAttacked(Angela, 1000);

	Arthur.show();
	Angela.show();
	return 0;
}
