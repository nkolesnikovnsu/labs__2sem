#pragma once
#include "EvaluatorException.h"

class InvalidRegister : public EvaluatorException {
public:
    InvalidRegister() : EvaluatorException("Invalid register!"){};
};