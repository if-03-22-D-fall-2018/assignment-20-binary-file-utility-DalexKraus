#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

void get_input(char text[], const char* prompt)
{
    printf("%s", prompt);
    scanf("%s", text);
}

int main(int argc, const char* argv[])
{
    char firstName[STRLEN];
    char lastName[STRLEN];
    char rawAge[STRLEN];

    get_input(firstName, "First Name: ");
    get_input(lastName, "Second Name: ");
    get_input(rawAge, "Age: ");
    int age = atoi(rawAge);

    FILE* fd = fopen("student.dat", "r+");

    //Read last ID
    int lastId;
    fseek(fd, -sizeof(int), SEEK_END);
    fread(&lastId, sizeof(int), 1, fd);

    //Write new Entry
    fwrite(firstName, sizeof(char), sizeof(firstName), fd);
    fwrite(lastName, sizeof(char), sizeof(lastName), fd);
    fwrite(&age, sizeof(int), 1, fd);

    //Append new ID
    lastId++;
    fwrite(&lastId, sizeof(int), 1, fd);

    fclose(fd);
    return 0;
}

