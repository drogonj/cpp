/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:07:20 by ngalzand          #+#    #+#             */
/*   Updated: 2023/03/20 14:07:22 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_PHONEBOOK_H
#define CPP_PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_contact_lst[8];
		int			_last_contact_index;
		int			_oldest_contact;
		void		_get_contact(int index);
		std::string	_adjust_str(std::string str);
		int			_atoi_check(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void);
};

#endif
