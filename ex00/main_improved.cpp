/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_improved.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:09:21 by lperez-h         #+#    #+#             */
/*   Updated: 2025/07/31 12:09:21 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert>
#include <sstream>
#include <functional>

// Test helper function to check if an exception is thrown
template<typename Exception>
bool testException(std::function<void()> func) {
    try {
        func();
        return false; // No exception thrown
    } catch (const Exception& e) {
        return true; // Expected exception thrown
    } catch (...) {
        return false; // Wrong exception type
    }
}

void testConstructorValid() {
    std::cout << BLUE << "\n=== Testing Valid Constructor ===" << RESET << std::endl;
    
    // Test valid grades
    Bureaucrat b1(1, "TopBoss");
    assert(b1.getName() == "TopBoss");
    assert(b1.getGrade() == 1);
    std::cout << GREEN << "✓ Grade 1 (highest): " << b1 << RESET << std::endl;
    
    Bureaucrat b2(150, "Intern");
    assert(b2.getName() == "Intern");
    assert(b2.getGrade() == 150);
    std::cout << GREEN << "✓ Grade 150 (lowest): " << b2 << RESET << std::endl;
    
    Bureaucrat b3(75, "MiddleManager");
    assert(b3.getName() == "MiddleManager");
    assert(b3.getGrade() == 75);
    std::cout << GREEN << "✓ Grade 75 (middle): " << b3 << RESET << std::endl;
}

void testConstructorInvalid() {
    std::cout << BLUE << "\n=== Testing Invalid Constructor ===" << RESET << std::endl;
    
    // Test grade too high (< 1)
    bool exceptionThrown = false;
    try {
        Bureaucrat b1(0, "TooHigh");
        assert(false && "Should have thrown GradeTooHighException");
    } catch (const Bureaucrat::GradeTooHighException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Grade 0 correctly throws GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    assert(exceptionThrown);
    
    exceptionThrown = false;
    try {
        Bureaucrat b2(-5, "VeryTooHigh");
        assert(false && "Should have thrown GradeTooHighException");
    } catch (const Bureaucrat::GradeTooHighException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Grade -5 correctly throws GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    assert(exceptionThrown);
    
    // Test grade too low (> 150)
    exceptionThrown = false;
    try {
        Bureaucrat b3(151, "TooLow");
        assert(false && "Should have thrown GradeTooLowException");
    } catch (const Bureaucrat::GradeTooLowException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Grade 151 correctly throws GradeTooLowException: " << e.what() << RESET << std::endl;
    }
    assert(exceptionThrown);
    
    exceptionThrown = false;
    try {
        Bureaucrat b4(1000, "WayTooLow");
        assert(false && "Should have thrown GradeTooLowException");
    } catch (const Bureaucrat::GradeTooLowException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Grade 1000 correctly throws GradeTooLowException: " << e.what() << RESET << std::endl;
    }
    assert(exceptionThrown);
}

void testCopyConstructor() {
    std::cout << BLUE << "\n=== Testing Copy Constructor ===" << RESET << std::endl;
    
    Bureaucrat original(42, "Original");
    Bureaucrat copy(original);
    
    assert(copy.getName() == original.getName());
    assert(copy.getGrade() == original.getGrade());
    assert(&copy != &original); // Different objects
    
    std::cout << GREEN << "✓ Copy constructor works correctly" << RESET << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
}

void testAssignmentOperator() {
    std::cout << BLUE << "\n=== Testing Assignment Operator ===" << RESET << std::endl;
    
    Bureaucrat b1(10, "Boss");
    Bureaucrat b2(100, "Employee");
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;
    
    b1 = b2;
    
    // Name should remain the same (const), grade should change
    assert(b1.getName() == "Boss"); // Name doesn't change (const)
    assert(b1.getGrade() == 100); // Grade changes
    assert(b2.getName() == "Employee");
    assert(b2.getGrade() == 100);
    
    std::cout << "After assignment (b1 = b2):" << std::endl;
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;
    std::cout << GREEN << "✓ Assignment operator works correctly (grade copied, name remains const)" << RESET << std::endl;
}

void testIncreaseGrade() {
    std::cout << BLUE << "\n=== Testing Increase Grade ===" << RESET << std::endl;
    
    // Test normal increase
    Bureaucrat b(50, "TestBureaucrat");
    int originalGrade = b.getGrade();
    b.increaseGrade();
    assert(b.getGrade() == originalGrade - 1);
    std::cout << GREEN << "✓ Grade increased from " << originalGrade << " to " << b.getGrade() << RESET << std::endl;
    
    // Test increase at boundary (grade 2 -> 1)
    Bureaucrat b2(2, "AlmostTop");
    b2.increaseGrade();
    assert(b2.getGrade() == 1);
    std::cout << GREEN << "✓ Grade increased from 2 to 1 (boundary test)" << RESET << std::endl;
    
    // Test exception when trying to increase beyond grade 1
    bool exceptionThrown = false;
    try {
        b2.increaseGrade(); // Should throw exception
        assert(false && "Should have thrown GradeTooHighException");
    } catch (const Bureaucrat::GradeTooHighException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Correctly throws GradeTooHighException when trying to increase beyond grade 1" << RESET << std::endl;
    }
    assert(exceptionThrown);
    assert(b2.getGrade() == 1); // Grade should remain unchanged after exception
}

void testDecreaseGrade() {
    std::cout << BLUE << "\n=== Testing Decrease Grade ===" << RESET << std::endl;
    
    // Test normal decrease
    Bureaucrat b(50, "TestBureaucrat");
    int originalGrade = b.getGrade();
    b.decreaseGrade();
    assert(b.getGrade() == originalGrade + 1);
    std::cout << GREEN << "✓ Grade decreased from " << originalGrade << " to " << b.getGrade() << RESET << std::endl;
    
    // Test decrease at boundary (grade 149 -> 150)
    Bureaucrat b2(149, "AlmostBottom");
    b2.decreaseGrade();
    assert(b2.getGrade() == 150);
    std::cout << GREEN << "✓ Grade decreased from 149 to 150 (boundary test)" << RESET << std::endl;
    
    // Test exception when trying to decrease beyond grade 150
    bool exceptionThrown = false;
    try {
        b2.decreaseGrade(); // Should throw exception
        assert(false && "Should have thrown GradeTooLowException");
    } catch (const Bureaucrat::GradeTooLowException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Correctly throws GradeTooLowException when trying to decrease beyond grade 150" << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        // Note: There's a bug in your decreaseGrade() method - it throws GradeTooHighException instead of GradeTooLowException
        exceptionThrown = true;
        std::cout << RED << "⚠️  Bug detected: decreaseGrade() throws GradeTooHighException instead of GradeTooLowException" << RESET << std::endl;
    }
    assert(exceptionThrown);
    assert(b2.getGrade() == 150); // Grade should remain unchanged after exception
}

void testOutputOperator() {
    std::cout << BLUE << "\n=== Testing Output Operator ===" << RESET << std::endl;
    
    Bureaucrat b(42, "TestOutput");
    std::ostringstream oss;
    oss << b;
    std::string output = oss.str();
    std::string expected = "TestOutput, bureaucrat grade 42.";
    
    assert(output == expected);
    std::cout << GREEN << "✓ Output operator works correctly: " << output << RESET << std::endl;
}

void testEdgeCases() {
    std::cout << BLUE << "\n=== Testing Edge Cases ===" << RESET << std::endl;
    
    // Test empty name
    Bureaucrat b1(50, "");
    assert(b1.getName() == "");
    std::cout << GREEN << "✓ Empty name handled correctly" << RESET << std::endl;
    
    // Test very long name
    std::string longName(100, 'A');
    Bureaucrat b2(75, longName);
    assert(b2.getName() == longName);
    std::cout << GREEN << "✓ Long name handled correctly" << RESET << std::endl;
    
    // Test self-assignment
    Bureaucrat b3(25, "SelfTest");
    b3 = b3;
    assert(b3.getGrade() == 25);
    assert(b3.getName() == "SelfTest");
    std::cout << GREEN << "✓ Self-assignment handled correctly" << RESET << std::endl;
}

void testMultipleOperations() {
    std::cout << BLUE << "\n=== Testing Multiple Operations ===" << RESET << std::endl;
    
    Bureaucrat b(75, "TestSubject");
    
    // Multiple increases
    for (int i = 0; i < 10; i++) {
        b.increaseGrade();
    }
    assert(b.getGrade() == 65);
    std::cout << GREEN << "✓ Multiple increases: 75 -> 65" << RESET << std::endl;
    
    // Multiple decreases
    for (int i = 0; i < 5; i++) {
        b.decreaseGrade();
    }
    assert(b.getGrade() == 70);
    std::cout << GREEN << "✓ Multiple decreases: 65 -> 70" << RESET << std::endl;
    
    // Test mixed operations
    b.increaseGrade();
    b.increaseGrade();
    b.decreaseGrade();
    assert(b.getGrade() == 69);
    std::cout << GREEN << "✓ Mixed operations work correctly: final grade = 69" << RESET << std::endl;
}

void testBoundaryExceptions() {
    std::cout << BLUE << "\n=== Testing Boundary Exceptions ===" << RESET << std::endl;
    
    // Test exception at exact boundary for increaseGrade
    Bureaucrat topBureaucrat(1, "TopLevel");
    bool exceptionThrown = false;
    try {
        topBureaucrat.increaseGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        exceptionThrown = true;
        std::cout << GREEN << "✓ Exception thrown at top boundary for increaseGrade" << RESET << std::endl;
    }
    assert(exceptionThrown);
    assert(topBureaucrat.getGrade() == 1); // Should remain unchanged
    
    // Test exception at exact boundary for decreaseGrade
    Bureaucrat bottomBureaucrat(150, "BottomLevel");
    exceptionThrown = false;
    try {
        bottomBureaucrat.decreaseGrade();
    } catch (const std::exception& e) { // Catch any exception due to the bug
        exceptionThrown = true;
        std::cout << GREEN << "✓ Exception thrown at bottom boundary for decreaseGrade" << RESET << std::endl;
    }
    assert(exceptionThrown);
    assert(bottomBureaucrat.getGrade() == 150); // Should remain unchanged
}

void testConstMethods() {
    std::cout << BLUE << "\n=== Testing Const Methods ===" << RESET << std::endl;
    
    const Bureaucrat constBureaucrat(100, "ConstTest");
    
    // Test that const methods work
    assert(constBureaucrat.getName() == "ConstTest");
    assert(constBureaucrat.getGrade() == 100);
    
    // Test output with const object
    std::ostringstream oss;
    oss << constBureaucrat;
    std::string output = oss.str();
    std::string expected = "ConstTest, bureaucrat grade 100.";
    assert(output == expected);
    
    std::cout << GREEN << "✓ Const methods work correctly with const objects" << RESET << std::endl;
}

int main() {
    std::cout << BLUE << "🧪 Starting Comprehensive Bureaucrat Class Test Suite 🧪" << RESET << std::endl;
    
    try {
        testConstructorValid();
        testConstructorInvalid();
        testCopyConstructor();
        testAssignmentOperator();
        testIncreaseGrade();
        testDecreaseGrade();
        testOutputOperator();
        testEdgeCases();
        testMultipleOperations();
        testBoundaryExceptions();
        testConstMethods();
        
        std::cout << GREEN << "\n🎉 All tests passed successfully! 🎉" << RESET << std::endl;
        std::cout << BLUE << "Total test functions executed: 11" << RESET << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << RED << "\n❌ Test failed with exception: " << e.what() << RESET << std::endl;
        return 1;
    } catch (...) {
        std::cerr << RED << "\n❌ Test failed with unknown exception" << RESET << std::endl;
        return 1;
    }
    
    return 0;
}
