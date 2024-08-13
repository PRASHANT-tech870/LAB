#include <stdio.h>
#include <math.h>
struct stack
{
    int a[20];
    int top;
} s;

void push(int ele)
{
    s.a[++s.top] = ele;
}
int pop()
{
    return (s.a[s.top--]);
}

int compute(int opnd1, char symb, int opnd2)
{
    switch (symb)
    {
    case '*':
        return (opnd1 * opnd2);
    case '+':
        return (opnd1 + opnd2);
    case '-':
        return (opnd1 - opnd2);
    case '/':
        return (opnd1 / opnd2);
    case '$':
        return (pow(opnd1, opnd2));
    }
}
int main()
{
    char expr[20], symb;
    int opnd1, opnd2, value, i = 0;
    s.top = -1;
    printf("Enter the expession: ");

    scanf("%s", expr);

    while (expr[i] != '\0')
    {
        i++;
    }
    for (--i; i >= 0; i--)
    {
        symb = expr[i];
        if (symb >= '0' && symb <= '9')
        {
            push(symb - '0');
        }
        else
        {
            opnd1 = pop();
            opnd2 = pop();
            value = compute(opnd1, symb, opnd2);
            push(value);
        }
    }
    printf("result %d", pop());
}
