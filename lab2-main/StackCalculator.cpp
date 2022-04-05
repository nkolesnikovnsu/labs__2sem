#include "StackCalculator.h"
#include <memory>

void splitString(std::list <std::string>&, const std::string&);
bool readNextString(std::istream& is, std::list <std::string>& args);

double StackCalculator::evaluate(std::istream& is) {
    Context ctx;

    int stringCounter = 1;
    std::list <std::string> arguments;

    while (readNextString(is, arguments)) {
        try {
            char symbol = arguments.front()[0];
            auto comment = [symbol]() -> bool {
                return symbol == '#';
            }();
            if (comment) {
                continue;
            }

            std::unique_ptr<IOperation> op (OperationFactory::getInstance().createInstance(arguments.front()));
            arguments.pop_front();
            op -> execute(arguments, ctx);

        } catch (EvaluatorException& ex) {
            std::cout << ex.what() << " Command " << stringCounter << std::endl;
            arguments.clear();
            stringCounter++;
            continue;
        }

        arguments.clear();
        stringCounter++;
    }
    return ctx.operands.top();
}

bool readNextString(std::istream& is, std::list <std::string> &args) {
    std::string curString;
    if (!getline(is, curString)) {
        return false;
    }

    splitString(args, curString);
    return true;
}

void splitString(std::list<std::string> &args, const std::string& line) {
    int delimiter = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' && i > delimiter) {
            args.push_back(line.substr(delimiter, i - delimiter));
            delimiter = i + 1;
        }
    }

    if (line.size() - delimiter > 0) {
        args.push_back(line.substr(delimiter));
    }
}