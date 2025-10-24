#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- BASIC TEST -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;

    std::cout << "\n----- ARRAY TEST -----" << std::endl;
    const int N = 10;
    Animal* animals[N];

    for (int k = 0; k < N; ++k)
    {
        if (k < N / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\nDeleting all animals..." << std::endl;
    for (int k = 0; k < N; ++k)
        delete animals[k];

    std::cout << "\n----- DEEP COPY TEST -----" << std::endl;
    Dog basic;
    {
        Dog tmp = basic; //copy constructor
    } //tmp destroyed here, itshould call its own Brain destructor

    std::cout << "\n----- DEEP COPY CONTENT TEST -----" << std::endl;

    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want a bone");
    dog1.getBrain()->setIdea(1, "I want to play");

    Dog dog2 = dog1; //copy constructor
    dog2.getBrain()->setIdea(0, "I want a walk"); //I change the copy

    std::cout << "dog1 Brain idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 Brain idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog1 Brain idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;
    std::cout << "dog2 Brain idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;


    std::cout << "\n----- END OF TESTS -----" << std::endl;
    return (0);
}
