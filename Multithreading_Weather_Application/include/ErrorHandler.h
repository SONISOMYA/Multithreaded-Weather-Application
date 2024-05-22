// ErrorHandler.h
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <iostream>
#include <exception>
#include <string>

// Class for handling errors and exceptions
class ErrorHandler {
public:
    // Static method to print error messages
    static void printError(const string& errorMessage) {
        cerr << "Error: " << errorMessage << endl;
    }

    // Static method to print exception messages
    static void printException(const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
};

#endif // ERROR_HANDLER_H
