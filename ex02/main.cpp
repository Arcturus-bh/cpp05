/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:39 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/09 19:28:29 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	{
		try
		{
			Bureaucrat bob("Bob", 45);
			//ShrubberyCreationForm form("garden"); // sign 145, exec 137
			RobotomyRequestForm form("Pedro le loco");    // sign 72, exec 45
			//PresidentialPardonForm form("Bob"); // sign 25, exec 5
			
			std::cout << std::endl;
			//bob.signForm(form);
			std::cout << "    ╰┈➤Try to execute it:" << std::endl;
			bob.executeForm(form);
			std::cout << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const AForm::CantExecuteException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const AForm::NotSignedFormException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
}