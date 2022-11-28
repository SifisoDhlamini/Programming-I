#include<stdio.h>

int main(void){
    int height;
    int climb;
    int slide;
    int currentPosition;
    int days = 1;


    scanf("%d %d %d", &height, &climb, &slide);

    currentPosition = climb; //initialize position to first day climb
    //top will be reached on first climb
    if (climb > height){
        days = 1;
    //it will never reach the top
    } else if (climb <= slide){
        days = -1;
    } else {
        while (currentPosition < height){
            currentPosition -= slide; //start with the slide that happened at night
            currentPosition += climb;
            days++;
        }
    }
    printf("%d", days);
}
