/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:06:47 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
Form::Form(const std::string& name, const int& signGrade, const int& execGrade) : 
    _name(name), 
    _signGrade(signGrade), 
    _execGrade(execGrade),
    _signed(false)
{
    std::cout << GREEN << "The form '" << _name << "' has been created" << std::endl;
}

Form::Form(const Form& other) :
    _name(other._name), 
    _signGrade(other._signGrade), 
    _execGrade(other._execGrade),
    _signed(other._signed)
{
    std::cout << GREEN << "The form '" << _name << "' has been created" << std::endl;
}

Form::~Form(void) {
    std::cout << RED << "The form '" << _name << "' has been archived" << std::endl;
}

// OVERLOAD  ----------------------------
Form& Form::operator=(const Form& other) {
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

// SETTERS & GETTERS ----------------------------
std::string const& Form::getName(void) const {
    return _name;
}

int const& Form::getSignGrade(void) const {
    return _signGrade; 
}

int const& Form::getExecGrade(void) const {
    return _execGrade; 
}

bool const& Form::getSigned(void) const {
    return _signed; 
}


// MEMBER FUNCTIONS ----------------------------
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

// IMBRIQUED CLASSES ----------------------------
const char* Form::GradeTooHighException::what(void) const throw() {
	return "ERROR - Grade is too hight for sign this form (1 max, 150 min)";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "ERROR - Grade is too low for sign this form (1 max, 150 min)";
}


// GLOBAL FUNCTIONS ----------------------------
std::ostream& operator<<(std::ostream& out, const Form& form) {
    std::string isSigned = "❌";
    
    if (form.getSigned() == true)
        isSigned = "✅";
    out << RESET "Form name                         🢚 " << form.getName();
    out << "\nMinimum grade required to sign    🢚 " << form.getSignGrade();
    out << "\nMinimum grade required to execute 🢚 " << form.getExecGrade();
    out << "\nAlready signed ?                  🢚 " << isSigned;
    return out;
}