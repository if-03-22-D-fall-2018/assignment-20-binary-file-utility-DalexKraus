#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

int main(int argc, const char* argv[])
{
    char firstName[STRLEN];
    char lastName[STRLEN];
    int age;

    if (argc == 1)
        return -1;
    int id = atoi(argv[1]) - 1;

    size_t student_size = sizeof(firstName) + sizeof(lastName) + sizeof(int) * 2;

    FILE* fd = fopen("student.dat", "r");
    fseek(fd, sizeof(int) + student_size * id, SEEK_SET);

    fread(firstName, sizeof(char), sizeof(firstName), fd);
    fread(lastName, sizeof(char), sizeof(lastName), fd);
    fread(&age, sizeof(int), 1, fd);

    printf("First Name: %s\nLast Name: %s\nAge: %d\n", firstName, lastName, age);

    fclose(fd);
    return 0;
}
