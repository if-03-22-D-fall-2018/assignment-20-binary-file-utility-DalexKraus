#include <stdio.h>
#include "generic.h"

int main(int argc, const char* argv[])
{
    char firstName[STRLEN];
    char lastName[STRLEN];
    int age;

    FILE* fd=fopen("student.dat", "r");
    printf("%-10s %-20s %-20s %-5s\n", "Id", "First Name", "Last Name", "Age");

    int id;
    fseek(fd, 0, SEEK_SET);
    int count = fread(&id, sizeof(int), 1, fd);
    while (count > 0)
    {
        int total = 0;
        total += fread(firstName, sizeof(char), sizeof(char) * STRLEN, fd);
        total += fread(lastName, sizeof(char), sizeof(char) * STRLEN, fd);
        total += fread(&age, sizeof(int), 1, fd);

        if (total == STRLEN * 2 + 1)    //Only print if read is successful
            printf("%010d %-20s %-20s %-5d\n", id, firstName, lastName, age);

        count = fread(&id, sizeof(int), 1, fd);
    }

    fclose(fd);
    return 0;
}
