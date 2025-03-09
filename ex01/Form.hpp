/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:41:28 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/07 16:09:25 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string   _name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
		Form(const std::string& name, const int& signGrade, const int& execGrade);
		Form(const Form& other);
		~Form();

		// overload
		Form& operator=(const Form& other);

		// set & get
		std::string const&	getName() const;
		int	const&			getSignGrade() const;
		int	const&			getExecGrade() const;
		bool const&			getSigned() const;

		// members
		void beSigned(const Bureaucrat& b);

		// imbriqued class - exceptions 
		class GradeTooLowException : std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const Form& form);

#endif