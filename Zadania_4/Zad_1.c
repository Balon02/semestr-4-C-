#include <stdio.h>

int factorial(int x)
{
    int y = x;
    if (x == 1)
    {
       return y;
    }
    if (x > 1)
    {
        return y * factorial(x-1);
    }
}

int main() {
    int x = 6;
    printf("%d",factorial(x));

    char keepopen[999];
    scanf("%s", keepopen);
}