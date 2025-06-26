/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:41:05 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 17:47:53 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// constructor with parameters
Form::Form(const std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(execGrade) {
    std::cout << BLUE << "Form constructed called" << RESET << std::endl;
    if (signGrade < Bureaucrat::_minGrade || execGrade < Bureaucrat::_minGrade)
        throw GradeTooHighException();
    if (signGrade > Bureaucrat::_maxGrade || execGrade > Bureaucrat::_maxGrade)
        throw GradeTooLowException();
}

// copy constructor
Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    std::cout << BLUE << "Form copy constructor called" << RESET << std::endl;
}


// destructor
Form::~Form() {
    std::cout << RED << "Form destructor called" << RESET << std::endl;
}

// getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

// methods for the Form class
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

// Overloading the output operator
std::ostream& operator<<(std::ostream &os, const Form &form) {
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}