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
    std::string name_;
    int total_tests_ = 0;
    int fail_count_ = 0;

public:
    NTest(const std::string& name);

    void AssertTrue(bool condition);

    template <typename T>
    void AssertGreaterThan(const T& expected, const T& actual);

    template <typename T>
    void AssertLessThan(const T& expected, const T& actual);

    template <typename T>
    void AssertEqual(const T& expected, const T& actual);

    template <typename T>
    void AssertNotEqual(const T& expected, const T& actual);

    void PrintSummary();
};

#endif // TESTCASE_H_