#include <stdio.h>
#include <stdlib.h>

int main()
{
    int physics, chemistry, maths;
    printf("Enter Physics marks: \n");
    scanf("%d", &physics);
    printf("Enter Chemistry marks: \n");
    scanf("%d", &chemistry);
    printf("Enter Maths marks: \n");
    scanf("%d", &maths);
    float total = (physics + maths + chemistry) / 3;
    if (total < 40 || physics < 33 || maths < 33 || chemistry < 33)
        printf("Your total marks is %f and you have failed\n", total);
    else
        printf("Your total marks is %f and you have passed\n", total);

    return 0;
}