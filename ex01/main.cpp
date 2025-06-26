/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:48:09 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 21:34:06 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat PePe(103, "PePe");
        std::cout << BLUE << PePe << RESET << std::endl;
        // Create a Form with valid parameters
        Form formulario1("Formulario1", 50, 100);
        std::cout << BLUE << formulario1 << RESET << std::endl;
        // Bureaucrat signs the Form
        PePe.signForm(formulario1);
        std::cout << GREEN << PePe.getName() << " signed " << formulario1.getName() << RESET << std::endl;
        PePe.increaseGrade(); // Increase the grade of the Bureaucrat
        PePe.increaseGrade();
        PePe.increaseGrade();
        PePe.increaseGrade();
        // Bureaucrat tries to sign the Form again
        PePe.signForm(formulario1);
        std::cout << BLUE << PePe << RESET << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    catch (...) {
        std::cerr << RED << "An unexpected exception occurred." << RESET << std::endl;
    }
    std::cout << std::endl;
    try {
        // Create a form with low grade
        Form formulario2("Formulario2", 151, 0); // This should throw an exception
    }
    catch (const std::exception& e){
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    catch (...) {
        std::cerr << RED << "An unexpected exception occurred." << RESET << std::endl;
    }
}
