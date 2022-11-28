#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int calculate(int n1, char op, int n2){
  int answer;
  switch (op){
    case '+':
        answer = n1 + n2;
        break;
    case '-':
        answer = n1 - n2;
        break;
    case '*':
        answer = n1 * n2;
        break;
    case '/':
        answer = n1 / n2;
        break;
  }
  return answer;
}

int main(){
    char expression[100];
    int numbers[100];
    int num = 0;
    int chars = 0;
    int count = 0;
    do{
        if(count == 0 || count % 2 == 0){
            scanf("%d", &numbers[num]);
            num++;
        } else {
            scanf("%c", &expression[chars]);
            chars++;
        }
        count++;
    }while(getchar() == 32);

    int result = 0;

    //if something was entered
    if (num > 0)
        result = numbers[0];

    //if more than 1 digit was entered + an operand
    if(num >= 2){
        char operand;
        for (int i = 1; i < num; i++){
            operand = expression[i - 1];
            result = calculate(result, operand, numbers[i]);
        }
    }

    printf("%d", result);

    return 0;
}
