/**
 * TestCBase.cpp - library test cases
 * 2025-03-20
 * vika <https://github.com/hi-im-vika>
 */

#include "TestCBase.hpp"

TestCBase::TestCBase() {
    _text = "Hello world!";
    _count = 0;
}

TestCBase::~TestCBase() = default;

void TestCBase::update() {
    _count++;
}

void TestCBase::draw() {
    std::cout << _text << std::endl;
    std::cout << "Current count: " << _count << std::endl;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(1000));
}

int main() {
    TestCBase c = TestCBase();
    c.run();
    return 0;
}