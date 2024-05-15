/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:56 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/15 15:59:31 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact _contacts[MAX_CONTACTS];
		int		_contacts_n;
		int		_contacts_i;
	
	public:
		PhoneBook();

		void			addContact(const Contact &contact);

		const Contact*	getContact(const int index);

		const Contact*	getContacts(void);

		int				getContactNum(void);
};

#endif
