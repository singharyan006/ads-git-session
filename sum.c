#include <stdio.h>

void multiply_by_two(int *num)
{
    *num = (*num) * 2;
    printf("%d\n", *num);
}
int main()
{
    int a = 4;
    int b = 5;
    int c = 9;
    int d = 10;
    int e = 11;
    int sum = a + b + c + d + e;
    printf("%d\n", sum);
    multiply_by_two(&sum);
}
