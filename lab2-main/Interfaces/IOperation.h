#pragma once
#include <list>
#include "../Context.h"
#include "../Exceptions/NoSuchOperation.h"
#include "../Exceptions/WrongInput.h"
#include "../Exceptions/NegativeParameter.h"
#include "../Exceptions/UndefParameter.h"
#include "../Exceptions/OutOfParameters.h"
#include "../Exceptions/WrongIdentifier.h"
#include "../Exceptions/WrongNumber.h"
#include "../Exceptions/InvalidRegister.h"
#include "../Exceptions/DivisionByZero.h"

#define OPERATION(T, NAME) static OperationMaker<T> maker(#NAME)

class IOperation {
public:
    virtual void execute(std::list<std::string> &arg, Context & ctx) const = 0;

    virtual ~IOperation() = default;
};
