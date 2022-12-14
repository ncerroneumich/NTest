#ifndef TESTCASE_H_
#define TESTCASE_H_

#include <string>

// Usage: Declare a sequence of named tests that utilize the
//        various assertions provided by this class. It is
//        best practice to make a larger test suite comprised
//        of multiple smaller tests rather than one large test
//        suite. 
class NTest {
private:
    std::string name;
    int total_tests = 0;
    int fail_count = 0;

public:
    NTest(const std::string& name);

    void AssertTrue(bool condition);

    void AssertFalse(bool condition);

    template <typename T>
    void AssertGreaterThan(const T& expected, const T& actual);

    template <typename T>
    void AssertGreaterThanOrEqual(const T& expected, const T& actual);

    template <typename T>
    void AssertLessThan(const T& expected, const T& actual);

    template <typename T>
    void AssertLessThanOrEqual(const T& expected, const T& actual);

    template <typename T>
    void AssertEqual(const T& expected, const T& actual);

    template <typename T>
    void AssertNotEqual(const T& expected, const T& actual);

    void AssertNear(const double& expected, const double& actual, const double& tolerance);

    void PrintSummary();
};

#endif // TESTCASE_H_
