/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:39 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/13 15:30:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	AForm* form = NULL;
	try
	{
		// std::string request = "robotomy request";
		// std::string request = "shrubbery request";
		std::string request = "pardon request";

		std::string target = "Bob";
		Bureaucrat bob("Bob", 1);
		Intern intern;

		AForm* form = intern.makeForm(request, target);

		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(const AForm::CantExecuteException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(const AForm::NotSignedFormException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(Intern::WrongFormNameException& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	catch(std::exception& e)
	{
		delete form;
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}