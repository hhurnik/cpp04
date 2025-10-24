#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n-----The rest of the tests: wrong, no virtual-----" << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrong->getType() << std::endl;
    std::cout << wrongCat->getType() << std::endl;

    wrong->makeSound();     //some wrong animal sound
    wrongCat->makeSound();  //some wrong animal sound here too - lack of polymorphism

    delete wrong;
    delete wrongCat;

	delete i;
	delete j;
	delete meta;
	
	return (0);
}
