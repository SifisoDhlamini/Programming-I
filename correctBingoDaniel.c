#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkLine (int array[][5], int card)
{
    int sumv, sumh, sumd;
    int n;
    n = card * 5;
    sumv = 0;
    sumh =0;
    for(int i = n; i < 5+n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            sumh = sumh + array[i][j];
            if(sumh == 250)
            {
                return 1;
            }
        }
        sumh = 0;
    }
    for(int j = 0; j < 5; j++)
    {
        for(int i = n; i < 5+n; i++)
        {
            sumv = sumv + array [i][j];
            if(sumv == 250)
            {
                return 1;
            }
        }
        sumv = 0;
    }
    sumd = 0;
    for(int i = n, j = 0; i < n+5; i++, j++)
    {
        sumd = sumd + array[i][j];
        if (sumd == 250)
        {
            return 1;
        }
    }
    sumd = 0;
    for(int i = n, j = 4; i < n+5; i++, j--)
    {
        sumd = sumd + array[i][j];
        if (sumd == 250)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    //card number
    int cardn;
    scanf ("%d", &cardn);

    //scan all bingo cards into an array
    int bingoend = cardn * 5;
    int array[bingoend][5];

    for(int i = 0; i < bingoend; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", &array[i][j]);
            //printf ("%d", array[i][j]);
        }
    }

    //scan bingo number order
    int bingonumbers[25];
    for(int i = 0; i < 25; i++)
    {
        scanf ("%d", &bingonumbers[i]);
    }

    //bingo player array
    int player[2][cardn];
    //set 0s
    for(int i = 0; i < cardn; i++)
    {
        player[1][i] = 0;
    }
    //set card number
    for(int i = 0; i < cardn; i++)
    {
        player[0][i] = i+1;
    }

    //replace with 50
    int currentn;
    for(int k = 0; k < 25; k++)
    {
        currentn = bingonumbers[k];
        for(int i = 0; i < bingoend; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if (array[i][j] == currentn)
                {
                    array[i][j] = 50;
                }
            }
        }
        for(int l = 0; l <= cardn; l++)
        {
            if(checkLine(array, l) == 1)
            {
                for(int c = 0; c <= cardn; c++)
                {
                    if (player[0][c] == l+1 && player[1][c] == 0)
                    {
                        player [1][c] = k+1;
                        //printf ("ok");
                    }
                }
            }
        }
    }
    int temp;
    for(int i = 5;i < 25;i ++)
    {
        temp = 0;
        for(int j = 0;j < cardn;j ++)
        {
            if(player[1][j] == i)
            {
                if(temp == 0)
                {
                    printf("%d:", i);
                    temp = 1;
                }
                printf(" %d", player[0][j]);
            }
        }
        if(temp == 1)
        {
            printf("\n");
        }
    }
}
