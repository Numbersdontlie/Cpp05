/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:10:01 by luifer            #+#    #+#             */
/*   Updated: 2025/07/03 14:06:03 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>

#define BLUE "\e[1;94m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define RESET "\033[0m"

class Intern {
    public:
        Intern(); // Default constructor
        Intern(const Intern &other); // Copy constructor
        Intern &operator=(const Intern &other); // Assignment operator
        ~Intern(); // Destructor

        class NonExistingFormException : public std::exception {
            public:
                const char* what() const throw();
        };

        AForm* makeForm(const std::string &formName, const std::string &target);

};

#endif