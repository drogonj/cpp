/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:04 by ngalzand          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:09 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	core;
	std::string buffer;

	while (1)
	{
		buffer.clear();
		while (buffer.empty())
		{
			std::cout << "Type ADD, SEARCH or EXIT: ";
			std::getline(std::cin, buffer);
		}
		if (strcmp(buffer.c_str(), "EXIT") == 0)
			return (0);
		else if (strcmp(buffer.c_str(), "ADD") == 0)
			core.add_contact();
		else if (strcmp(buffer.c_str(), "SEARCH") == 0)
			core.search_contact();
	}
}
