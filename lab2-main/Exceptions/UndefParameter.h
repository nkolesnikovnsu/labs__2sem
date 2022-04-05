#pragma once
#include "EvaluatorException.h"

class UndefParameter : public EvaluatorException {
public:
    UndefParameter() : EvaluatorException("Undefined parameter!"){};
};