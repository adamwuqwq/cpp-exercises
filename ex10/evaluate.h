#ifndef EVALUATE_H
#define EVALUATE_H

#include <iostream>
#include <stack>
#include <sstream>

double evaluate(std::string expr)
{
    std::stack<double> num_stack;
    std::stack<std::string> op_stack;

    std::stringstream ss(expr);
    std::string token;

    while (getline(ss, token, ' '))
    {
        if (token == ")")
        {
            while (!op_stack.empty() && op_stack.top() != "(")
            {
                double num_2 = num_stack.top();
                num_stack.pop();
                double num_1 = num_stack.top();
                num_stack.pop();

                std::string op = op_stack.top();
                op_stack.pop();

                if (op == "+")
                    num_stack.push(num_1 + num_2);
                else if (op == "-")
                    num_stack.push(num_1 - num_2);
                else if (op == "*")
                    num_stack.push(num_1 * num_2);
                else if (op == "/")
                    num_stack.push(num_1 / num_2);
            }
            op_stack.pop();
        }
        else if (token == "(")
        {
            op_stack.push(token);
        }
        else if (token >= "0" && token <= "9")
        {
            num_stack.push(stod(token));
        }
        else
        {
            op_stack.push(token);
        }
    }
    return num_stack.top();
}
#endif