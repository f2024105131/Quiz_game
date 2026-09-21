#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Question.h"

// Result of one completed quiz session.
struct QuizResult {
    int correct = 0;
    int total   = 0;

    int wrong() const { return total - correct; }

    int percent() const {
        return total > 0 ? (correct * 100) / total : 0;
    }

    std::string grade() const {
        const int p = percent();
        if (p >= 80) return "Excellent work!";
        if (p >= 60) return "Good job!";
        if (p >= 40) return "Keep practicing!";
        return "You need more practice.";
    }
};


class Quiz {
public:
    explicit Quiz(const std::vector<Question>& questions);

    // Play one full session, return the result.
    QuizResult run();

private:
    const std::vector<Question>& questions_;

    void printQuestion(std::size_t index) const;
    char askAnswer() const;
};