#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog: default constructor called" << std::endl;
}


Dog::Dog(const Dog &other): Animal(other) //it calls copy constructor from Animal
{
    std::cout << "Dog: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); //we call upon the operator from base class
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "Hao buah buah hah hau hau hau hau" << std::endl;
}