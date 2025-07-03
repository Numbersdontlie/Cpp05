/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:56:58 by luifer            #+#    #+#             */
/*   Updated: 2025/07/03 14:01:48 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include <iostream>

int main() {
    try{
        Intern intern;
        Bureaucrat bureaucrat(1, "John");
        
        AForm *form1 = intern.makeForm("shrubbery creation", "Garden");
        AForm *form2 = intern.makeForm("robotomy request", "Robot");
        AForm *form3 = intern.makeForm("presidential pardon", "President");

        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);

        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);

        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    catch(...) {
        std::cerr << RED << "An unexpected error occurred." << RESET << std::endl;
    }
    std::cout << std::endl;
}