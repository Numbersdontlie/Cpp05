/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:41:05 by luifer            #+#    #+#             */
/*   Updated: 2025/08/14 15:06:51 by lperez-h         ###   ########.fr       */
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
    std::cout << BLUE << "Form copy constructor called" << RESET << std::endl;
}


// destructor
AForm::~AForm() {
    std::cout << RED << "Form destructor called" << RESET << std::endl;
}

// getters
const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecuteGrade() const {
    return this->_executeGrade;
}

// methods for the Form class
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() < this->_signGrade)
        this->_isSigned = true;
	else 
		throw GradeTooLowException();
}

void AForm::beExecuted(const Bureaucrat &exec) const {
    if (!this->_isSigned)
        throw FormNotSignedException();
    else if (exec.getGrade() > this->_executeGrade)
        throw GradeTooLowException();
	else 
		this->execute();
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