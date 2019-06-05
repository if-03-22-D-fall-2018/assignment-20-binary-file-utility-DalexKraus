//
// Created by David on 05.06.2019.
//
#include <stdio.h>

void get_input(char text[], const char* prompt)
{
    printf("%s", prompt);
    scanf("%s", text);
}

int main(int argc, const char* argv[])
{
    printf("lol");

    char firstName[15];
    char lastName[15];
    char age[15];

    get_input();
    get_input();
    get_input();

    printf("F: %s, L:", firstName);

    return 0;
}

