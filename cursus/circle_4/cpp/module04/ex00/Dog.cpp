#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->type = dog.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "bark bark!" << std::endl;
}