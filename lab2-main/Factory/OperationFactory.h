#pragma once
#include "../Interfaces/IOperation.h"
#include "../Interfaces/IOperationMaker.h"

class OperationFactory {
public:
    static OperationFactory &getInstance() noexcept;
    IOperation *createInstance(const std::string&) const;
    void RegisterMaker(const std::string &, IOperationMaker*);
private:
    OperationFactory() = default;
    std::map<std::string, IOperationMaker *> makers;

    OperationFactory(OperationFactory& other) = delete;
    void operator=(OperationFactory&) = delete;
};

