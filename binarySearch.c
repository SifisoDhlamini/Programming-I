#include<stdio.h>
#include<stdbool.h>

int main(void){
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int first = 0, i;
    int item = 65;
    int last = (sizeof(numbers)/sizeof(numbers[0])) - 1;
    bool found = false;
    int middle;

    for (i = 0; i < last + 1; i++){
        printf("%d  ", i);
    }
    printf("\n");
    for (i = 0; i < last + 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n\n");


    while(first <= last && !found){
        middle = (first + last)/2;
        printf("middle = %d\n", middle);
        if (item == numbers[middle]){
            found = true;
        } else if (item < numbers[middle]){
            last = middle - 1;
            printf("last = %d\n", last);
        } else {
            first = middle + 1;
            printf("first = %d\n", first);
        }
    }

    if (found){
        printf("The number %d was found at index number %d", item, middle);
    } else {
        printf("Number not found");
    }

    return 0;
}
