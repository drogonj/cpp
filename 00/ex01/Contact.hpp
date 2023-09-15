/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:07:09 by ngalzand          #+#    #+#             */
/*   Updated: 2023/03/20 14:07:11 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_CONTACT_H
#define CPP_CONTACT_H

# include <iostream>
# include <string>

class Contact {

	private:
		std::string index;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		void		get_values(int index);
		std::string	search_val(std::string val);
};

#endif
