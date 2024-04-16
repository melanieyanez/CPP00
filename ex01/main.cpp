/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:21:42 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/16 15:36:56 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	prompt;
	PhoneBook	PhoneBook;

	while (42)
	{
		std::cout << "Enter the command you want to execute (ADD, SEARCH, EXIT):" << std::endl;
		std::cin >> prompt;
		if (std::string(prompt) == "ADD")
			PhoneBook.PhoneBook::AddContact();
		else if (std::string(prompt) == "SEARCH")
			PhoneBook.PhoneBook::SearchContact();
		else if (std::string(prompt) == "EXIT")
			return(0);
		else
			std::cout << "Error! " << prompt << " is not a valid command." << std::endl;
	}
	return(0);
}