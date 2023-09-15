/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:23 by ngalzand          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:26 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->index = "";
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string	Contact::search_val(std::string val)
{
	if (strcmp(val.c_str(), "index") == 0)
		return (this->index);
	else if (strcmp(val.c_str(), "firstname") == 0)
		return (this->firstname);
	else if (strcmp(val.c_str(), "lastname") == 0)
		return (this->lastname);
	else if (strcmp(val.c_str(), "nickname") == 0)
		return (this->nickname);
	else if (strcmp(val.c_str(), "phone_number") == 0)
		return (this->phone_number);
	else if (strcmp(val.c_str(), "darkest_secret") == 0)
		return (this->darkest_secret);
	return (0);
}

void	Contact::get_values(int index)
{
	this->index = std::to_string(index);

	// Firstname //
	while (this->firstname.empty())
	{
		std::cout << "First name: ";
		std::getline(std::cin, this->firstname);
	}


	// Lastname //
	while (this->lastname.empty())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, this->lastname);
	}


	// Nickname //
	while (this->nickname.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, this->nickname);
	}


	// Phone number //
	while (this->phone_number.empty())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, this->phone_number);
	}


	// Darkest secret //
	while (this->darkest_secret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->darkest_secret);
	}

	std::cout << "Registration completed." << std::endl;
}
