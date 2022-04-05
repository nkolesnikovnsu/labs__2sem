#pragma once
#include <exception>
#include <string>

class EvaluatorException : public std::exception {
protected:
    const char* message = "Something went wrong!";
public:
    explicit EvaluatorException(const char* message_) {
        message = message_;
    }
    const char* what() const noexcept override {
        return message;
    }
};
