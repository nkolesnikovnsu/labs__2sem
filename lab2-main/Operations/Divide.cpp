#include "Divide.h"
#include "../Factory/OperationMaker.h"

OPERATION(Divide, /);

void Divide::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.size() < 2) {
        throw OutOfParameters();
    }

    std::pair<double, double> pair = ctx.readTwoElements();

    if (pair.second == 0) {
        throw DivisionByZero();
    }

    ctx.operands.push(pair.first / pair.second);
}
