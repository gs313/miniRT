/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:59:01 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 18:13:25 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat was born" << std::endl;
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat was cloned" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat was assigned" << std::endl;
	Animal::operator=(copy);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow ~" << std::endl;
}


