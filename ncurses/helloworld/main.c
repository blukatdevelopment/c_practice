#include <ncurses.h>
// Compile with -lncurses
// Based off of examplke here https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/
 
void setup();
void teardown();

int main(void)
{ 

    setup();

    printw("Hello World !");  /* Print Hello World          */
    refresh();                /* Print it on to the real screen */
    getch();            /* Wait for user input */
    teardown();
    return 0;
}

void setup()
{
    initscr(); // Start curses mode
}

void teardown()
{
    endwin(); // End curses mode
}