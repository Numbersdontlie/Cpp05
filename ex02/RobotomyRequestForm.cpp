/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:39:06 by luifer            #+#    #+#             */
/*   Updated: 2025/06/26 23:47:03 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default_target") {
    std::cout << BLUE << "RobotomyRequestForm default constructor called 🤖 🤖 🤖" << RESET << std::endl;
}

RobotomyRequestForm::Robotomy
