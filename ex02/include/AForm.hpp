/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:41:28 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/08 15:23:16 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string   _name;
		const std::string   _target;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
		AForm(const std::string& name, const std::string& target, const int& signGrade, const int& execGrade);
		AForm(const AForm& other);
		virtual ~AForm();

		// overload
		AForm& operator=(const AForm& other);

		// set & get
		std::string const&	getName() const;
		std::string const&	getTarget() const;
		int	const&			getSignGrade() const;
		int	const&			getExecGrade() const;
		bool const&			getSigned() const;

		// members
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const& executor) const = 0;

		// imbriqued class - exceptions 
		class GradeTooLowException : std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedFormException : std::exception {
			public:
				virtual const char* what() const throw();
		};
		class CantExecuteException : std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const AForm& AForm);

#endif