/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:35:33 by luifer            #+#    #+#             */
/*   Updated: 2025/07/02 22:57:10 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // ShruberryCreationForm
    try {
        Bureaucrat luchito(147, "luchito");

        ShruberryCreationForm shrubbery("Home");
        //this should not work
        luchito.signForm(shrubbery);
        luchito.executeForm(shrubbery);
        std::cout << std::endl;
        luchito.increaseGrade();
        luchito.increaseGrade();
        std::cout << std::endl;
        //after improving grade it should work
        luchito.signForm(shrubbery);
        luchito.executeForm(shrubbery);
        Bureaucrat canserbero(86, "canserbero");
        canserbero.executeForm(shrubbery);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << RED << "caught an unknown exception" << RESET << std::endl;
    }
    std::cout << std::endl;

    //Robotomy
    try {
        Bureaucrat farid(75, "farid");
        RobotomyRequestForm robotomy("genaubot");
        farid.signForm(robotomy);
        farid.executeForm(robotomy);
        std::cout << std::endl;
        farid.increaseGrade();
        farid.increaseGrade();
        farid.increaseGrade();
        farid.signForm(robotomy);
        farid.executeForm(robotomy);
        std::cout << std::endl;
        Bureaucrat PePo(45, "PePo");
        PePo.executeForm(robotomy);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << RED << "caught an unknown exception" << RESET << std::endl;
    }
    std::cout << std::endl;
    //PresidentialPardonForm
    try {
        Bureaucrat luifer(28, "luifer");
        PresidentialPardonForm presidential("presidential");
        luifer.signForm(presidential);
        luifer.executeForm(presidential);
        std::cout << std::endl;
        luifer.increaseGrade();
        luifer.increaseGrade();
        luifer.increaseGrade();
        luifer.signForm(presidential);
        luifer.executeForm(presidential);
        std::cout << std::endl;
        Bureaucrat zaphod(5, "Zaphod Beeblebrox");
        zaphod.executeForm(presidential);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << RED << "caught an unknown exception" << RESET << std::endl;
    }
    std::cout << std::endl;
}