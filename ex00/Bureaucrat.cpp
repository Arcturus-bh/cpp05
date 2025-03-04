/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:06:47 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTOR ----------------------------
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat::~Bureaucrat(void) {}

// SURCHARGE ----------------------------
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_name = other._name;
		this->_grade = other._grade;	
	}
    return *this;
}

// SETTERS ET GETTERS ----------------------------
std::string const& Bureaucrat::getName(void) const {
    return _name;
}

int const& Bureaucrat::getGrade(void) const {
    return _grade;
}

// FONCTIONS MEMBRES ----------------------------

