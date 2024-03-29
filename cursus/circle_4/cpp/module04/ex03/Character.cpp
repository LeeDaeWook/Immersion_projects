#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    std::cout << "Default Character constructor called" << std::endl;
    this->addressDB = NULL;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const& name)
{
    std::cout << "String Character constructor called" << std::endl;
    this->addressDB = NULL;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    this->name = name;
}

Character::~Character()
{
    std::cout << "Default Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    if (this->addressDB)
        delete this->addressDB;
}

Character::Character(const Character& character)
{
    std::cout << "Character Copy constructor called" << std::endl;
    this->addressDB = NULL;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        this->inventory[i] = character.inventory[i]; 
    }
    if (this->addressDB != NULL)
        delete this->addressDB;
    this->addressDB = character.addressDB;
    this->name = character.name;
    return *this;
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3) {
        checkAddress();
        this->addressDB = this->inventory[idx];
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
        (this->inventory[idx])->use(target);
}

void Character::checkAddress()
{
    if (this->addressDB)
        delete this->addressDB;
}
