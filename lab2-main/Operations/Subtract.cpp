#include "Subtract.h"
#include "../Factory/OperationMaker.h"

OPERATION(Subtract, -);

void Subtract::execute(std::list<std::string>& args, Context & ctx) const {
    if (ctx.operands.size() < 2) {
        throw OutOfParameters();
    }

    std::pair<double, double> pair = ctx.readTwoElements();
    ctx.operands.push(pair.first - pair.second);
}