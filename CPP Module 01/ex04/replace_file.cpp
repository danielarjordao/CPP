/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:49 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:08:50 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace_file.hpp"

void replace_file(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return;
	}
	std::string outfile_name = "replace_" + filename;
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		infile.close();
		std::cerr << "Error: could not open output file" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(infile, line))
			outfile << replace_line(line, s1, s2) << std::endl;
	infile.close();
	outfile.close();
}

std::string replace_line(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string new_line;
	size_t i = 0;
	size_t pos = line.find(s1, i);
	if (pos == std::string::npos)
		return (line);
	while ((pos != std::string::npos))
	{
		new_line += line.substr(i, pos - i);
		new_line += s2;
		i = pos + s1.length();
		pos = line.find(s1, i);
	}
	new_line += line.substr(i);
	return (new_line);
}

