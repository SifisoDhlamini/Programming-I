#include <stdio.h>

void sort(int arr[], int length);

int main(void){
    int num, i, j;
    float middle = 0.0;
    int temp = 0;
    float count = 0.00;

    scanf("%d", &num);
    int numbers[num];

    for (j = 0; j < num; j++){
        scanf("%d", &numbers[j]);
    }

    sort(numbers, num);

    for (i = 3; i < (num - 3); i++){
        temp += numbers[i];
    }

    middle = (float)temp/(float)(num - 6);

    printf("%.2f", middle);

    return 0;
}

void sort(int arr[], int length){
    int i, j, temp;
    for (i = 0; i < length; i++){
        for (j = i + 1; j < length; j++){
            if (arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
