/****************************************
 *     threads                          *
 *     This demo shows creating two     *
 *     threads and waiting for one two  *
 *     finish. It also shows use of     *
 *     malloc and free for a struct ref *
 ***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>  // Don't forget to compile with -lpthread for gcc

void* count_up(void* pointer);
void start_thread(pthread_t * thread, char * name, int speed);

struct count_up_args {
    char * name;
    int speed;
};

int main()
{
    pthread_t threads[2];
    printf("main starting\n");
    start_thread(&threads[0], "thread1", 1);
    start_thread(&threads[1], "thread2", 2);
    printf("main waiting for thread1\n");
    pthread_join(threads[1], NULL);
    printf("main done\n");

}

void start_thread(pthread_t * thread, char * name, int speed)
{
    struct count_up_args * args;
    args = malloc(sizeof(struct count_up_args));
    args->name = name;
    args->speed = speed;

    pthread_create(thread, NULL, count_up, (void*) args);
}

void* count_up(void* pointer)
{
    struct count_up_args * args = (struct count_up_args *) pointer;
    printf("%s starting with speed of %d\n", args->name, args->speed);
    for(int i = 0; i < 10; i++)
    {

        printf("%s count_up %d\n", args->name, i + 1);
        sleep(args->speed);
    }


    free(args);
    return NULL;
}