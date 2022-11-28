#include<stdio.h>

void initialize(int[], int);
void countVotes (int[], int[], int);
int checkMajority(int[], int, int);
int checkPlurality(int[], int);


int main(void){
    int candidates, voters, i, vote;
    int majority, plurality;


    scanf("%d %d", &candidates, &voters);
    while (candidates != 0 && voters != 0){
        int votes[voters];
        int scores[candidates];

//    initialize each candidate total votes to 0
        initialize(scores, candidates);

//    collect votes
        for (i = 0; i < voters; i++){
           scanf("%d", &votes[i]);
        }

//    consolidate votes
        countVotes(votes, scores, voters);

//    check for Winner
        majority = checkMajority(scores, candidates, voters);
        plurality = checkPlurality(scores, candidates);
        if (majority > 0){
            printf("Majoritarian winner %d\n", majority);
        } else if ( plurality > 0){
            printf("Plurality winner %d\n", plurality);
        } else {
           printf("No winner\n");
        }

        scanf("%d %d", &candidates, &voters);
    }


    return 0;
}

void initialize(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        arr[i] = 0;
    }
};

void countVotes (int arr1[], int arr2[], int size){
    int i, vote;
    for (i = 0; i < size; i++){
       vote  = arr1[i] - 1;
       arr2[vote]++;
    }
}

int checkMajority(int arr[], int size, int voters){
    int i;
    int majority = voters / 2;
    for (i = 0; i < size; i++){
        if (arr[i] > majority){
            return i + 1;
        }
    }
    return 0;
}

int checkPlurality(int arr[], int size){
    int i, plurality = 0, winner = 0;

    for (i = 0; i < size; i++){
        if (arr[i] > plurality){
            plurality = arr[i];
            winner = i + 1;
        } else if (arr[i] == plurality){
            winner = 0;
        }
    }
    return winner;
}
