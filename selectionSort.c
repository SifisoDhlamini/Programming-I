#include<stdio.h>


int main(void){
    int arr[] = {4, 7, 9, 1, 2, 5, 3, 8, 6};
    int firstUnsorted = 0;
    int indexOfSmallest;
    int index;
    int length = sizeof(arr)/arr[0];
    int i;

    printf("unsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    while (firstUnsorted < length - 1){
        indexOfSmallest = firstUnsorted;
        index = indexOfSmallest + 1;
        printf("\nsorting at index %d: \n", indexOfSmallest);
        for (i = 0; i < length; i++){
            printf("%d ", arr[i]);
        }
        while (index <= length -1){
            if (arr[index] < arr[indexOfSmallest]){
                indexOfSmallest = index;
                printf("\nsmallest is %d at index %d", arr[index], index);
            }
            index++;
        }
        printf("\nswapped %d and %d\n", arr[firstUnsorted], arr[indexOfSmallest]);
        int temp = arr[firstUnsorted];
        arr[firstUnsorted] = arr[indexOfSmallest];
        arr[indexOfSmallest] = temp;
        firstUnsorted++;
    }

    printf("\n\nsorted: ");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}
