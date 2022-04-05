#pragma once
#include <stack>
#include <map>

struct Context {
    std::stack <double> operands;
    std::map <std::string, double> defines;
public:
    double readElement() {
        double tmp = operands.top();
        operands.pop();
        return tmp;
    }

    std::pair <double, double> readTwoElements() {
        double first = operands.top();
        operands.pop();
        double second = operands.top();
        operands.pop();

        return {first, second};
    }
};

