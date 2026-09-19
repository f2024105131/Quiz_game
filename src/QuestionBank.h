#pragma once

#include <string>
#include <vector>

#include "Question.h"


class QuestionBank {
public:
    QuestionBank();

    const std::vector<Question>& all() const;

    std::vector<Question> shuffled() const;

    std::size_t size() const;

private:
    std::vector<Question> questions_;
};