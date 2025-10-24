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
        virtual ~Animal(); //jeśli masz klasy bazowe, z których dziedziczą obiekty używane przez wskaźniki, 
        //destruktor klasy bazowej powinien być virtualny, inaczej delete j; na wskaźniku Animal* do obiektu Dog nie wywoła Dog::~Dog()

        virtual void makeSound() const;
        std::string getType() const;
        
};




#endif