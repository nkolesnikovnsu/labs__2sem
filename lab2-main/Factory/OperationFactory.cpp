#include "OperationFactory.h"

OperationFactory& OperationFactory::getInstance() noexcept {
    static OperationFactory factory;
    return factory;
}

IOperation* OperationFactory::createInstance(const std::string& id) const {
    auto i = makers.find(id);
    if (i == makers.end()) {
        throw NoSuchOperation();
    }
    IOperationMaker *maker = i->second;
    return (maker -> create(id));
}

void OperationFactory::RegisterMaker(const std::string &operationName, IOperationMaker *maker) {
    if (makers.find(operationName) != makers.end()) {
        throw InvalidRegister();
    }
    makers[operationName] = maker;
}


