/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:06:47 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
// #include "RobotomyRequestForm.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern(void) {}

// OVERLOAD  ----------------------------
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// SETTERS & GETTERS ----------------------------

// MEMBER FUNCTIONS ----------------------------
AForm* Intern::makeForm(std::string& formName, std::string& target) const {
    int idx = 0;
    const char* forms[] = {"robotomy request", "shrubbery request", "pardon request", NULL};

    for (; forms[idx]; idx++)
    {
        if (forms[idx] == formName)
            break;
    }
    if (forms[idx] == NULL)
        throw Intern::WrongFormNameException();
    
    AForm* form = NULL;
    switch (idx)
    {
        case 0:
            form = new RobotomyRequestForm(target);
            break;
        case 1:
            form = new ShrubberyCreationForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            delete form;
            throw Intern::WrongFormNameException();
    }
    std::cout << YELLOW << "Intern creates " << form->getName() << RESET << std::endl;
    return form;
}

// IMBRIQUED CLASSES ----------------------------
const char* Intern::WrongFormNameException::what(void) const throw() {
	return "\n❌ ERROR - Grade is too hight for sign this form (1 max, 150 min)";
}
// GLOBAL FUNCTIONS ----------------------------
