#include <iostream>
#include "stack.cpp"
#include <String>
#include <ctype.h> // for isdigit()

using namespace std;

bool CheckBracketsConsistency(const string &str);
string ExpressionToPostfix(const string &exp); 
double EvaluateExpression(const string &exp);
bool CheckExpressionConsistency(const string &str);

int main()
{   
    Stack<int>* intStack = new Stack<int>(3);
    
    intStack->Push(1); // 1 3
    intStack->Push(5); // 5 1 3
    intStack->Push(9); // 9 5 1 3
    intStack->Push(4); // 4 9 5 1 3
    intStack->Pop(); // 9 5 1 3
    intStack->Pop(); // 5 1 3
    intStack->Print();

    cout << "Empty: " << intStack->IsEmpty() << endl;
    cout << "Top: " << intStack->GetTop() << endl << endl;

    delete intStack;
//__________________________________________________________________________________________________________

    bool isConsistent = CheckBracketsConsistency("{Hello{10}(a((s(s[(Hey)])dfgh))gfd)[ddd]World}");
    if(isConsistent)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl << endl;
    }
//__________________________________________________________________________________________________________

    string exp1 = ExpressionToPostfix("2*(8+1)"); // 281+*
    cout << exp1 << endl;
    string exp2 = ExpressionToPostfix("2*8+1"); // 28*1+
    cout << exp2 << endl;
    string exp3 = ExpressionToPostfix("((2+2)*2)*(1+1)*2"); // 22+2*11+2**
    cout << exp3 << endl;
    string exp4 = ExpressionToPostfix("3-2*3"); //323*-
    cout << exp4 << endl << endl;

    double d1 = EvaluateExpression(exp1); // 281+* = 18
    cout << d1 << endl;
    double d2 = EvaluateExpression(exp2); // 28*1+ = 17
    cout << d2 << endl;
    double d3 = EvaluateExpression(exp3); // 22+2*11+2** = 32
    cout << d3 << endl;
    double d4 = EvaluateExpression(exp4); // 323*- = -3
    cout << d4 << endl;


    return 0;
}

bool CheckBracketsConsistency(const string &str)
{
    Stack<char>* stack = new Stack<char>();

    for(int i = 0; i < str.length(); ++i)
    {
        // When open bracket - add to stack
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack->Push(str[i]);
            continue;
        }
        // When close bracket - take top element from Stack and check is it from same type
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(stack->IsEmpty())
            { 
                delete stack;
                return false; 
            }
            switch (str[i])
            {
            case ')':
                if(stack->GetTop() == '(')
                {
                    stack->Pop();
                    break;
                }
                else 
                { 
                    delete stack;
                    return false; 
                }

            case '}':
                if(stack->GetTop() == '{')
                {
                    stack->Pop();
                    break;
                }
                else 
                { 
                    delete stack;
                    return false; 
                }

            case ']':
                if(stack->GetTop() == '[')
                {
                    stack->Pop();
                    break;
                }
                else 
                { 
                    delete stack;
                    return false; 
                }

            default:
                break;
            }
        }
    }
    
    // When some brackets are still in Stack - not consistent 
    if (stack->IsEmpty())
    {
        delete stack;
        return true;
    }
    else
    {
        delete stack;
        return false;
    }
}

string ExpressionToPostfix(const string &exp)
{
    if(exp == "") {return "";}
    if(CheckBracketsConsistency(exp) == false) { return ""; }
    // Check for expression consistency - operators amount should be one less than operands amount
    if(CheckExpressionConsistency(exp) == false) { return ""; }

    Stack<char>* symbols = new Stack<char>();
    string res = "";

    for(int i = 0; i < exp.length(); ++i)
    {
        if(isdigit(exp[i]))
        {
            res += exp[i]; // potential place for improve because each operation copy full string and add new character for O(N) where N - length of string
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '(')
        {
            if((exp[i] == '+' || exp[i] == '-') && (symbols->GetTop() == '*' || symbols->GetTop() == '/'))
            {
                // '*' and '/' are dominant operators - add allof them to resu string
                while(symbols->GetTop() == '*' || symbols->GetTop() == '/')
                {
                    res += symbols->GetTop();
                    symbols->Pop();
                }
            }
            symbols->Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while(symbols->GetTop() != '(')
            {
                char c = symbols->GetTop();
                symbols->Pop();
                res += c; // potential place for improve because each operation copy full string and add new character for O(N) where N - length of string
            }
            // Pop '('
            symbols->Pop();
        }
    }

    // Add all symbols from stack to res
    while(symbols->IsEmpty() == false)
    {
        res += symbols->GetTop();
        symbols->Pop();
    }

    delete symbols;
    return res;
}

double EvaluateExpression(const string &exp)
{
    if(exp == "") {return 0;}
    // Check for expression consistency - operators amount should be one less than operands amount
    if(CheckExpressionConsistency(exp) == false) { return 0; }

    Stack<double>* numbers = new Stack<double>();
    double res = 0;

    // Go through string and add all digits to stack. Once face operator -pop last 2 digits and result of calculation push back to stack
    for(int i = 0; i < exp.length(); ++i)
    {
        if(isdigit(exp[i]))
        {
            numbers->Push(exp[i] - 48); // exp[i] return ascii code; 0 - 48,..., 9 - 57. If we need number 9: 57 - 48 = 9
        }
        else if (exp[i] == '+'|| exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            double second = numbers->GetTop();
            numbers->Pop();
            double first = numbers->GetTop();
            numbers->Pop();

            if(exp[i] == '+'){ res = first + second; }
            else if(exp[i] == '-'){ res = first - second; }
            else if(exp[i] == '*'){ res = first * second; }
            else if(exp[i] == '/'){ res = first / second; }

            numbers->Push(res);
        }
    }

    res = numbers->GetTop();
    delete numbers;
    return res;
}

bool CheckExpressionConsistency(const string &str)
{
    //Check for expression consistency - operators amount should be one less than operands amount
    int operators = 0;
    int digits = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if(isdigit(str[i]))
        {
            ++digits;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            ++operators;
        }
    }

    return operators == digits - 1 ? true : false;
}