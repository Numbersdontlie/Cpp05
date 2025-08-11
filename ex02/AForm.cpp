/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:41:05 by luifer            #+#    #+#             */
/*   Updated: 2025/08/11 12:35:58 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// constructor with parameters
AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(execGrade) {
    //std::cout << BLUE << "Form constructed called" << RESET << std::endl;
    if (signGrade < Bureaucrat::_minGrade || execGrade < Bureaucrat::_minGrade)
        throw GradeTooHighException();
    if (signGrade > Bureaucrat::_maxGrade || execGrade > Bureaucrat::_maxGrade)
        throw GradeTooLowException();
}

// copy constructor
AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    //std::cout << BLUE << "Form copy constructor called" << RESET << std::endl;
}


// destructor
AForm::~AForm() {
    //std::cout << RED << "Form destructor called" << RESET << std::endl;
}

// getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

// methods for the Form class
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form: Not signed";
}

// Overloading the output operator
std::ostream& operator<<(std::ostream &os, const AForm &form) {
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}