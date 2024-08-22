/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:51:20 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/22 01:27:13 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain created" << std::endl;
}
Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Brain copied" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Brain assigned" << std::endl;
	return (*this);
}
Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("The brain only has 100 slots [0-99]");
	return (this->ideas[index]);
}
