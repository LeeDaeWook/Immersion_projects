#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = NULL;
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &cat) {
        this->type = cat.type;
        if (this->brain != NULL)
            delete this->brain;
        this->brain = new Brain(*cat.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow meow!" << std::endl;
}

Brain* Cat::getBrain()
{
    return this->brain;
}

void Cat::setBrain(Brain* brain)
{
    if (this->brain)
        delete this->brain;
    this->brain = brain;
}