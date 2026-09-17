# C++ Quiz Game

A terminal-based multiple-choice quiz game written in modern C++17.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)

## Features (v1)

- 10 C++ questions with 4 options each
- Case-insensitive A/B/C/D input with validation
- Live score feedback after every question
- Final percentage + performance grade
- Replay loop

## Requirements

- A C++17-capable compiler (`g++`, `clang++`, or MSVC 2017+)
- `make` (optional — manual build commands below)

## Build & Run

### With `make`

```bash
make        # compile
make run    # compile and run
make clean  # remove build artifacts
```

### Manually

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic src/*.cpp -o build/quiz
./build/quiz
```

## Project Layout

```
cpp-quiz-game/
├── src/
│   ├── main.cpp            # Entry point + game loop
│   ├── Quiz.h / .cpp       # Session runner + scoring
│   ├── Question.h          # Question struct
│   └── QuestionBank.h/.cpp # Question storage
├── data/                   # Question data (v3+)
├── docs/                   # Screenshots, docs
├── build/                  # Compiled binaries (gitignored)
├── Makefile
├── LICENSE
└── README.md
```

## Roadmap

- [x] **v1** — Basic quiz (10 questions, scoring, replay)
- [ ] **v2** — Randomize order, shuffle options, difficulty levels, score history
- [ ] **v3** — Load questions from `data/questions.txt`
- [ ] **v4** — Unit tests (Catch2), CMake, CI

## License

MIT — see [LICENSE](LICENSE).