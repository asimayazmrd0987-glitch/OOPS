#include <stdio.h>

int main()
{
    int a, b;
    int q, r;
    printf("Enter numerator :");
    scanf("%d", &a);
    printf("Enter denominator :");
    scanf("%d", &b);
    q = a / b;
    r = a - b / q;

    printf("The answer is %d", r);
    return 0;
}