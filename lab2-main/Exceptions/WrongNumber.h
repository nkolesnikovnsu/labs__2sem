#pragma once
#include "EvaluatorException.h"

class WrongNumber : public EvaluatorException {
public:
    WrongNumber() : EvaluatorException("Wrong number format!"){};
};