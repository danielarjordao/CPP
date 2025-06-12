/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:07:48 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:07:49 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Invalid number of zombies: " << N << std::endl;
		return NULL;
	}
	Zombie *horde = new Zombie[N];
	if (!horde)
	{
		std::cerr << "Failed to allocate memory for horde" << std::endl;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}


