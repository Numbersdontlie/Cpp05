/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:07:59 by luifer            #+#    #+#             */
/*   Updated: 2025/08/11 11:47:24 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

//Default constructor
ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137), _target("no name") {
    //std::cout << BLUE << "ShruberryCreationForm default constructor called" << RESET << std::endl;
}

//Parameterized constructor
ShruberryCreationForm::ShruberryCreationForm(const std::string &target) : AForm("ShruberryCreationForm", 145, 137), _target(target) {
    //std::cout << BLUE << "ShruberryCreationForm parameterized constructor called 🌳 🌳 🌳" << RESET << std::endl;
}

//Copy constructor
ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &other) : AForm(other), _target(other._target) {
    //std::cout << BLUE << "ShruberryCreationForm copy constructor called" << RESET << std::endl;
}

//Assignment operator overload
ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm &other){
    //std::cout << BLUE << "ShruberryCreationForm assignment operator called 🌳 🌳 🌳" << RESET << std::endl;
    if (this != &other) {
        this->_target = other.getTarget(); // Copy the target
    }
    return *this;
}

//Destructor
ShruberryCreationForm::~ShruberryCreationForm(){
    //std::cout << RED << "ShruberryCreationForm destructor called" << RESET << std::endl;
}

//Getter
const std::string& ShruberryCreationForm::getTarget() const {
    return this->_target;
}

//Exception
const char* ShruberryCreationForm::ErrorFileException::what() const throw() {
    return "ShruberryCreationForm: Error creating file";
}

//Methods to execute the form
void ShruberryCreationForm::execute() const {
    std::string filename = this->_target + "_shruberry";
    std::ofstream ofs(filename.c_str(), std::ios::app);
    if (ofs.is_open()){
        ofs << "                                      " << std::endl;
        ofs << "          oxoxoo    ooxoo             " << std::endl;
        ofs << "        ooxoxo oo  oxoxooo            " << std::endl;
        ofs << "        oooo xxoxoo ooo ooox          " << std::endl;
        ofs << "        oxo o oxoxo  xoxxoxo          " << std::endl;
        ofs << "        oxo xooxoooo o ooo            " << std::endl;
        ofs << "          ooo\\oo\\  /o/o             " << std::endl;
        ofs << "              \\  \\/ /               " << std::endl;
        ofs << "                |   /                 " << std::endl;
        ofs << "                |  |                  " << std::endl;
        ofs << "                | D|                  " << std::endl;
        ofs << "                |  |                  " << std::endl;
        ofs << "                |  |                  " << std::endl;
        ofs << "       ________/___\\_____            " << std::endl;
        ofs << std::endl;
        std::cout << "ShruberryCreated at " << _target << "_shruberry."<< std::endl;
}
else
    throw ErrorFileException();
ofs.close();
}

