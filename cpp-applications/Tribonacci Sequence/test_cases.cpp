#include <iostream>
#include <vector>
#include "tribonacci.h"

int main() {
    std::vector<int> signature = { 1, 1, 1 };
    std::vector<int> expected = { 1, 1, 1, 3, 5, 9, 17, 31, 57, 105 };
    if (tribonacci(signature, 10) == expected) std::cout << "Test 1 Passed" << std::endl;
    else {
        std::cout << "Test 1 Failed" << std::endl << "Expected: ";
        for (auto i : expected) std::cout << i << " ";
        std::cout << std::endl << "Actual: ";
        for (auto i : tribonacci(signature, 10)) std::cout << i << " ";
        std::cout << std::endl;
    }

    signature = { 0, 0, 1 };
    expected = { 0,0,1,1,2,4,7,13,24,44 };
    if (tribonacci(signature, 10) == expected) std::cout << "Test 2 Passed" << std::endl;
    else {
        std::cout << "Test 2 Failed" << std::endl << "Expected: ";
        for (auto i : expected) std::cout << i << " ";
        std::cout << std::endl << "Actual: ";
        for (auto i : tribonacci(signature, 10)) std::cout << i << " ";
        std::cout << std::endl;
    }

    signature = { 1,2,3 };
    expected = { 1,2 };
    if (tribonacci(signature, 2) == expected) std::cout << "Test 6 Passed" << std::endl;
    else {
        std::cout << "Test 6 Failed" << std::endl << "Expected: ";
        for (auto i : expected) std::cout << i << " ";
        std::cout << std::endl << "Actual: ";
        for (auto i : tribonacci(signature, 2)) std::cout << i << " ";
        std::cout << std::endl;
    }

    int third = rand() % 10;
    signature = { 1,2, third };
    expected = {};
    if (tribonacci(signature, 0) == (expected)) std::cout << "Test 7 Passed" << std::endl;
    else {
        std::cout << "Test 7 Failed" << std::endl << "Expected: ";
        for (auto i : expected) std::cout << i << " ";
        std::cout << std::endl << "Actual: ";
        for (auto i : tribonacci(signature, 0)) std::cout << i << " ";
        std::cout << std::endl;
    }
}