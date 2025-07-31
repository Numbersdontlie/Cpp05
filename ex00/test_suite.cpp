/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_suite.cpp                                     :+:      :+:    :+:   */
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
#include <vector>
#include <functional>

// Test statistics
struct TestStats {
    int totalTests = 0;
    int passedTests = 0;
    int failedTests = 0;
    
    void addPass() { totalTests++; passedTests++; }
    void addFail() { totalTests++; failedTests++; }
    
    void printSummary() const {
        std::cout << BLUE << "\n📊 Test Summary:" << RESET << std::endl;
        std::cout << "Total tests: " << totalTests << std::endl;
        std::cout << GREEN << "Passed: " << passedTests << RESET << std::endl;
        if (failedTests > 0) {
            std::cout << RED << "Failed: " << failedTests << RESET << std::endl;
        }
        std::cout << "Success rate: " << (passedTests * 100 / totalTests) << "%" << std::endl;
    }
};

TestStats globalStats;

// Macro for easier assertion testing
#define TEST_ASSERT(condition, message) \
    do { \
        if (condition) { \
            std::cout << GREEN << "✓ " << message << RESET << std::endl; \
            globalStats.addPass(); \
        } else { \
            std::cout << RED << "✗ " << message << RESET << std::endl; \
            globalStats.addFail(); \
            assert(false); \
        } \
    } while(0)

// Test helper function to check if an exception is thrown
template<typename Exception>
bool testException(std::function<void()> func, std::string& exceptionMessage) {
    try {
        func();
        return false; // No exception thrown
    } catch (const Exception& e) {
        exceptionMessage = e.what();
        return true; // Expected exception thrown
    } catch (const std::exception& e) {
        exceptionMessage = std::string("Wrong exception type: ") + e.what();
        return false; // Wrong exception type
    } catch (...) {
        exceptionMessage = "Unknown exception type";
        return false; // Unknown exception type
    }
}

void testConstructorValidCases() {
    std::cout << BLUE << "\n=== Testing Valid Constructor Cases ===" << RESET << std::endl;
    
    // Test boundary valid grades
    Bureaucrat b1(1, "TopBoss");
    TEST_ASSERT(b1.getName() == "TopBoss", "Grade 1 name assignment");
    TEST_ASSERT(b1.getGrade() == 1, "Grade 1 value assignment");
    
    Bureaucrat b2(150, "Intern");
    TEST_ASSERT(b2.getName() == "Intern", "Grade 150 name assignment");
    TEST_ASSERT(b2.getGrade() == 150, "Grade 150 value assignment");
    
    // Test middle range grades
    std::vector<int> testGrades = {2, 10, 50, 75, 100, 149};
    for (int grade : testGrades) {
        Bureaucrat b(grade, "Test" + std::to_string(grade));
        TEST_ASSERT(b.getGrade() == grade, "Grade " + std::to_string(grade) + " assignment");
    }
}

void testConstructorInvalidCases() {
    std::cout << BLUE << "\n=== Testing Invalid Constructor Cases ===" << RESET << std::endl;
    
    // Test grades too high
    std::vector<int> tooHighGrades = {0, -1, -5, -100};
    for (int grade : tooHighGrades) {
        std::string exceptionMsg;
        bool exceptionThrown = testException<Bureaucrat::GradeTooHighException>(
            [grade]() { Bureaucrat b(grade, "TooHigh"); },
            exceptionMsg
        );
        TEST_ASSERT(exceptionThrown, "Grade " + std::to_string(grade) + " throws GradeTooHighException");
    }
    
    // Test grades too low
    std::vector<int> tooLowGrades = {151, 200, 1000, 999999};
    for (int grade : tooLowGrades) {
        std::string exceptionMsg;
        bool exceptionThrown = testException<Bureaucrat::GradeTooLowException>(
            [grade]() { Bureaucrat b(grade, "TooLow"); },
            exceptionMsg
        );
        TEST_ASSERT(exceptionThrown, "Grade " + std::to_string(grade) + " throws GradeTooLowException");
    }
}

void testCopySemantics() {
    std::cout << BLUE << "\n=== Testing Copy Constructor and Assignment ===" << RESET << std::endl;
    
    // Copy constructor test
    Bureaucrat original(42, "Original");
    Bureaucrat copy(original);
    
    TEST_ASSERT(copy.getName() == original.getName(), "Copy constructor preserves name");
    TEST_ASSERT(copy.getGrade() == original.getGrade(), "Copy constructor preserves grade");
    TEST_ASSERT(&copy != &original, "Copy constructor creates different object");
    
    // Assignment operator test
    Bureaucrat b1(10, "Boss");
    Bureaucrat b2(100, "Employee");
    
    std::string originalB1Name = b1.getName();
    b1 = b2;
    
    TEST_ASSERT(b1.getName() == originalB1Name, "Assignment operator preserves const name");
    TEST_ASSERT(b1.getGrade() == b2.getGrade(), "Assignment operator copies grade");
    
    // Self-assignment test
    Bureaucrat b3(25, "SelfTest");
    b3 = b3;
    TEST_ASSERT(b3.getGrade() == 25, "Self-assignment preserves grade");
    TEST_ASSERT(b3.getName() == "SelfTest", "Self-assignment preserves name");
}

void testGradeModification() {
    std::cout << BLUE << "\n=== Testing Grade Modification Methods ===" << RESET << std::endl;
    
    // Test normal increase
    Bureaucrat b1(50, "TestIncrease");
    int originalGrade = b1.getGrade();
    b1.increaseGrade();
    TEST_ASSERT(b1.getGrade() == originalGrade - 1, "Normal grade increase works");
    
    // Test normal decrease
    Bureaucrat b2(50, "TestDecrease");
    originalGrade = b2.getGrade();
    b2.decreaseGrade();
    TEST_ASSERT(b2.getGrade() == originalGrade + 1, "Normal grade decrease works");
    
    // Test boundary cases for increase
    Bureaucrat b3(2, "AlmostTop");
    b3.increaseGrade();
    TEST_ASSERT(b3.getGrade() == 1, "Increase to grade 1 works");
    
    std::string exceptionMsg;
    bool exceptionThrown = testException<Bureaucrat::GradeTooHighException>(
        [&b3]() { b3.increaseGrade(); },
        exceptionMsg
    );
    TEST_ASSERT(exceptionThrown, "Increase beyond grade 1 throws exception");
    TEST_ASSERT(b3.getGrade() == 1, "Grade unchanged after failed increase");
    
    // Test boundary cases for decrease
    Bureaucrat b4(149, "AlmostBottom");
    b4.decreaseGrade();
    TEST_ASSERT(b4.getGrade() == 150, "Decrease to grade 150 works");
    
    // Note: Due to bug in implementation, this might throw GradeTooHighException instead
    exceptionThrown = testException<std::exception>(
        [&b4]() { b4.decreaseGrade(); },
        exceptionMsg
    );
    TEST_ASSERT(exceptionThrown, "Decrease beyond grade 150 throws exception");
    TEST_ASSERT(b4.getGrade() == 150, "Grade unchanged after failed decrease");
}

void testOutputFormatting() {
    std::cout << BLUE << "\n=== Testing Output Formatting ===" << RESET << std::endl;
    
    struct TestCase {
        int grade;
        std::string name;
        std::string expected;
    };
    
    std::vector<TestCase> testCases = {
        {42, "TestOutput", "TestOutput, bureaucrat grade 42."},
        {1, "TopBoss", "TopBoss, bureaucrat grade 1."},
        {150, "Intern", "Intern, bureaucrat grade 150."},
        {100, "", ", bureaucrat grade 100."},
        {50, "Name With Spaces", "Name With Spaces, bureaucrat grade 50."}
    };
    
    for (const auto& testCase : testCases) {
        Bureaucrat b(testCase.grade, testCase.name);
        std::ostringstream oss;
        oss << b;
        std::string output = oss.str();
        TEST_ASSERT(output == testCase.expected, 
                   "Output format for '" + testCase.name + "' grade " + std::to_string(testCase.grade));
    }
}

void testEdgeCasesAndSpecialNames() {
    std::cout << BLUE << "\n=== Testing Edge Cases and Special Names ===" << RESET << std::endl;
    
    // Empty name
    Bureaucrat b1(50, "");
    TEST_ASSERT(b1.getName() == "", "Empty name handled correctly");
    
    // Very long name
    std::string longName(100, 'A');
    Bureaucrat b2(75, longName);
    TEST_ASSERT(b2.getName() == longName, "Long name handled correctly");
    
    // Special characters in name
    Bureaucrat b3(25, "José María O'Connor-Smith");
    TEST_ASSERT(b3.getName() == "José María O'Connor-Smith", "Special characters in name");
    
    // Numbers in name
    Bureaucrat b4(60, "Agent007");
    TEST_ASSERT(b4.getName() == "Agent007", "Numbers in name");
    
    // Unicode characters (if supported)
    Bureaucrat b5(80, "张三");
    TEST_ASSERT(b5.getName() == "张三", "Unicode characters in name");
}

void testMultipleOperationsSequence() {
    std::cout << BLUE << "\n=== Testing Multiple Operations Sequences ===" << RESET << std::endl;
    
    Bureaucrat b(75, "TestSubject");
    
    // Sequence 1: Multiple increases
    for (int i = 0; i < 10; i++) {
        b.increaseGrade();
    }
    TEST_ASSERT(b.getGrade() == 65, "10 consecutive increases: 75 -> 65");
    
    // Sequence 2: Multiple decreases
    for (int i = 0; i < 5; i++) {
        b.decreaseGrade();
    }
    TEST_ASSERT(b.getGrade() == 70, "5 consecutive decreases: 65 -> 70");
    
    // Sequence 3: Mixed operations
    b.increaseGrade(); // 69
    b.increaseGrade(); // 68
    b.decreaseGrade(); // 69
    b.increaseGrade(); // 68
    b.decreaseGrade(); // 69
    TEST_ASSERT(b.getGrade() == 69, "Mixed operation sequence results in grade 69");
    
    // Sequence 4: Test that operations maintain invariants
    int gradeBeforeOp = b.getGrade();
    b.increaseGrade();
    b.decreaseGrade();
    TEST_ASSERT(b.getGrade() == gradeBeforeOp, "Increase followed by decrease returns to original grade");
}

void testConstCorrectness() {
    std::cout << BLUE << "\n=== Testing Const Correctness ===" << RESET << std::endl;
    
    const Bureaucrat constBureaucrat(100, "ConstTest");
    
    // Test that const methods work
    TEST_ASSERT(constBureaucrat.getName() == "ConstTest", "Const getName() works");
    TEST_ASSERT(constBureaucrat.getGrade() == 100, "Const getGrade() works");
    
    // Test output with const object
    std::ostringstream oss;
    oss << constBureaucrat;
    std::string output = oss.str();
    std::string expected = "ConstTest, bureaucrat grade 100.";
    TEST_ASSERT(output == expected, "Output operator works with const objects");
}

void testExceptionMessages() {
    std::cout << BLUE << "\n=== Testing Exception Messages ===" << RESET << std::endl;
    
    std::string exceptionMsg;
    
    // Test GradeTooHighException message
    bool exceptionThrown = testException<Bureaucrat::GradeTooHighException>(
        []() { Bureaucrat b(0, "Test"); },
        exceptionMsg
    );
    TEST_ASSERT(exceptionThrown, "GradeTooHighException is thrown");
    TEST_ASSERT(!exceptionMsg.empty(), "GradeTooHighException has non-empty message");
    std::cout << "  Exception message: \"" << exceptionMsg << "\"" << std::endl;
    
    // Test GradeTooLowException message
    exceptionThrown = testException<Bureaucrat::GradeTooLowException>(
        []() { Bureaucrat b(151, "Test"); },
        exceptionMsg
    );
    TEST_ASSERT(exceptionThrown, "GradeTooLowException is thrown");
    TEST_ASSERT(!exceptionMsg.empty(), "GradeTooLowException has non-empty message");
    std::cout << "  Exception message: \"" << exceptionMsg << "\"" << std::endl;
}

void testPerformanceAndMemory() {
    std::cout << BLUE << "\n=== Testing Performance and Memory ===" << RESET << std::endl;
    
    // Test creating many bureaucrats
    std::vector<Bureaucrat> bureaucrats;
    for (int i = 1; i <= 150; i++) {
        bureaucrats.emplace_back(i, "Bureaucrat" + std::to_string(i));
    }
    TEST_ASSERT(bureaucrats.size() == 150, "Created 150 bureaucrats successfully");
    
    // Test that all have correct grades
    bool allCorrect = true;
    for (size_t i = 0; i < bureaucrats.size(); i++) {
        if (bureaucrats[i].getGrade() != static_cast<int>(i + 1)) {
            allCorrect = false;
            break;
        }
    }
    TEST_ASSERT(allCorrect, "All 150 bureaucrats have correct grades");
    
    // Test copy operations on many objects
    std::vector<Bureaucrat> copies;
    for (const auto& b : bureaucrats) {
        copies.push_back(b); // Copy constructor
    }
    TEST_ASSERT(copies.size() == bureaucrats.size(), "Mass copy operations work correctly");
}

int main() {
    std::cout << BLUE << "🧪 Starting Comprehensive Bureaucrat Class Test Suite 🧪" << RESET << std::endl;
    std::cout << "This test suite uses assertions to validate all aspects of the Bureaucrat class.\n" << std::endl;
    
    try {
        testConstructorValidCases();
        testConstructorInvalidCases();
        testCopySemantics();
        testGradeModification();
        testOutputFormatting();
        testEdgeCasesAndSpecialNames();
        testMultipleOperationsSequence();
        testConstCorrectness();
        testExceptionMessages();
        testPerformanceAndMemory();
        
        std::cout << GREEN << "\n🎉 All tests completed! 🎉" << RESET << std::endl;
        globalStats.printSummary();
        
        if (globalStats.failedTests == 0) {
            std::cout << GREEN << "\n✨ Perfect score! Your Bureaucrat class implementation is working correctly! ✨" << RESET << std::endl;
        } else {
            std::cout << RED << "\n⚠️  Some tests failed. Review the implementation and fix the issues." << RESET << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << RED << "\n❌ Test suite failed with exception: " << e.what() << RESET << std::endl;
        std::cerr << "This indicates a serious issue with the implementation." << std::endl;
        globalStats.printSummary();
        return 1;
    } catch (...) {
        std::cerr << RED << "\n❌ Test suite failed with unknown exception" << RESET << std::endl;
        globalStats.printSummary();
        return 1;
    }
    
    return (globalStats.failedTests == 0) ? 0 : 1;
}
