/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:28:49 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/09 19:17:05 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS & DESTRUCTOR ----------------------------
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
    AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << GREEN << this->getName() << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    std::cout << GREEN << this->getName() << " has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << RED << this->getName() << " has been archived" << std::endl;
}

// OVERLOAD  ----------------------------
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

// SETTERS & GETTERS ----------------------------

// MEMBER FUNCTIONS ----------------------------
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw CantExecuteException();
    if (this->getSigned() == false)
        throw NotSignedFormException();

    std::string outfile_name = this->getTarget() + "_shrubbery";
    std::ofstream outfile;
    outfile.open(outfile_name.c_str(), std::ofstream::out);
    if (!outfile.is_open())
        throw "ERROR - can't open outfile";
    std::string tree = 
    "                # #### ####\n"
    "              ### \\/#|### |/####\n"
    "             ##\\/#/ \\||/##/_/##/_#\n"
    "           ###  \\/###|/ \\/ # ###\n"
    "         ##_\\_#\\_\\## | #/###_/_####\n"
    "        ## #### # \\ #| /  #### ##/##\n"
    "         __#_--###`  |{,###---###-~\n"
    "                   \\ }{\n"
    "                    }}{\n"
    "                    }}{\n"
    "                    {{}}\n"
    "              , -=-~{ .-^- _\n"
    "                    `}\n"
    "                     {\n"
    "          "
    "                  Credits: ejm";
    outfile << tree << std::endl;
    std::cout << YELLOW << "Execution complete ! Check the tree in the "<< MAGENTA << this->getTarget() << "_shrubbery" << YELLOW << " file !" << RESET << std::endl; 
    outfile.close();
}
// IMBRIQUED CLASSES ----------------------------

// GLOBAL FUNCTIONS ----------------------------
