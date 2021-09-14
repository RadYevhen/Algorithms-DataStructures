#include <iostream>
#include "stack.cpp"
#include <String>

using namespace std;

bool CheckBracketsConsistency(const string &str);

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

    bool isConsistent = CheckBracketsConsistency("{Hello{10}(a((s(s[(Hey)])dfgh))gfd)[ddd]World}");
    if(isConsistent)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

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
