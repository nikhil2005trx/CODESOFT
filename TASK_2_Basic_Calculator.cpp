#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Arithmetic operation functions
double add(double first, double second) {
    return first + second;
}

double sub(double first, double second) {
    return first - second;
}

double mul(double first, double second) {
    return first * second;
}

double divide(double first, double second) {
    if (second == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return first;
    }
    return first / second;
}

double mod(double first, double second) {
    if (second == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        return first;
    }
    return fmod(first, second);  // Using fmod for floating-point modulus
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double first) {
    if (first < 0) {
        cout << "Error: Cannot compute the square root of a negative number." << endl;
        return first;
    }
    return sqrt(first);
}

double reciprocal(double first) {
    if (first == 0) {
        cout << "Error: Cannot compute the reciprocal of zero." << endl;
        return first;
    }
    return 1 / first;
}

// Function to perform the operation based on user input
double performOperation(double first, char op, double second = 0) {
    switch (op) {
        case '+': return add(first, second);
        case '-': return sub(first, second);
        case '*': return mul(first, second);
        case '/': return divide(first, second);
        case '%': return mod(first, second);
        case '^': return power(first, second);
        default:
            cout << "Invalid operation. Please use +, -, *, /, %, ^." << endl;
            return first;
    }
}

int main() {
    cout << "------------------------- Basic Calculator -----------------------------" << endl;
    cout << "Available operations:" << endl;
    cout << "\033[1m Add (+), Subtract (-), Multiply (*), Divide (/), Modulus (%), Exponentiation (^) \033[0m" << endl;
    cout << "Enter 0 as the operation to exit." << endl;

    double first;
    cout << "Enter the first number: ";
    cin >> first;

    vector<double> results;
    char op;

    do {
        cout << "Enter an operation (+, -, *, /, %, ^) or 0 to exit: ";
        cin >> op;

        if (op == '0') 
            break;
        else {
            double second;
            cout << "Enter the second number: ";
            cin >> second;

            first = performOperation(first, op, second);
            results.push_back(first);
            cout << "Result: " << first << endl;
        }

    } while (op != '0');

    cout << "Session Results: ";
    for (double val : results) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Calculator session ended." << endl;

    return 0;
}
