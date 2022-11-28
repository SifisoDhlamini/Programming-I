#include<stdio.h>
#include<math.h>

typedef struct {
    int x;
    int y;
} coordinate;

void sortMontains(coordinate[], int);
float calcSun(coordinate[], int);

int main(void){
    int cases, cords, i, j;
    float totalSun;
    scanf("%d", &cases);
    for (i = 0; i < cases; i++){
        scanf("%d", &cords);
        totalSun = 0.0;
        coordinate mountainTop[cords];
        for (j = 0; j < cords; j++){
            scanf("%d %d", &mountainTop[j].x, &mountainTop[j].y);
        }

        sortMontains(mountainTop, cords);
//        for (j = 0; j < cords; j++){
//            printf("%d %d %d\n", j, mountainTop[j].x, mountainTop[j].y);
//        }
        totalSun = calcSun(mountainTop, cords);
        printf("%.2f\n", totalSun);
    }
}

void sortMontains(coordinate mT[], int s){
    int i, j;
    coordinate temp;
    for (i = 0; i < s - 1; i++){
        for (j = i + 1; j < s; j++){
            if(mT[j].x > mT[i].x){
                temp = mT[i];
                mT[i] = mT[j];
                mT[j] = temp;
            }
        }
    }
}

float calcSun(coordinate mT[], int size){
    float total = 0.0;
    int highestY = mT[0].y;
    int i;
    float a, b, c, ratio;
    for (i = 1; i < size; i++){
        if (mT[i].y > highestY){
            a = mT[i -1].x - mT[i].x;// difference of x coordinates
            b = mT[i].y - mT[i - 1].y;// difference in last y to current y
            c = sqrt(a*a + b*b);
            ratio = (mT[i].y-highestY)/b;
            total+= (c * ratio);
            highestY = mT[i].y;
        }
    }


    return total;
}
