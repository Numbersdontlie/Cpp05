/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:30:16 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 00:38:26 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() {}

// constructor with parameters
Bureaucrat::Bureaucrat(int grade, const std::string& name): _name(name), _grade(grade) {
    std::cout << "Bureaucrat constructor called." << std::endl;
    if (grade < _minGrade)
        throw GradeTooHighException();
    else if (grade > _maxGrade)
        throw GradeTooLowException();
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called." << std::endl;
}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called." << std::endl;
    if (this != &other) {
        this->_grade = other._grade; // to update the grade not the name which is const
    }
    return *this;
}

// destructor
Bureucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called... BOOM!" << std::endl;
}

//Getters
const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getName() const {
    return this->_grade;
}
