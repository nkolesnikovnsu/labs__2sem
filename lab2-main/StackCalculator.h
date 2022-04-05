#pragma once
#include <fstream>
#include <iostream>
#include <list>
#include "Context.h"
#include "Factory/OperationFactory.h"
#include "Factory/OperationMaker.h"
#include "Interfaces/IOperationMaker.h"
#include "Interfaces/IOperation.h"

class StackCalculator {
public:
    static double evaluate(std::istream& is);
};