#include<stdio.h>

int merge(int *a, int *b, int *c);

int main(){
    int a[] = {5, 3, 9, 1, 2};
    int b[] = {6, 10, 8, 4, 7};
    int c[10];

    for (int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", b[i]);
    }
    printf("\n");

    *c = merge(a, b, c);

    for (int i = 0; i < 10; i++){
        printf("%d ", c[i]);
    }

    return 0;
}

int merge(int *a, int *b, int *c)
{
    int numAB = 5;
    int numC = 10;
    int temp;
    int indexA = 0;
    int indexB = 0;
    int indexC = 0;

    //sort a
    for (int i = 0; i < numAB - 1; i++){
        for (int j = i + 1; j < numAB; j++){
            if(*(a+j) < *(a+i)){
                temp = *(a+j);
                *(a+j) = *(a+i);
                *(a+i) = temp;
            }
        }
    }

    //sort b
    for (int i = 0; i < numAB - 1; i++){
        for (int j = i + 1; j < numAB; j++){
            if(*(b+j) < *(b+i)){
                temp = *(b+j);
                *(b+j) = *(b+i);
                *(b+i) = temp;
            }
        }
    }

    while(indexA < numAB && indexB < numAB){
        if(*(a+indexA) < *(b+indexB)){
            *(c+indexC) = *(a+indexA);
            indexA++;
        } else {
            *(c+indexC) = *(b+indexB);
            indexB++;
        }
        indexC++;
    }
    //remainder of a if any
    while(indexA < numAB){
        *(c+indexC) = *(a+indexA);
        indexA++;
        indexC++;
    }

    //remainder of c if any
    while(indexB < numAB){
        *(c+indexC) = *(b+indexB);
        indexB++;
        indexC++;
    }

    return *c;
}
