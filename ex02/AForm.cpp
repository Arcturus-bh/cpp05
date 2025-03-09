/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:06:47 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:15 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
AForm::AForm(const std::string& name, const std::string& target, const int& signGrade, const int& execGrade) :
    _name(name),
    _target(target),
    _signGrade(signGrade), 
    _execGrade(execGrade),
    _signed(false) {}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _target(other._target),
    _signGrade(other._signGrade), 
    _execGrade(other._execGrade),
    _signed(other._signed) {}

AForm::~AForm(void) {}

// OVERLOAD  ----------------------------
AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

// SETTERS & GETTERS ----------------------------
std::string const& AForm::getName(void) const {
    return _name;
}

std::string const& AForm::getTarget(void) const {
    return _target;
}

int const& AForm::getSignGrade(void) const {
    return _signGrade; 
}

int const& AForm::getExecGrade(void) const {
    return _execGrade; 
}

bool const& AForm::getSigned(void) const {
    return _signed; 
}

// MEMBER FUNCTIONS ----------------------------
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

// IMBRIQUED CLASSES ----------------------------
const char* AForm::GradeTooHighException::what(void) const throw() {
	return "\n❌ ERROR - Grade is too hight for sign this form (1 max, 150 min)";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return "\n❌ ERROR - Grade is too low for sign this form (1 max, 150 min)";
}

const char* AForm::NotSignedFormException::what(void) const throw() {
	return "\n❌ ERROR - You may not execute an unsigned form";
}

const char* AForm::CantExecuteException::what(void) const throw() {
	return "\n❌ ERROR - You do not have the required grade to execute the form";
}

// GLOBAL FUNCTIONS ----------------------------
std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
    std::string isSigned = "❌";
    
    if (AForm.getSigned() == true)
        isSigned = "✅";
    out << RESET "AForm name                         🢚 " << AForm.getName();
    out << "\nMinimum grade required to sign    🢚 " << AForm.getSignGrade();
    out << "\nMinimum grade required to execute 🢚 " << AForm.getExecGrade();
    out << "\nAlready signed ?                  🢚 " << isSigned;
    return out;
}