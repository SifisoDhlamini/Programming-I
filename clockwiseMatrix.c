#include<stdio.h>

void printToRight(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]);
void printToBottom(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]);
void printToLeft(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]);
void printToTop(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]);

int main(){
    int rows, columns;
    int i, j;

    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];

    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int startX = 0;
    int finishX = columns - 1;
    int startY = 0;
    int finishY = rows - 1;
    int count = 0;
    int total = rows * columns;

    while(count < total){
        if(count < total){
            printToRight(finishX, finishY, startX, startY, rows, columns, matrix);
            startY++;
            count+=(finishX - startX + 1);
        }

        if(count < total){
           printToBottom(finishX, finishY, startX, startY, rows, columns, matrix);
            finishX--;
            count+=(finishY - startY + 1);
        }

        if(startX < finishX && count < total){
            printToLeft(finishX, finishY, startX, startY, rows, columns, matrix);
            finishY--;
            count+=(finishX - startX + 1);
        }

        if(startX < finishX && count < total){
            printToTop(finishX, finishY, startX, startY, rows, columns, matrix);
            startX++;
            count+=(finishY - startY + 1);
        }
    }

    return 0;
}
void printToRight(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]){
    int i;

    for (i = startX; i <= finishX; i++){
        printf("%d ", matrix[startY][i]);
    }
}
void printToBottom(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]){
    int i;

    for (i = startY; i <= finishY; i++){
        printf("%d ", matrix[i][finishX]);
    }
}
void printToLeft(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]){
    int i;

    for (i = finishX; i >= startX; i--){
        printf("%d ", matrix[finishY][i]);
    }
}
void printToTop(int finishX, int finishY, int startX, int startY, int rows, int columns, int matrix[rows][columns]){
    int i;

    for (i = finishY; i >= startY; i--){
        printf("%d ", matrix[i][startX]);
    }
}
