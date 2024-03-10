#include <stdio.h>
struct stack
{
    char a[20];
    int top;
} s;
void push(char ele)
{
    s.a[++s.top] = ele;
}

char pop()
{
    return (s.a[s.top--]);
}

int prcd(char op1, char op2)
{
    switch (op1)
    {
    case '$':
        if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')')
        {
            return 1;
        }
    case '*':
    case '/':
        if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')')
        {
            return 1;
        }
    case '-':
    case '+':
        if (op2 == '+' || op2 == '-' || op2 == ')')
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char expr[20], postfix[20], symb, topsymb;
    int i, k = 0;
    s.top = -1;
    printf("Enter the expression: ");
    scanf("%s", expr);
    for (i = 0; expr[i] != '\0'; i++)
    {
        symb = expr[i];
        if (symb >= 'A' && symb <= 'Z' || (symb >= 'a' && symb <= 'z'))
        {
            postfix[k++] = symb;
        }
        else
        {
            while (s.top != -1 && (prcd(s.a[s.top], symb)))
            {
                topsymb = pop();
                postfix[k++] = topsymb;
            }

            if (s.top == -1 || symb != ')')
            {
                push(symb);
            }
            else
            {
                topsymb = pop(); // no usage again
            }
        }
    }

    while (s.top != -1)
    {
        topsymb = pop();
        postfix[k++] = topsymb;
    }

    postfix[k] = '\0';
    printf("postfix is %s", postfix);
    return 0;
}