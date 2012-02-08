#include "Entity.h"

/*
 * Entity
 */

Entity::Entity()
{
    // Randomly generate creature type
    //hp = maxhp = ;
    //m = maxm = ;
}

Entity::~Entity()
{
    // Drop loot
    // Player gains xp
}

// Accessors and mutators
std::string Entity::getName()
{
    return name;
}

std::string Entity::setName(std::string value)
{
    name = value;
    return name;
}

std::string Entity::getType()
{
    return type;
}

std::string Entity::setType(std::string value)
{
    type = value;
    return type;
}

int Entity::getMaxHP()
{
    return maxhp;
}

int Entity::setMaxHP(int value)
{
    maxhp = value;
    return maxhp;
}

int Entity::addMaxHP(int value)
{
    maxhp += value;
    return maxhp;
}

int Entity::getHP()
{
    return hp;
}

int Entity::setHP(int value)
{
    hp = value;
    return hp;
}

int Entity::addHP(int value)
{
    if(hp > 0) hp += value;
    if(hp > maxhp) hp = maxhp;
    return hp;
}

int Entity::getMaxMP()
{
    return maxmp;
}

int Entity::setMaxMP(int value)
{
    maxmp = value;
    return maxmp;
}

int Entity::addMaxMP(int value)
{
    maxmp += value;
    return maxmp;
}

int Entity::getMP()
{
    return mp;
}

int Entity::setMP(int value)
{
    mp = value;
    return mp;
}

int Entity::addMP(int value)
{
    mp += value;
    return mp;
}

int Entity::getStrength()
{
    return str;
}

int Entity::setStrength(int value)
{
    str = value;
    return str;
}

int Entity::addStrength(int value)
{
    str += value;
    return str;
}

int Entity::getArmor()
{
    return armor;
}

int Entity::setArmor(int value)
{
    armor = value;
    return armor;
}

int Entity::addArmor(int value)
{
    armor += value;
    return armor;
}

int Entity::getLevel()
{
    return lvl;
}
int Entity::setLevel(int value)
{
    lvl = value;
    return lvl;
}

int Entity::addLevel(int value)
{
    lvl += value;
    return lvl;
}

Sprite& Entity::sprite()
{
    return appearance;
}

Sprite Entity::getSprite()
{
    return appearance;
}

void Entity::setSprite(Sprite s)
{
    appearance = s;
    return;
}

std::list<Ability> Entity::getAbilities()
{
    return a;
}

std::list<Ability> Entity::setAbilities(std::list<Ability> value)
{
    a = value;
    return a;
}

int Entity::getX()
{
    return x;
}

int Entity::getY()
{
    return y;
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::move(int x, int y)
{
    this->x += x;
    this->y += y;
}

/*
 * Player
 */


int Player::getGold()
{
    return gp;
}

int Player::setGold(int value)
{
    gp = value;
    return gp;
}

int Player::addGold(int value)
{
    gp += value;
    return gp;
}

int Player::getXP()
{
    return xp;
}

int Player::setXP(int value)
{
    xp = value;
    return xp;
}

int Player::addXP(int value)
{
    xp += value;
    return xp;
}

std::list<Item> Player::getItems()
{
	return i;
}

std::list<Item> Player::setItems(std::list<Item> value)
{
	i = value;
	return i;
}

Player::Player() // Constructor specifically for player
{
    // idk if we need this
}

Player::~Player()
{
	// return heap memory here (NO MEMORY LEAKS PLZ)
}

void Player::death() // Goto here when player dies
{
    // Attributes when respawning
    hp = maxhp/2;
    mp = maxmp;
    gp /= 2;
    return;
}

void Player::level_up()
{
    maxhp *= 1.2; // Assuming 20% increase per level
    hp = maxhp; // Health regeneration
    maxmp *= 1.2;
    mp = maxmp;
    xp -= 100 * lvl * lvl; // assuming experience scales in a quadratic regression
    lvl++;
    // random trait, etc.
    return;
}

/*
 * Creature
 */

Creature::Creature()
{

}

Creature::~Creature()
{

}

std::list<Item> Creature::getDrops()
{
	return d;
}

std::list<Item> Creature::setDrops(std::list<Item> value)
{
	d = value;
	return d;
}

void Creature::death(Player P) // Goto here when creature dies
{
	std::list<Item> temp = P.getItems();
	temp.splice(temp.begin(),d);
	P.setItems(temp);
	P.addXP(lvl * 10);
	// remove the creature
	return;
}	

