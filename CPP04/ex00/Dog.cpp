/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:59:06 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 19:53:49 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog was born" << std::endl;
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog was cloned" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog was assigned" << std::endl;
	Animal::operator=(copy);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof ~" << std::endl;
}

