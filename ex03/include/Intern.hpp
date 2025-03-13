/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:29:33 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/10 15:08:28 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);

        // overload
        Intern& operator=(const Intern& other);
        
        // members
        AForm* makeForm(std::string& formName, std::string& target) const;

        // imbriqued class - exceptions 
		class WrongFormNameException : std::exception {
			public:
				virtual const char* what() const throw();
		};
};