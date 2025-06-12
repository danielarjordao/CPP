/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:42 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:08:43 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace_file.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace_file <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error: empty arguments" << std::endl;
		return (1);
	}
	if (s1 == s2)
	{
		std::cout << "Error: s1 and s2 are the same" << std::endl;
		return (1);
	}
	replace_file(filename, s1, s2);
	return (0);
}
