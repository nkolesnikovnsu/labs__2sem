#include "StackCalculator.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream fin(argv[1]);
        if (!fin) {
            std::cerr << "No such file!" << std::endl;
            StackCalculator::evaluate(std::cin);
        }
        else
            StackCalculator::evaluate(fin);
    }

    StackCalculator::evaluate(std::cin);
    return 0;
}