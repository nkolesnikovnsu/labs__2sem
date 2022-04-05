cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp Exceptions/EvaluatorException.h Exceptions/OutOfParameters.h Exceptions/DivisionByZero.h StackCalculator.cpp StackCalculator.h Context.h Exceptions/InvalidRegister.h Exceptions/WrongInput.h Exceptions/WrongIdentifier.h Exceptions/WrongNumber.h Exceptions/NoSuchOperation.h Exceptions/UndefParameter.h Exceptions/NegativeParameter.h Interfaces/IOperation.h Interfaces/IOperationMaker.h Factory/OperationFactory.cpp Factory/OperationFactory.h Factory/OperationMaker.h Operations/Add.cpp Operations/Add.h Operations/Define.cpp Operations/Define.h Operations/Push.cpp Operations/Push.h Operations/Sqrt.cpp Operations/Sqrt.h Operations/Print.cpp Operations/Print.h Operations/Pop.cpp Operations/Pop.h Operations/Divide.cpp Operations/Divide.h Operations/Multiply.cpp Operations/Multiply.h Operations/Subtract.cpp Operations/Subtract.h)