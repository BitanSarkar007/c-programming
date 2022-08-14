#include<stdio.h>
#include<stdlib.h>
void sumAndAvg(int a, int b, int *sum, float *avg)
{
    *sum = a+b;
    *avg = (float)*sum/2;
}
int main()
{
    int a,b, sum;
    float avg;
    a =3;
    b =6;
    sumAndAvg(a,b, &sum, &avg);
    printf("The value of sum is: %d\n", sum);
    printf("The value of avg is: %f\n", avg);
    return 0;
}