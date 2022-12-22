#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *look_and_say(int n) {
    // Base case: the first term is "1"
    if (n == 1) return "1";

    // Recursive case: generate the (n-1)-th term and then
    // generate the n-th term by reading off the digits of the (n-1)-th term
    char *prev_term = look_and_say(n - 1);
    char *current_term = malloc(strlen(prev_term) * 2 + 1);  // allocate memory for the n-th term
    int i = 0, j = 0;
    while (i < strlen(prev_term)) {
        int count = 1;
        while (i + 1 < strlen(prev_term) && prev_term[i] == prev_term[i + 1]) {
            i++;
            count++;
        }
        current_term[j++] = count + '0';  // append count to the current term
        current_term[j++] = prev_term[i++];  // append the digit to the current term
    }
    current_term[j] = '\0';  // terminate the string
    return current_term;
}


int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        char *term = look_and_say(i);
        printf("%s\n", term);
        
        //free(term);  // don't forget to free the memory allocated by malloc
    }
    return 0;
}
