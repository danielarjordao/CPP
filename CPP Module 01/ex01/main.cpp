/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:07:31 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:07:32 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "Zombie");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	std::cout << std::endl;
	Zombie *horde1 = zombieHorde(1, "Zombie1");
	if (!horde1)
		return (1);
	horde1[0].announce();
	delete[] horde1;
	std::cout << std::endl;
	Zombie *horde2 = zombieHorde(0, "Zombie");
	if (!horde2)
		return (1);

	return (0);
}
