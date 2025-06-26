/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:35:07 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 13:31:55 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	int	startingGrade = 42;
	try {
		Bureaucrat pepe(startingGrade, "PePe");
		std::cout << BLUE << " 🕴🏽 🕴🏽 🕴🏽PePe Bureaucrat created with grade: " << startingGrade << RESET << std::endl;
		
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
		Bureaucrat falton(200, "Falton");
		std::cout << BLUE << " 🕴🏽 🕴🏽 🕴🏽Falton Bureaucrat created with grade: " << 200 << RESET << std::endl;
		Bureaucrat falton2(-2, "Falton2");
		std::cout << BLUE << " 🕴🏽 🕴🏽 🕴🏽Falton2 Bureaucrat created with grade: " << -2 << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "An unknown error occurred." << RESET << std::endl;
	}
	try {
		Bureaucrat falton(4, "Falton");
		std::cout << BLUE << falton <<  RESET << std::endl;
		Bureaucrat falton2(28, "Falton2");
		std::cout << BLUE << falton2 <<  RESET << std::endl;
		falton = falton2;
		std::cout << BLUE << "After assignment operator: " << falton << RESET << std::endl;
		std::cout << BLUE << "After assignment operator: " << falton2 << RESET << std::endl;
		falton.increaseGrade();
		falton2.increaseGrade();
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽Falton's grade increased to: " << falton.getGrade() << RESET << std::endl;
		std::cout << GREEN << " 🕴🏽 🕴🏽 🕴🏽Falton2's grade increased to: " << falton2.getGrade() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (...) {
		std::cerr << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}