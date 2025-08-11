/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:23:55 by luifer            #+#    #+#             */
/*   Updated: 2025/08/11 11:46:38 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential pardon", 25, 5) {
    //std::cout << BLUE << "PresidentialPardonForm default constructor called" << RESET << std::endl;
    this->_target = "Default Target";
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential pardon", 25, 5) {
    //std::cout << BLUE << "PresidentialPardonForm parameterized constructor called" << RESET << std::endl;
    this->_target = target;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("Presidential pardon", 25, 5) {
    //std::cout << BLUE << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
    this->_target = other._target;
}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    //std::cout << BLUE << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    //std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

// Getter for target
const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

// Execute method
void PresidentialPardonForm::execute() const {
    std::cout << GREEN << "PresidentialPardonForm: " << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
