/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:51:56 by luifer            #+#    #+#             */
/*   Updated: 2025/07/03 00:01:34 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define BLUE "\e[1;94m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define RESET "\033[0m"

// Forward declaration of Form class to avoid circular dependency
class AForm;

class Bureaucrat
{
    private:
    Bureaucrat();// Default constructor private to avoid instantiation without parameters
    const std::string _name;
    int _grade;

    public:
        Bureaucrat(int grade, const std::string &name); // Constructor with parameters
        Bureaucrat(const Bureaucrat& other); // Copy constructor
        Bureaucrat& operator=(const Bureaucrat &other); // Assignment operator constructor
        ~Bureaucrat(); // Destructor
        static const int _minGrade = 1;
        static const int _maxGrade = 150;

        //Getters
        const std::string& getName() const;
        int getGrade() const;

        //Methods to increase or decrease
        void increaseGrade();
        void decreaseGrade();

        //Method to sign a form
        void signForm(AForm &form);

        //Method to execute a form
        void executeForm(const AForm &form) const;

        //Exception classes
        class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif