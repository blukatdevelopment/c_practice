#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substring(char * destination, char * source, int start, int size);
void fill_buffer(char * string, int length);

int main()
{
    char string_array[] = "hello, world!"; // You can't modify constant char arrays
    char * source = &string_array[0];
    char destination_array[15]; 
    char * destination = &destination_array[0];
    
    fill_buffer(destination, 15);

    printf("Started with %s, %s\n", source, destination);

    substring(destination, source, 0, 5);

    printf("Ended with %s, %s\n", source, destination);

    return 0;
}

// Fills string with blank spaces
void fill_buffer(char * string, int length)
{
    for(int i = 0; i < length-1; i++)
    {
        string[i] = ' ';
    }
    string[length] = '\0';
}

int substring(char * destination, char * source, int start, int size)
{
    //printf("substring");
    if(start + size >= strlen(source))
    {
        printf("substring larger than string\n");
        return -1;
    }

    if(strlen(destination) < size)
    {
        printf("substring buffer too small\n");
        return -2;
    }

    int sub_i = 0;
    for(int i = start; i < start + size; i++)
    {
        destination[sub_i] = source[i];
        sub_i++;
    }
    destination[sub_i] = '\0';

    return 0;
}