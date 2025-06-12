/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:07:03 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:07:04 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

#include "Zombie.hpp"



int main() {
	std::cout << "Stack Zombie test (randomChump)" << std::endl;
	randomChump("stackZombie");

	std::cout << "Heap Zombie test (newZombie)" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	return 0;
}

