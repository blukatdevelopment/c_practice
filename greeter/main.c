/**************************************
 *     Greeter                        *
 *     Should demonstrate a few       *
 *     concepts:                      *
 *     - command-line args            *
 *     - piped input                  *
 *************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/poll.h> // poll, pollfd
#include <unistd.h>   // Provides STDIN_FILENO

int main(int argc, char* argv[])
{
    struct pollfd inputfd;
    inputfd.fd = STDIN_FILENO;
    inputfd.events = POLLIN;


    int BUFFERSIZE = 100;
    char buffer[BUFFERSIZE];

    if (argc > 1)
    {
        printf("Hello, %s!\n", argv[1]);
    }
    else if (poll(&inputfd, 1, 0) && fgets(buffer, sizeof buffer, stdin) && strlen(buffer))
    {
	int lastChar = strlen(buffer)-1;
        buffer[lastChar] = '\0';
        printf("Hello, %s!\n", buffer);
    }
    else
    {
        printf("Usage: greeter <name>\n");
    }

    return 0;
}
