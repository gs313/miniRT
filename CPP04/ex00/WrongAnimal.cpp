/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:04:27 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 20:24:24 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal was born" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal was born" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal was cloned" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	std::cout << "WrongAnimal was assigned" << std::endl;
	type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal was destroyed" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound ????" << std::endl;
}

