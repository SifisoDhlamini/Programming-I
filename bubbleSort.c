#include<stdio.h>
#include<stdbool.h>


int main(void){
    int arr[] = {2, 1, 3, 4, 5, 6, 7, 8, 9};
    int firstUnsorted = 0;
    int index = firstUnsorted + 1;
    int length = 9;
    int i;
    bool swap = true;
    printf("unsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    while (firstUnsorted < length && swap){
        printf("\nFirstUnsorted  = %d", firstUnsorted);
        swap = false;
        index = length - 1;
        while (index > firstUnsorted){
            if (arr[index] < arr[index - 1]){
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                swap = true;
                printf("\nswapped %d and %d\n", arr[index], arr[index - 1]);

            }
            if (swap){
               printf("\nswap is true\n");
            } else {
                printf("\nswap is false\n");
            }

            printf("\n\nsorted for index %d: ", firstUnsorted);
            for (i = 0; i < length; i++){
                printf("%d ", arr[i]);
            }
            index--;
        }
        firstUnsorted++;
    }

    printf("\n\nsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
