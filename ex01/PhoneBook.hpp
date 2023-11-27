/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:56 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/22 13:47:55 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int		_contacts_n = 0;
	
	public:
		void			addContact(Contact contact);
		const Contact	*getContacts(void);
}

#endif
