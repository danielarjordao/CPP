/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:15 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:08:16 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name(name), weapon(NULL) {
	std::cout << this->name << " is created" << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->name << " is destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their "<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with" << std::endl;
}

void HumanB::getWeapon(void)
{
	if (this->weapon)
		std::cout << this->name << " has a weapon: "
		<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon." << std::endl;
}
