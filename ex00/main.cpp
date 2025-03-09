/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:39 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/07 09:39:01 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	{
		std::cout << "TRY 1" << std::endl;
		try
		{
			Bureaucrat yvette("Yvette", -5);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		std::cout << "\nTRY 2" << std::endl;
		try
		{
			Bureaucrat jaqu("Jaqueline", 155);
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		std::cout << "\nTRY 3 with" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 56);
			std::cout << bob << std::endl << std::endl;
			
			bob.decrementGrade();
			std::cout << "Manager: 🫵  AHAH " << bob.getName() << " you just lost a grade !" << std::endl;
			std::cout << bob.getName() << ": WHAT ? ARE YOU KIDDING ME ?! 🔪"<< std::endl;
			std::cout << "Manager: Ok, it was a joke " << bob.getName() << " calm down please... Drop this knife..." << std::endl;
			bob.incrementGrade();
			std::cout << bob.getName() << ":😊" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		std::cout << "\nTRY 4" << std::endl;
		try
		{
			Bureaucrat seb("Seb", 146);
			std::cout << seb << std::endl << std::endl;
			
			std::cout << "Manager: Hey " << seb.getName() << std::endl;
			std::cout << seb.getName() << ": Yep ?" << std::endl;
			std::cout << "Manager: You fired." << std::endl;
			std::cout << seb.getName() << ": WHAT THE ..?" << std::endl;
			seb.decrementGrade();
			seb.decrementGrade();
			seb.decrementGrade();
			seb.decrementGrade();
			seb.decrementGrade();
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
}