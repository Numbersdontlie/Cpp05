/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:35:07 by luifer            #+#    #+#             */
/*   Updated: 2025/08/01 12:41:16 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>

int main() {
	try {
		Bureaucrat falton(-2, "Falton2");
		std::cout << BLUE << " 🕴🏽 🕴🏽 🕴🏽Falton2 Bureaucrat created with grade: " << falton.getGrade() << RESET << std::endl;
    }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "An unknown error occurred." << RESET << std::endl;
	}
	std::cout << std::endl;
	
	int	startingGrade = 42;
	try {
		Bureaucrat pepe(startingGrade, "PePe");
		std::cout << BLUE << " 🕴🏽 🕴🏽 🕴🏽PePe Bureaucrat created with grade: " << pepe.getGrade() << RESET << std::endl;
		
		pepe.decreaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽PePe's grade decreased to: " << pepe.getGrade() << RESET << std::endl;
		pepe.decreaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽PePe's grade decreased to: " << pepe.getGrade() << RESET << std::endl;
		pepe.increaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽PePe's grade increased to: " << pepe.getGrade() << RESET << std::endl;
		pepe.increaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽PePe's grade increased to: " << pepe.getGrade() << RESET << std::endl;
		pepe.increaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽PePe's grade increased to: " << pepe.getGrade() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "An unknown error occurred." << RESET << std::endl;
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat falton(4, "Falton");
		std::cout << BLUE << falton <<  RESET << std::endl;
		Bureaucrat falton2(28, "Falton2");
		std::cout << BLUE << falton2 <<  RESET << std::endl;
		falton = falton2;
		std::cout << BLUE << "After assignment operator: " << falton << RESET << std::endl;
		std::cout << BLUE << "After assignment operator: " << falton2 << RESET << std::endl;
		falton.increaseGrade();
		falton2.decreaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽Falton's grade increased to: " << falton.getGrade() << RESET << std::endl;
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽Falton2's grade decreased to: " << falton2.getGrade() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}