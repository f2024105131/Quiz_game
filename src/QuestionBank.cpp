#include "QuestionBank.h"

#include <algorithm>
#include <random>

QuestionBank::QuestionBank() {
    questions_ = {
        { "Which keyword is used to create a class?",
          {"object", "class", "function", "struct"}, 'B' },

        { "Which symbol is used to end a statement in C++?",
          {".", ":", ";", ","}, 'C' },

        { "Which of these is NOT a C++ fundamental type?",
          {"int", "float", "double", "real"}, 'D' },

        { "What is the correct way to declare a variable?",
          {"int x = 5;", "x int = 5;", "declare x = 5;", "variable int x;"}, 'A' },

        { "Which object is used for output in C++?",
          {"cin", "cout", "print", "output"}, 'B' },

        { "Which header file is needed for input/output?",
          {"<stdio.h>", "<string>", "<iostream>", "<vector>"}, 'C' },

        { "What does 'endl' do?",
          {"Ends the program", "Ends the line", "Ends a loop", "Deletes a variable"}, 'B' },

        { "Which loop is guaranteed to run at least once?",
          {"for", "while", "do-while", "foreach"}, 'C' },

        { "Which keyword makes a class member accessible outside the class?",
          {"inherits", "extends", "public", "using"}, 'C' },

        { "Which of these is the entry point of a C++ program?",
          {"start()", "begin()", "main()", "run()"}, 'C' }
    };
}

const std::vector<Question>& QuestionBank::all() const {
    return questions_;
}

std::vector<Question> QuestionBank::shuffled() const {
    std::vector<Question> copy = questions_;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(copy.begin(), copy.end(), rng);

    return copy;
}

std::size_t QuestionBank::size() const {
    return questions_.size();
}