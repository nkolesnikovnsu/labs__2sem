#pragma once
#include "EvaluatorException.h"

class WrongIdentifier : public EvaluatorException {
public:
    WrongIdentifier() : EvaluatorException("Wrong identifier format!"){};
};