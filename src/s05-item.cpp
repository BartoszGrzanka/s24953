#include <iostream>
class Creature
{
	public:
	std::string name;
	int hp;
	Creature(std::string name, int hp) : name(name), hp(hp){}
	
	void get_hp(){
        std::cout<<name<<": "<<hp<<"HP \n";
	}
};

class Item
{
	public:
	virtual void use_on(Creature& x) = 0;
	virtual int strength() const = 0;
};


class Weapon : public Item
{
	public:
	void use_on(Creature& x){
	x.hp = x.hp - strength();
	}
	int strength() const{
	return 10;
	}
    
};
class Sword : public Weapon
{
	void use_on(Creature& x){
	x.hp = x.hp - strength();
	std::cout<<"Used sword \n";
	}
	int strength() const{
	return 30;
	}
};
class Axe : public Weapon
{
	void use_on(Creature& x){
		x.hp = x.hp - strength();
	std::cout<<"Used axe \n";
	 }
	int strength() const{
	return 40;
	}
};
class Bow : public Weapon
{
	void use_on(Creature& x){
	x.hp = x.hp - strength();
	std::cout<<"Used bow \n";
	}
	int strength() const{
	return 10;
	}
};

class Potion : public Item
{
	public:
	void use_on(Creature& x){
        x.hp = x.hp + strength();
	}
	int strength() const{
	return 10;
	}
};
class Hp_Potion : public Potion
{
	public:
	int used = 0;
	void use_on(Creature& x){
		if(used < 2){
			std::cout<<"Used hp potion \n";
			x.hp = x.hp + strength();
			this->used += 1;
		}
		else{
			std::cout << "Can't do that \n";
		}
   	}
	int strength() const{
	return 15;
	}
};
int main(){
    
	Creature goblin("aaa", 100);
	Item* bron = new Weapon();
	Item* potion = new Potion();
	Item* sword = new Sword();
	Item* axe = new Axe();
	Item* bow = new Bow();
	Item* hp_potion = new Hp_Potion();

	sword->use_on(goblin);
	goblin.get_hp();
	axe->use_on(goblin);
	goblin.get_hp();
	hp_potion->use_on(goblin);
	goblin.get_hp();
	bow->use_on(goblin);
	goblin.get_hp();
	hp_potion->use_on(goblin);
	goblin.get_hp();
	hp_potion->use_on(goblin);
	return 0;
}
