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

// CONSTRUCTORS & DESTRUCTOR ----------------------------
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat::~Bureaucrat(void) {}

// OVERLOAD  ----------------------------
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        this->_grade = other._grade;	
    return *this;
}

// SETTERS & GETTERS ----------------------------
std::string const& Bureaucrat::getName(void) const {
    return _name;
}

int const& Bureaucrat::getGrade(void) const {
    return _grade; 
}

// MEMBER FUNCTIONS ----------------------------
void Bureaucrat::incrementGrade(void) {
    if ((this->_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    std::cout << GREEN << _name << "'s grade is now " << _grade << " - Great job "<< _name << " ! The company is proud of you !" << RESET << std::endl;
}

void Bureaucrat::decrementGrade(void) {
    if ((this->_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
    std::cout << RED << _name << "'s grade is now " << _grade << " - Too bad " << _name << "... Too bad." << RESET << std::endl;
}

// IMBRIQUED CLASSES ----------------------------
const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "ERROR - Grade is too hight (1 max, 150 min)";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "ERROR - Grade is too low (1 max, 150 min)";
}


// GLOBAL FUNCTIONS ----------------------------
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur) {
    out << bur.getName() << " bureaucrat grade " << bur.getGrade();
    return out;
}