#include "Define.h"
#include "../Factory/OperationMaker.h"

OPERATION(Define, DEFINE);

void Define::execute(std::list<std::string> &args, Context &ctx) const {
    if (args.size() < 2) {
        throw WrongInput();
    }

    std::string id = args.front();
    std::string numberToDefine = args.back();

    bool wrongId = true;
    for (char i : id) {
        if (isdigit(i)) {
            wrongId = false;
            break;
        }
    }

    if (!wrongId) {
        throw WrongIdentifier();
    }

    try {
        ctx.defines[id] = stof(numberToDefine);
    } catch (std::invalid_argument &ex) {
        throw WrongNumber();
    }
}
