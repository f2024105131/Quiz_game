#include <cctype>
#include <iostream>
#include <string>

#include "QuestionBank.h"
#include "Quiz.h"

namespace {

void printBanner() {
    std::cout << "\n";
    std::cout << "================================\n";
    std::cout << "          C++ QUIZ GAME\n";
    std::cout << "================================\n";
}

void printResult(const QuizResult& r) {
    std::cout << "\n";
    std::cout << "================================\n";
    std::cout << "          QUIZ RESULT\n";
    std::cout << "================================\n\n";
    std::cout << "Correct Answers : " << r.correct << "\n";
    std::cout << "Wrong Answers   : " << r.wrong() << "\n";
    std::cout << "Final Score     : " << r.percent() << "%\n\n";
    std::cout << r.grade() << "\n";
    std::cout << "================================\n";
}

bool askPlayAgain() {
    while (true) {
        std::cout << "\nPlay again? (Y/N): ";

        std::string input;
        if (!std::getline(std::cin, input)) {
            return false;
        }

        for (char c : input) {
            if (std::isspace(static_cast<unsigned char>(c))) continue;

            const char up = static_cast<char>(
                std::toupper(static_cast<unsigned char>(c)));

            if (up == 'Y') return true;
            if (up == 'N') return false;
            break;
        }

        std::cout << "Please enter Y or N.\n";
    }
}

}  // namespace

int main() {
    QuestionBank bank;

    printBanner();

    while (true) {
        Quiz quiz(bank.all());
        const QuizResult result = quiz.run();

        printResult(result);

        if (!askPlayAgain()) break;

        printBanner();
    }

    std::cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}