#include<stdio.h>
#include<stdbool.h>
#define MAX 5
#define TOTAL 25

typedef struct{
    int bingoCard[MAX][MAX];
    int winAt;
    int index;
}Student;

bool checkPattern(int pattern[], int length, Student student);
bool checkExist(int arr[], int position, int number);

int main(void){
   int students;

   scanf("%d", &students) ;
   Student card[students];
   int teacher[TOTAL];
   int winnerPositions[TOTAL] = {0};
   int winners = 0;

    //collect student Student
    for (int i = 0; i < students; i++){
        for (int j = 0; j < MAX; j++){
            for (int k = 0; k < MAX; k++){
                scanf("%d", &card[i].bingoCard[j][k]);
            }
        }
        card[i].winAt = - 1; //initialize winning position
        card[i].index = i + 1;
    }

    //collect teachers scores
    for (int j = 0; j < TOTAL; j++){
        scanf("%d", &teacher[j]);
    }

    //start from 5th element (nobody wins when we don't have at least 5 numbers)
    int position = MAX - 1; //index 4

    //check bingo winners until all three have won
    while(winners < students){
        for(int i = 0; i < students; i++){
                if(checkPattern(teacher, position, card[i])){
                    if(card[i].winAt == -1){
                        card[i].winAt = position;
                        winners++;
                        winnerPositions[position]++;
                    }
                }
        }
        position++;
    }

    //print winners
    winners = 0;
    for (int j = MAX - 1; j < TOTAL; j++){
        if (winnerPositions[j] > 0 ){
            printf("%d:", j+1);
            for(int i = 0; i < students; i++){
                if(card[i].winAt == j){
                    printf(" %d", card[i].index);
                    winners++;
                }
            }
            //if(winners < students)
                printf("\n");
        }
    }

   return 0;
}

bool checkPattern(int pattern[], int length, Student student){
    int count = 0;

    //check rows
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(checkExist(pattern, length, student.bingoCard[i][j]))
                count++;
        }
        if(count == 5)
            return true;
        count = 0;
    }

    //check columns
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(checkExist(pattern, length, student.bingoCard[j][i]))
                count++;
        }
        if(count == 5)
            return true;
        count = 0;
    }

    //check diagonal right
    for (int i = 0; i < MAX; i++){
        if(checkExist(pattern, length, student.bingoCard[i][i]))
            count++;
        if(count == 5)
             return true;
    }

    count = 0;

//    check diagonal left
    for (int i = 0; i < MAX; i++){
        if(checkExist(pattern, length, student.bingoCard[i][(MAX - 1) - i]))
            count++;
        if(count == 5)
             return true;
    }

    count = 0;

    return false;
}

bool checkExist(int arr[], int position, int number){
    for(int i = 0; i <= position; i++){
        if(number == arr[i]){
            return true;
        }
    }

    return false;
}
