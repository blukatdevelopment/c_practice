/*
    Simple program to pick up commands from stdin
    and change output accordingly.
*/

#include <ncurses.h> // Compile with -lncurses
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void setup();
void teardown();
void read_command();
void execute_command();

#define BUFFERSIZE 100
static char buffer[BUFFERSIZE];
enum Commands { Quit = 0, Greet = 1, Help = 2};
static enum Commands command;

int main(void)
{ 
    setup();

    command = Greet;
    execute_command();

    while(command != Quit)
    {
        read_command();
        execute_command();
    }
    
    teardown();
    return 0;
}

void read_command()
{
    getstr(buffer);
    char * command_string = &buffer[0];

    clear();

    if(strcmp("greet", command_string) == 0)
    {
        command = Greet;
    }
    else if(strcmp("quit", command_string) == 0)
    {
        command = Quit;
    }
    else if(strcmp("help", command_string) == 0)
    {
        command = Help;
    }
    else{
        printw("Input not recognized\n");
        command = Help;
    }
}

void execute_command()
{
    switch(command)
    {
        case Quit:
            break;
        case Greet:
            printw("Enter a command! Use 'help' to list commands.\n");
            break;
        case Help:
            printw("greet - See greeting message\nquit - Exit program.\nhelp - See this listing.\n");
            break;
    }
    refresh();
}

void setup()
{
    initscr(); // Start curses mode
}

void teardown()
{
    endwin(); // End curses mode
    printf("Goodbye! :3\n");
}