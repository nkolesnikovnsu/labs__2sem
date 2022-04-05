#include "Sqrt.h"
#include "../Factory/OperationMaker.h"

OPERATION(Sqrt, SQRT);

void Sqrt::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.empty()) {
        throw OutOfParameters();
    }

    double elem = ctx.readElement();

    if (elem < 0) {
        throw NegativeParameter();
    }

    ctx.operands.push(sqrt(elem));
}
