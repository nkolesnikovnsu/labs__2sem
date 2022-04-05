#include "Multiply.h"
#include "../Factory/OperationMaker.h"

OPERATION(Multiply, *);


void Multiply::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.size() < 2) {
        throw OutOfParameters();
    }

    std::pair<double, double> pair = ctx.readTwoElements();
    ctx.operands.push(pair.first * pair.second);
}
