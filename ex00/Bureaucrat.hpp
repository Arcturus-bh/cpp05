#pragma once

# define RED    "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define CYAN    "\x1b[36m"
# define MAGENTA "\x1b[35m"
# define RESET   "\x1b[0m"

# include <iostream>
# include <cstdlib>

class Bureaucrat {
	private:
		const std::string 	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		// surcharge
		Bureaucrat& operator=(const Bureaucrat& other);

		// set & get
		std::string const& getName(void) const;			
		int const& getGrade(void) const;
};