/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:45 by aldalmas          #+#    #+#             */
/*   Updated: 2025/03/07 09:02:04 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define RED    "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define CYAN    "\x1b[36m"
# define MAGENTA "\x1b[35m"
# define RESET   "\x1b[0m"

# include <iostream>
# include <cstdlib>
# include <exception>

class Bureaucrat {
	private:
		int					_grade;
		const std::string 	_name;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		// surcharge
		Bureaucrat& operator=(const Bureaucrat& other);

		// set & get
		std::string const& getName(void) const;
		int const& getGrade(void) const;

		// members
		void incrementGrade(void);
		void decrementGrade(void);

		// imbriqued class - exceptions 
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bur);