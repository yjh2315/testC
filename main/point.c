// #include <stdio.h>

// int main(void)
// {
//     int value = 0x000000FF;

//     int *pi = &value;
//     printf("%f\n", *pi);

//     short *ps = (short *)&value;
//     *(ps + 1) = 0x000F;
//     printf("%f ", *(ps));
//     printf("%f\n", *(ps+1));

//     return 0;
// }

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    union a
    {
        float a;
        int c;
        char b;
    } bite;
    bite.c = 10;
    bite.b = 'a';
    printf("%d %c", bite.c, bite.b);
}
