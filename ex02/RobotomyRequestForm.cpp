/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:28:49 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/09 15:19:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
    AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << GREEN << this->getName() << " has been created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    std::cout << GREEN << this->getName() << " has been created" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << RED << this->getName() << " has been archived" << RESET << std::endl;
}

// OVERLOAD  ----------------------------
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

// SETTERS & GETTERS ----------------------------

// MEMBER FUNCTIONS ----------------------------
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw CantExecuteException();
    if (this->getSigned() == false)
        throw NotSignedFormException();

    std::srand(std::time(NULL));
    const int random = std::rand();
    std::cout << YELLOW << "WARNING: The robotomy can be executed but works 50% of the time..." << RESET << std::endl;
    if (random % 2 == 0)
        std::cout << YELLOW << "✅ "<< this->getTarget() << " has been successfully robotomized !" << std::endl;
    else
        std::cout << YELLOW << "❌ The robotomy of "<< this->getTarget() << " has failed... @!)+$%# !!! Please try again." << std::endl;
}

// IMBRIQUED CLASSES ----------------------------

// GLOBAL FUNCTIONS ----------------------------
