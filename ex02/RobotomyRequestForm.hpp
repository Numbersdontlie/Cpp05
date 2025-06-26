/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:34:54 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 22:55:23 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

#define BLUE "\e[1;94m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define RESET "\033[0m"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

    public:
        RobotomyRequestForm(); // Default constructor
        RobotomyRequestForm(std::string target); // Parameterized constructor
        RobotomyRequestForm(const RobotomyRequestForm &other); // Copy constructor
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other); //operator= overload constructor
        ~RobotomyRequestForm();// Destructor
    
    //Getters
    const std::string& getTarget() const;

    //Methods
    void execute() const;

    //Exceptions classes
    class RobotomyFailureException: public std::exception {
        public:
            const char* what() const throw() {
            }
    };
};

#endif