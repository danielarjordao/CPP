/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:19 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:08:20 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack(void);
		void getWeapon(void);

	private:
		std::string name;
		Weapon *weapon;
};


#endif

