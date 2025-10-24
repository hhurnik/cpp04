#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) //it calls copy constructor from Animal
{
    std::cout << "Cat: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        //i don't copy anything else, because Cat doesn't have its own fields
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow." << std::endl;
}