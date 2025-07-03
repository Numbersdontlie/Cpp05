/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:20:23 by luifer            #+#    #+#             */
/*   Updated: 2025/07/03 14:27:39 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    std::cout << BLUE << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << BLUE << "Intern copy constructor called" << RESET << std::endl;
    (void)other; // Avoid unused parameter warning
}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // Avoid unused parameter warning
    std::cout << BLUE << "Intern assignment operator called" << RESET << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

const char* Intern::NonExistingFormException::what() const throw() {
    return "Intern: Form does not exist";
}

//Static functions to create forms and call them inside the makeForm method
//they return pointers to the base class AForm*
static AForm* createShruberryCreationForm(const std::string &target) {
    return new ShruberryCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

//TO DO: Create the method to create the form 
//It needs to distinct between the different methods and call the right one
AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    // Array of form names
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of function pointers, it contains pointers to the static functions 
    // that create forms
    AForm* (*formCreators[])(const std::string&) = {
        createShruberryCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };

    // Number of forms to search in the array of form names
    const int numForms = 3;

    // Loop through the form names to find a match and when found return the 
    // corresponding function pointer from the formCreators array that creates the form
    for (int i = 0; i < numForms; ++i) {
        if (formName == formNames[i]) {
            std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
            return formCreators[i](target); // Call the corresponding form creator
        }
    }

    // If no match is found, throw an exception
    throw NonExistingFormException();
}