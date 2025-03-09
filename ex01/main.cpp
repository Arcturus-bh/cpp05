/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:39 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/08 15:16:43 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	{
		std::cout << "TRY 1" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 15);
			Form form("ShrubberyCreationForm", 145, 137);
			Form form("RobotomyRequestForm", 72, 45);
			Form form("PresidentialPardonForm", 25, 5);
			std::cout << form << std::endl << std::endl;
			bob.signForm(form);
			std::cout << form << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
}