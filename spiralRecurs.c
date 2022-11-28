
#include<stdio.h>
int print(int c, int length, int arr[][length], int r, int total, int startY, int startX, int dir);


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
    int startY = 0;
    int startX = 0;
    int total = rows * columns;
    int dir = 0;
    int length = columns;
    print(columns, length, matrix, rows, total, startY, startX, dir);

    return 0;
}


int print(int c, int length, int arr[][length], int r, int total, int startY, int startX, int dir){
    static int count = 0;
    int i;

    if (count == total){
        return 0;
    }

    if (dir == 0){
        for (i = startX; i < c; i++){
            printf("%d ", arr[startY][i]);
            count++;
        }
        startY++;
    } else if(dir == 1){
        for (i = startY; i < r; i++){
            printf("%d ", arr[i][c - 1]);
            count++;
        }
        c--;
    } else if(dir == 2){
        for (i = c - 1; i >= startX; i--){
            printf("%d ", arr[r - 1][i]);
            count++;
        }
        r--;
    } else if(dir == 3){
        for (i = r - 1; i >= startY; i--){
            printf("%d ", arr[i][startX]);
            count++;
        }
         startX++;
     }

     dir =(dir+1)%4;

    print(c, length, arr, r, total, startY, startX, dir);
}
