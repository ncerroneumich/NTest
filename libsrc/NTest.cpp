#include <iostream>
#include <string>
#include "NTest.h"

NTest::NTest(const std::string& name) : name_(name) {}

void NTest::AssertTrue(bool condition) {
    total_tests_++;
    if (!condition) {
        std::cerr << name_ << ": Assertion failed: expected true, got false"
                << std::endl;
        fail_count_++;
    }
}

void NTest::AssertFalse(bool condition) {
    total_tests_++;
    if (condition) {
        std::cerr << name_ << ": Assertion failed: expected false, got true"
                << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertGreaterThan(const T& expected, const T& actual) {
    total_tests_++;
    if (expected <= actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be greater than " << actual << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertGreaterThanOrEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected < actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be greater than or equal to " << actual << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertLessThan(const T& expected, const T& actual) {
    total_tests_++;
    if (expected >= actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be less than " << actual << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertLessThanOrEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected > actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be less than or equal to " << actual << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected != actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << ", got " << actual << std::endl;
        fail_count_++;
    }
}

template <typename T>
void NTest::AssertNotEqual(const T& expected, const T& actual) {
    total_tests_++;
    if (expected == actual) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " to be not equal to " << actual << std::endl;
        fail_count_++;
    }
}

void NTest::AssertNear(const double& expected, const double& actual, const double& tolerance) {
    total_tests_++;
    if (std::abs(expected - actual) > tolerance) {
        std::cerr << name_ << ": Assertion failed: expected " << expected
                << " but got " << actual << " (tolerance: " << tolerance << ")"
                << std::endl;
        fail_count_++;
    }

}

void NTest::PrintSummary() {
    if (fail_count_ == 0) {
        std::cout << name_ << ": All " << total_tests_ << " tests passed" << std::endl;
    } else {
        std::cout << name_ << ": " << fail_count_ <<  "/" << total_tests_ << " tests failed" << std::endl;
    }
}