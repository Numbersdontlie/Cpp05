/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:34:25 by luifer            #+#    #+#             */
/*   Updated: 2025/07/02 23:36:04 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

#define BLUE "\e[1;94m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define RESET "\033[0m"

class ShruberryCreationForm : public AForm {
    private:
        std::string _target;
    
    public:
        ShruberryCreationForm(); // Default constructor
        ShruberryCreationForm(const std::string &target); // Parameterized constructor
        ShruberryCreationForm(const ShruberryCreationForm &other); // Copy constructor
        ShruberryCreationForm& operator=(const ShruberryCreationForm& other);
        ~ShruberryCreationForm(); // Destructor

    //Getters
    const std::string& getTarget() const;

    //Methods
    void execute() const;

    //Exceptions classes
    class ErrorFileException: public std::exception {
        public:
            const char* what() const throw();
    };

};

#endif