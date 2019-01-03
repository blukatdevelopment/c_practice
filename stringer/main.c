#include <stdio.h>
#include <string.h>

int main()
{
    char string_array[] = "hello, world!"; // You can't modify constant char arrays
    char * string = &string_array[0];

    printf("Original string: %s\n", string);

    for(int i = 0; i < strlen(string); i++){
        printf("%c \n", string[i]);
    }

    printf("\n\n\n\n\n Now let's manipulate this string.\n\n\n\n");

    for(int i = 0; i < strlen(string); i++){
        string[i] = 'b';
        printf("string has changed to %s\n", string);
    }

    printf("String is now: %s\n", string);

    return 0;
}
