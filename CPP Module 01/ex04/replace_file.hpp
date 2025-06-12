/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:52 by dramos-j          #+#    #+#             */
/*   Updated: 2025/05/01 15:08:53 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <iostream>
#include <fstream>
#include <string>

void replace_file(const std::string &filename, const std::string &s1, const std::string &s2);
std::string replace_line(const std::string &line, const std::string &s1, const std::string &s2);

#endif
