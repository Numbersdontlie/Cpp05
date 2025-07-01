/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:52:20 by luifer            #+#    #+#             */
/*   Updated: 2025/07/02 00:07:20 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define BLUE "\e[1;94m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define RESET "\033[0m"

class Bureaucrat; // Forward declaration to avoid circular dependency

class AForm {
    private:
        // They are private to prevent instantiation without parameters
        AForm(); // Default constructor
        AForm &operator=(const AForm &other); // Assignment operator 
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    
    public:
        AForm(const std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        virtual ~AForm();

        // Getters
        const std::string& getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        // Methods
        void beSigned(const Bureaucrat& bureaucrat);
        void beExecuted(const Bureaucrat& exec) const;
        virtual void execute() const = 0; // Pure virtual function to be implemented by derived classes

        //Exceptions classes
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw(); 
        };
        class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();
        };
        class formNotSignedException: public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif