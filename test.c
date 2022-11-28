#include<stdio.h>

int main(void)
{
    int i, j, minimum, temp, n = 10, b;
    int a[n];

    for (b=0; b<n; b++) {/*putting numbers in an array*/
        scanf("%d", &a[b]);
    }

    for (i = 0; i < n-1; i++) /*selection sort algorithm*/
    {
        printf("a[i] = %d\n", a[i]);
        minimum = i;
        for(j = i + 1; j < i; j++) /*finding the minimum*/
        {
            if (a[j] < a[i])
                minimum=j;
        }
        if (minimum != i)
        {
            printf("j =%d\n", j);
            temp = a[i]; /*Swapping numbers*/
            a[i]=a[minimum];
            a[minimum]=temp;
        }
    }

    for (i=0; i < n ; i++)
        printf("%d ", a[i]);

return 0;
}
