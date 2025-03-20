/**
 * TestCBase.hpp - test header
 * 2025-03-20
 * vika <https://github.com/hi-im-vika>
 */

#pragma once

#include <iostream>

#include "../include/CBase.hpp"

class TestCBase : public CBase {
private:
    std::string _text;
    uint _count;

public:
    TestCBase();
    ~TestCBase();

    void update() override;
    void draw() override;
};