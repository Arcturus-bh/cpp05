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
    this->_grade = grade;
    std::cout << GREEN << "Hi " << _name << " (grade " << _grade << ") ! Welcome back to the company" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
    std::cout << GREEN << "Hi " << _name << " (grade " << _grade << ") ! Welcome back to the company" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << RED << _name << " has returned to his home" << std::endl;
}

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

void Bureaucrat::signForm(Form& form) const {
    form.beSigned(*this);
    if (form.getSigned() == true)
        std::cout << _name << " signed " << form.getName() << std::endl;
    else
        std::cout << _name << " couldn't sign " << form.getName() << " because he don't have pen..." << std::endl;
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