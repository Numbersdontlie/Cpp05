/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:39:06 by luifer            #+#    #+#             */
/*   Updated: 2025/07/01 23:23:23 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Default constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default_target") {
    std::cout << BLUE << "RobotomyRequestForm default constructor called 🤖 🤖 🤖" << RESET << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target("default_target") {
    std::cout << BLUE << "RobotomyRequestForm parameterized constructor called 🤖 🤖 🤖" << RESET << std::endl;
    this->_target = target;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", 72, 45), {
    std::cout << BLUE << "RobotomyRequestForm copy constructor called 🤖 🤖 🤖" << RESET << std::endl;
    this->_target = other._target;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << BLUE << "RobotomyRequestForm assignment operator called 🤖 🤖 🤖" << RESET << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "RobotomyRequestForm destructor called 🤖 🤖 🤖" << RESET << std::endl;
}


// Getters
const std::string &RobotomyRequestForm::getTarget() const {
    return this->_target;
}

// Member function to execute the form
void RobotomyRequestForm::execute() const {
    srand(time(0)); //to generate random numbers
    std::cout << GREEN << "Robotomy in progress frgrgyatzzzeerrmasnbjdabs 🔧 🔩 🪛 🔨" << RESET << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << GREEN << this->_target << "has been upgraded without problems 🤖" << RESET << std::endl;
    }
    else {
        std::cout << RED << "Robotomy failed for " << this->_target << " 🤖 😿" << RESET << std::endl;
    }
}