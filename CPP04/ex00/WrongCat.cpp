/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:04:33 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 20:25:53 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat was born" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat was cloned" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "WrongCat was assigned" << std::endl;
	WrongAnimal::operator=(copy);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat was destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow ~" << std::endl;
}

