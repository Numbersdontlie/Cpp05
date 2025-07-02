/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:20:23 by luifer            #+#    #+#             */
/*   Updated: 2025/07/03 00:24:06 by luifer           ###   ########.fr       */
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
    void(other);
    std::cout << BLUE << "Intern assignment operator called" << RESET << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

const char* Intern::NonExistingFormException::what() const throw() {
    return "Intern: Form does not exist";
}

//TO DO: Create the method to create the form 
//It needs to distinct between the different methods and call the right one