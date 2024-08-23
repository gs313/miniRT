/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:59:09 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/22 02:19:41 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include <cstdlib>
int main()
{
	/*  Subject's Example   */
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	// system("leaks ex01");

	/*  Deep copy check  */
	Dog nobi;
	std::cout << "Nobi's brain address: " << nobi.getBrain() << std::endl;
	Dog copy_nobi(nobi);
	std::cout << "Copy Nobi's brain address: " << copy_nobi.getBrain() << std::endl;

	Cat doraemon;
	std::cout << "Doraemon's brain address: " << doraemon.getBrain() << std::endl;
	Cat copy_doraemon(doraemon);
	std::cout << "Copy Doraemon's brain address: " << copy_doraemon.getBrain() << std::endl;

	/*  Looping create and delete example  */
	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	// system("leaks ex01");

return 0;
}
