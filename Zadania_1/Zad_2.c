#include <stdio.h>

int main() 
{
    int grades[2][5] = {
        {5, 4, 5, 3, 2}, 
        {3, 2, 4, 5, 5}  
    };
    double mathavg = 0, physavg = 0;
    for (int i = 0; i < 5; i++) {
        mathavg += grades[0][i];
        physavg += grades[1][i];
    }
    mathavg /= 5;
    physavg /= 5;

    printf("srednia ocen z matematyki: %.2f\n", mathavg);
    printf("srednia ocen z fizyki: %.2f\n", physavg);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}
