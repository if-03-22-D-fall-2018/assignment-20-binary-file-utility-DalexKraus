#include <stdio.h>
#include "generic.h"

int main(int argc, const char* argv[])
{
    char firstName[STRLEN];
    char lastName[STRLEN];
    int age;

    if (argc == 1)
        return -1;
    int id = atoi(argv[1]);

    size_t student_size = sizeof(firstName) + sizeof(lastName) + sizeof(int);

    FILE* fd = fopen("student.dat", "r");
    fseek(fd, sizeof(int) + student_size * id);

    fread(firstName, sizeof(char), sizeof(firstName), fd);
    fread(lastName, sizeof(char), sizeof(lastName), fd);
    fread(&age, sizeof(int), 1, fd);

    printf("First Name: %s\nLast Name: %s\nAge: %d", firstName, lastName, age);

    fclose(fd);
    return 0;
}
