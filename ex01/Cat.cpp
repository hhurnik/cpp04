#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat"; //cannot be in initialisation list - it belongs to Animal, not Cat, and is protected
    std::cout << "Cat: default constructor called" << std::endl;
}

//it calls copy constructor from Animal
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat: copy constructor called" << std::endl;
    brain = new Brain(*other.brain); //deep copy
}


Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); //deep copy
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow." << std::endl;
}

Brain* Cat::getBrain() const
{
    return (brain);
}