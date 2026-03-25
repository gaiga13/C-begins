#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1;
    float num2;
    printf("enter first number: ");
    scanf("%f",&num1);
    printf("enter second number: ");
    scanf("%f",&num2);
    printf("inter the operator:");
    char sym;
    scanf(" %c", &sym);
    float ans;
    switch(sym)
   {
    case'+':
        ans= num1+num2;
        break;
    case'-':
        ans= num1-num2;
        break;

    case'*':
        ans=num1*num2;
        break;
    case'/':
        ans=num1/num2;
        break;
    default:
    printf("sorry, the operation is invalid!");
    return 0;
    }
    printf("answer is: %f", ans);
    return 0;

}

