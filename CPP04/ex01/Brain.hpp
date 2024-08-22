/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:51:17 by scharuka          #+#    #+#             */
/*   Updated: 2024/08/22 01:15:31 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};


#endif
