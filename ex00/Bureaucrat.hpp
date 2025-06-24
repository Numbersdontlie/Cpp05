/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:51:56 by luifer            #+#    #+#             */
/*   Updated: 2025/06/24 20:55:01 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;
    static const int _minGrade = 1;
    static const int _maxGrade = 150;

    public:
        Bureaucrat();// Default constructor
        Bureaucrat(int grade, const str::string& name); // Constructor with parameters
        Bureaucrat(const Bureaucrat& other); // Copy constructor
        Bureaucrat& operator=(const Bureaucrat& other); // Assignment operator constructor
        ~Bureaucrat(); // Destructor

        //Getters
        const std::string& getName() const;
        int getGrade() const;

        //Methods to increase or decrease
        void increaseGrade();
        void decreaseGrade();

        //Exception classes
        cl
};

#endif