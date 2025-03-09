/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:28:49 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/09 15:19:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
    AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout << GREEN << this->getName() << " has been created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    std::cout << GREEN << this->getName() << " has been created" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << RED << this->getName() << " has been archived" << RESET << std::endl;
}

// OVERLOAD  ----------------------------
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

// SETTERS & GETTERS ----------------------------

// MEMBER FUNCTIONS ----------------------------
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw CantExecuteException();
    if (this->getSigned() == false)
        throw NotSignedFormException();
    std::cout << "Informs that " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// IMBRIQUED CLASSES ----------------------------

// GLOBAL FUNCTIONS ----------------------------
