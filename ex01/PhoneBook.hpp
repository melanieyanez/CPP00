/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:15:11 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/16 15:43:26 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	AddContact(void);
		void	SearchContact(void);
	private:
		Contact			_Contacts[8];
		static int		_ContactCount;
		static int		_ContactTotal;
		void 			_CheckData(std::string text, std::string field);
		void			_DisplayList(void);
		void			_DisplayContact(int index);
};

#endif