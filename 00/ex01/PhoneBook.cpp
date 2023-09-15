/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:34 by ngalzand          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:36 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_last_contact_index = -1;
	_oldest_contact = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

int	PhoneBook::_atoi_check(std::string str)
{
	int n;

	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (-1);
	n = std::stoi(str);
	if (n > _last_contact_index)
		return (-1);
	return (n);
}

std::string PhoneBook::_adjust_str(std::string str)
{
	if (str.size() > 10)
	{
		str[9] = '.';
		for (int i = 10; str[i]; i++)
			str[i] = '\0';
	}
	return (str);
}

void PhoneBook::add_contact()
{
	Contact	buffer;

	if (_last_contact_index == 7)
	{
		std::cout << "ALERT: CONTACTS LIMIT REACHED: THE OLDEST CONTACT WILL BE REPLACED BY THE ENTRY" << std::endl;
		buffer.get_values(_oldest_contact);
		_contact_lst[_oldest_contact] = buffer;
		_oldest_contact = (_oldest_contact + 1) % 8;
	}
	else
	{
		buffer.get_values(_last_contact_index + 1);
		_contact_lst[_last_contact_index + 1] = buffer;
		_last_contact_index++;
	}
}

void PhoneBook::search_contact()
{
	std::string	buffer;
	int			index;

	std::cout << "|   Index  |First Name|Last Name |  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << _adjust_str(_contact_lst[i].search_val("index")) << "|";
		std::cout << std::setw(10) << std::right << _adjust_str(_contact_lst[i].search_val("firstname")) << "|";
		std::cout << std::setw(10) << std::right << _adjust_str(_contact_lst[i].search_val("lastname")) << "|";
		std::cout << std::setw(10) << std::right << _adjust_str(_contact_lst[i].search_val("nickname")) << "|" << std::endl;
	}

	buffer.clear();
	while (buffer.empty())
	{
		std::cout << "Enter the index you want: ";
		std::getline(std::cin, buffer);
	}
	if ((index = _atoi_check(buffer)) == -1)
		std::cout << "Invalid entry, try again." << std::endl;
	else
	{
		std::cout << "First Name     : " << _contact_lst[index].search_val("firstname") << std::endl;
		std::cout << "Last Name      : " << _contact_lst[index].search_val("lastname") << std::endl;
		std::cout << "Nick Name      : " << _contact_lst[index].search_val("nickname") << std::endl;
		std::cout << "Phone number   : " << _contact_lst[index].search_val("phone_number") << std::endl;
		std::cout << "Darkest secret : " << _contact_lst[index].search_val("darkest_secret") << std::endl;
	}
}
