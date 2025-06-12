/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:07:43 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:07:44 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void announce(void);

	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
