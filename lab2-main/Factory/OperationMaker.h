#pragma once
#include "../Interfaces/IOperationMaker.h"
#include "OperationFactory.h"

template <typename T>

class OperationMaker : public IOperationMaker{
public:
    explicit OperationMaker(const std::string &opName){
        OperationFactory::getInstance().RegisterMaker(opName, this);
    }
    IOperation *create(const std::string &opName) const override {
        return new T;
    }
};
