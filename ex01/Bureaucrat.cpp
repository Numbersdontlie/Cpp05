/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:30:16 by luifer            #+#    #+#             */
/*   Updated: 2025/08/12 13:17:13 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// constructor with parameters
Bureaucrat::Bureaucrat(int grade, const std::string& name): _name(name), _grade(grade) {
    //std::cout << BLUE << "Bureaucrat constructor called." << RESET << std::endl;
    if (grade < _minGrade)
        throw GradeTooHighException();
    else if (grade > _maxGrade)
        throw GradeTooLowException();
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
    if (other._grade < _minGrade)
		throw GradeTooHighException();
	else if(other._grade > _maxGrade)
		throw GradeTooLowException();
	//std::cout << GREEN << "Bureaucrat copy constructor called." << RESET << std::endl;
}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    //std::cout << GREEN << "Bureaucrat copy assignment operator called." << RESET << std::endl;
    if (other._grade < _minGrade)
		throw GradeTooHighException();
	else if(other._grade > _maxGrade)
		throw GradeTooLowException();
	if (this != &other) {
        this->_grade = other._grade; // to update the grade not the name which is const
    }
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat() {
    //std::cout << RED << "Bureaucrat destructor called... BOOM!" << RESET << std::endl;
}

//Getters
const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// Methods to increase or decrease
// method to increase the grade
void Bureaucrat::increaseGrade() {
    if (this->_grade <= _minGrade)
        throw GradeTooHighException();
    this->_grade--;
}

// method to decrease the grade
void Bureaucrat::decreaseGrade() {
    if (this->_grade >= _maxGrade)
        throw GradeTooHighException();
    this->_grade++;
}

// method to sign a form from Bureaucrat class
void Bureaucrat::signForm(Form& form) {
    try {
		form.beSigned(*this);
        std::cout << BLUE << _name << " signs " << form.getName() << "." << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << RED << _name << " cannot sign " << form.getName() << " because: " << e.what() << RESET << std::endl;
    }
}

// Exception classes
// This exception is thrown when the grade is too high
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high! It must be between 1 and 150 pal.");
}

// This exception is thrown when the grade is too low
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low! It must be between 1 and 150 pal.");
}

// This operator overload allows us to print the Bureaucrat object directly using std::cout
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
