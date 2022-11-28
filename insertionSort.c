#include<stdio.h>
#include<stdbool.h>


int main(void){
    int arr[] = {4, 7, 9, 1, 2, 5, 3, 8, 6};
    int current = 1;
    int firstUnsorted = 0;
    int index;
    int length = 9;
    int i;
    bool placeFound;

    printf("unsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }

    while (current < length){
        index = current;
        placeFound = false;
        while (index > 0 && !placeFound){
            if (arr[index] < arr[index - 1]){
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                printf("\nswapped %d (index %d)and %d (index %d)\n", arr[index], index, arr[index -1], index - 1);
                index--;
            } else {
                placeFound = true;
            }
        }
        printf("\n\nsorted for index %d: ", current);
        for (i = 0; i < length; i++){
            printf("%d ", arr[i]);
        }
        current++;
    }

    printf("\n\nsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

