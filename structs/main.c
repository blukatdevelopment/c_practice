/***************************************
 *     c_object                        *
 *     This programs aims to           *
 *     demonstrate use of structs and  *
 *     functions to replicate objects  *
 *     and methods found in most OOP   *
 *     languages.                      *
 *                                     *
 **************************************/

#include <stdio.h>

enum Sounds {Silence = 0, Bark = 1, Meow = 2};

struct animal 
{
    enum Sounds sound;
    char * name;
};

struct animal Animal(enum Sounds sound, char * name)
{
    struct animal an;
    an.sound = sound;
    an.name = name;

    return an;
}

void make_sound(struct animal an)
{
    switch(an.sound)
    {
        case Silence:
            break;
        case Bark:
            printf("%s barks loudly!\n", an.name);
            break;
        case Meow:
            printf("%s meows quietly.\n", an.name);
            break;
    }
}

int main()
{

    struct animal dog = Animal(Bark, "dog");

    struct animal cat = Animal(Meow, "cat");

    make_sound(dog);
    make_sound(cat);

    return 0;
}