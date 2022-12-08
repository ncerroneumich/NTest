#include <iostream>
#include <string>
#include <vector>
#include "NTest.h"


NTest::NTest(const std::string& name) : name_(name) {}

void NTest::AssertTrue(bool condition) {
    total_tests_++;
    if (!condition) {
        std::cerr << name_ << ": Assertion failed: expected true, got false"
                << std::endl;
        ++fail_count_;
    }
}

template <typename T>
void NTest::AssertGreaterThan(const T& expected, const T& actual) {
    total_tests_++;
    if (expected <= actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be greater than " << actual << std::endl;
        ++fail_count_;
    }
}

template <typename T>
void NTest::AssertLessThan(const T& expected, const T& actual) {
    total_tests_++;
    if (expected >= actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be less than " << actual << std::endl;
        ++fail_count_;
    }
}

template <typename T>
void NTest::AssertEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected != actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << ", got " << actual << std::endl;
        ++fail_count_;
    }
}

template <typename T>
void NTest::AssertNotEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected == actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be not equal to " << actual << std::endl;
    }
}

void NTest::PrintSummary() {
    if (fail_count_ == 0) {
        std::cout << name_ << ": All " << total_tests_ << " tests passed" << std::endl;
    } else {
        std::cout << name_ << ": " << fail_count_ <<  "/" << total_tests_ << " tests failed" << std::endl;
    }
}