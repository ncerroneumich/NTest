#include <iostream>
#include "NTest.h"

NTest::NTest(const std::string& n) : name(n) {}

void NTest::AssertTrue(bool condition) {
    total_tests++;
    if (!condition) {
        std::cerr << name << ": Assertion failed: expected true, got false"
                << std::endl;
        fail_count++;
    }
}

void NTest::AssertFalse(bool condition) {
    total_tests++;
    if (condition) {
        std::cerr << name << ": Assertion failed: expected false, got true"
                << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertGreaterThan(const T& expected, const T& actual) {
    total_tests++;
    if (expected <= actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " to be greater than " << actual << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertGreaterThanOrEqual(const T& expected, const T& actual) {
    total_tests++;
    if (expected < actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " to be greater than or equal to " << actual << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertLessThan(const T& expected, const T& actual) {
    total_tests++;
    if (expected >= actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " to be less than " << actual << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertLessThanOrEqual(const T& expected, const T& actual) {
    total_tests++;
    if (expected > actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " to be less than or equal to " << actual << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertEqual(const T& expected, const T& actual) {
    total_tests++;
    if (expected != actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << ", got " << actual << std::endl;
        fail_count++;
    }
}

template <typename T>
void NTest::AssertNotEqual(const T& expected, const T& actual) {
    total_tests++;
    if (expected == actual) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " to be not equal to " << actual << std::endl;
        fail_count++;
    }
}

void NTest::AssertNear(const double& expected, const double& actual, const double& tolerance) {
    total_tests++;
    if (std::abs(expected - actual) > tolerance) {
        std::cerr << name << ": Assertion failed: expected " << expected
                << " but got " << actual << " (tolerance: " << tolerance << ")"
                << std::endl;
        fail_count++;
    }

}

void NTest::PrintSummary() {
    if (fail_count == 0) {
        std::cout << name << ": All " << total_tests << " tests passed" << std::endl;
    } else {
        std::cout << name << ": " << fail_count <<  "/" << total_tests << " tests failed" << std::endl;
    }
}