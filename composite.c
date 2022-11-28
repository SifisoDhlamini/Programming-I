#include<stdio.h>

int parser(char *expr, int *n)
{
    while(expr[*n] == ',' || expr[*n] == '(' || expr[*n] == ')')
        (*n) ++;
    if(expr[*n] == 'F')
    {
        (*n) ++;
        return parser(expr, n) + 1;
    }
    else if(expr[*n] == 'G')
    {
        (*n) ++;
        return parser(expr, n) + parser(expr, n);
    }
    else
    {
        int temp = 0;
        while(expr[*n] >= '0' && expr[*n] <= '9')
        {
            temp = temp * 10 + expr[*n] - '0';
            (*n) ++;
        }
        return temp;
    }
}

int main()
{
    int n = 0;
    char input[10000];
    gets(input);
    printf("%d", parser(input, &n));
}
