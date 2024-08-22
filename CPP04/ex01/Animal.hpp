/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:58:55 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/21 20:28:42 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;
};

#endif
