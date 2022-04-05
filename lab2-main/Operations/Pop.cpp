#include "Pop.h"
#include "../Factory/OperationMaker.h"

OPERATION(Pop, POP);

void Pop::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.empty()) {
        throw OutOfParameters();
    }

    ctx.operands.pop();
}
