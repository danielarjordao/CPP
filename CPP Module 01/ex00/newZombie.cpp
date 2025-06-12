/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:07:12 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:07:13 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name)
{
	Zombie* newZombie = new Zombie(name);
	if (!newZombie)
	{
		std::cerr << "Failed to allocate memory for new zombie" << std::endl;
		return 0;
	}
	return newZombie;
}
