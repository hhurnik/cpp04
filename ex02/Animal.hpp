#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{

    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        std::string getType() const;
        
};


// If you have base classes from which objects used through pointers are derived,
// the base class destructor should be virtual; otherwise, delete j; on an Animal* pointing to a Dog object will not call Dog::~Dog()


#endif