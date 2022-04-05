#include "Push.h"
#include "../Factory/OperationMaker.h"

OPERATION(Push, PUSH);

void Push::execute(std::list<std::string> &args, Context &ctx) const {
    if (args.empty()) {
        throw WrongInput();
    }
    std::string number = args.front();

    try {
        ctx.operands.push(stof(number));
    } catch (std::invalid_argument &ex) {
        if (ctx.defines.find(number) != ctx.defines.end())
            ctx.operands.push(ctx.defines[number]);
        else
            throw WrongNumber();
    }
}
