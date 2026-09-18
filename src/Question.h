#pragma once

#include <array>
#include <cstddef>
#include <string>


struct Question {
    std::string text;
    std::array<std::string, 4> options;
    char correctAnswer;  


    static char label(std::size_t index) {
        return static_cast<char>('A' + index);
    }
};