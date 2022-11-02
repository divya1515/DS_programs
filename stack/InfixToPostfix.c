#include <stdlib.h>
#include <stdio.h>
#define stacksize 20
#define true 1
#define false 0
struct stack
{
    int item[stacksize];
    int top;
};
struct stack s;
void Initialize()
{
    s.top = -1;
}
void push(int x)
{
    if (s.top == (stacksize - 1))
    {
        printf("Stack overflows");
        return;
    }
    s.top = s.top + 1;
    s.item[s.top] = x;
}
char pop()
{
    char x;
    if (s.top == -1)
    {
        printf("Stack underflows");
        return 0;
    }
    x = s.item[s.top];
    s.top = s.top - 1;
    return x;
}
int IsEmpty()
{
    if (s.top == -1)
    {
        return 1;
    }
    else
        return 0;
}
char StackTop()
{
    char x = s.item[s.top];
    return x;
}
int precd(char a, char b)
{
    if (a == '(' || b == '(')
        return 0;
    if (a != '(' && b == ')')
        return 1;
    else if (a == '(' && b == ')')
        return 0;
    else if (a == '^' || a == '*' || a == '%' || a == '/')
    {
        if (b == '^')
            return 0;
        else
            return 1;
    }
    else
    {
        if (b == '+' || b == '-')
            return 1;
        else
            return 0;
    }
}
void infixtopostfix(char infix[])
{
    int i = 0;
    int p = 0;
    char postfixexp[20];
    char symbol, x, y;
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (symbol >= 'a' && symbol <= 'z')
        {
            postfixexp[p] = symbol;
            p++;
        }
        else
        {
            while (!IsEmpty() && precd(StackTop(), symbol))
            {
                x = pop();

                postfixexp[p] = x;
                p++;
            }
            if (symbol != ')')
            {
                push(symbol);
            }
            else
                pop();
        }
        i++;
    }
    while (!IsEmpty())
    {
        y = pop();
        postfixexp[p] = y;
        p++;
    }
    postfixexp[p] = '\0';

    printf("%s", postfixexp);
}

int main()
{
    Initialize();
    char infix[20];
    scanf("%s", infix);
    infixtopostfix(infix);
}
