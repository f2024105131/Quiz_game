#include "Quiz.h"

#include <cctype>
#include <iostream>
#include <string>

namespace {

char toUpper(char c) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

// Returns the first non-whitespace character of a string, or '\0' if none.
char firstMeaningfulChar(const std::string& s) {
    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            return toUpper(c);
        }
    }
    return '\0';
}

}  // namespace

Quiz::Quiz(const std::vector<Question>& questions)
    : questions_(questions) {}

void Quiz::printQuestion(std::size_t index) const {
    const Question& q = questions_[index];

    std::cout << "\nQuestion " << (index + 1) << "/" << questions_.size() << "\n\n";
    std::cout << q.text << "\n\n";

    for (std::size_t i = 0; i < q.options.size(); ++i) {
        std::cout << Question::label(i) << ". " << q.options[i] << "\n";
    }
    std::cout << "\n";
}

char Quiz::askAnswer() const {
    while (true) {
        std::cout << "Your answer: ";

        std::string input;
        if (!std::getline(std::cin, input)) {
            // EOF or stream failure — return something safe.
            return 'A';
        }

        const char c = firstMeaningfulChar(input);
        if (c == 'A' || c == 'B' || c == 'C' || c == 'D') {
            return c;
        }

        std::cout << "Invalid input. Please enter A, B, C, or D.\n";
    }
}

QuizResult Quiz::run() {
    QuizResult result;
    result.total = static_cast<int>(questions_.size());

    for (std::size_t i = 0; i < questions_.size(); ++i) {
        printQuestion(i);

        const char answer = askAnswer();
        const bool correct = (answer == questions_[i].correctAnswer);

        if (correct) {
            std::cout << "\n+ Correct!\n";
            ++result.correct;
        } else {
            std::cout << "\n- Incorrect. The correct answer was "
                      << questions_[i].correctAnswer << ".\n";
        }

        std::cout << "Score: " << result.correct << "/" << (i + 1) << "\n";
    }

    return result;
}