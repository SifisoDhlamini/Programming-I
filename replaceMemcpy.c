#include <stdio.h>
#include <string.h>

char *replace(char *source, char const *pattern, char const *replacement)
{
    char *substring;
    static char *last_source;
    static char *last_replace;
    int isNull = 0;

    if(source != NULL && (substring = strstr(source, pattern)) == NULL){
        source = last_source;
        return source;
    }

    if (source == NULL){
        source = last_source;
        isNull = 1;
        substring = strstr(last_replace, pattern);
        if( substring == NULL)
            return source;
    }

    int patternLength = strlen(pattern);
    int replacementLength = strlen(replacement);
    int tail_len = strlen(substring) + 1;
    last_replace = substring + replacementLength - 1;

    memcpy(substring + replacementLength, substring + patternLength, tail_len);
    memcpy(substring, replacement, replacementLength);

    if (isNull == 0){
        last_source = source;
    }

    return source;
}

int main(void) {
    char source[100] = "1223456789", pattern[10] = "2", replacement[10] = "123";

    printf("%s\n", source);
    printf("%s\n", replace(source, pattern, replacement));
    printf("%s\n", replace(source, pattern, replacement));
    printf("%s\n", replace(source, pattern, replacement));
    printf("%s\n", replace(NULL, pattern, replacement));

    return 0;
}
