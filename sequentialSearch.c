#include<stdio.h>
#include<stdbool.h>

int main(void){
    int arr[] = {4, 7, 9, 1, 2, 5, 3, 8, 6};
    int position = 0;
    int search = 7;
    bool found = false;
    int length = sizeof(arr)/arr[0];

    while (position < length && !found){
        if (arr[position] == search){
            found = true;
        } else {
           position++;
        }
    }

    printf("The number %d was found at index %d", search, position);
    return 0;
}



