/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/14 11:11:09 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string	_firstName;

		std::string	_lastName;

		std::string	_nickName;

		std::string	_phoneNumb;

		std::string	_secret;

	public:
//		Contact();
//
//		~Contact();
		bool		valName(const std::string &str);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumb(void) const;
		std::string	getSecret(void) const;

		bool	setFirstName(const std::string &firstName);
		bool	setLastName(const std::string &lastName);
		bool	setNickName(const std::string &nickName);
		bool	setPhoneNumb(const std::string &phoneNumb);
		bool	setSecret(const std::string &secret);
};
#endif
