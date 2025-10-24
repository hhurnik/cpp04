#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog"; //cannot be in initialisation list - it belongs to Animal, not Dog, and is protected
    std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog: copy constructor called" << std::endl;
    brain = new Brain(*other.brain); //deep copy - create a real copy, not just pointer copy which would be a shallow copy
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); //deep copy
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Hao buah buah hah hau hau hau hau" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (brain);
}