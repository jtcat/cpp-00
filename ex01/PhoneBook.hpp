/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:56 by joaoteix          #+#    #+#             */
/*   Updated: 2023/12/12 11:26:05 by jcat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact _contacts[MAX_CONTACTS];
		int		_contacts_n;
	
	public:
		PhoneBook();

		void	addContact(const Contact &contact);

		Contact	&getContact(const int index);

		const Contact	*getContacts(void);

		int		getContactNum(void);
};

#endif
