//
// Created by David on 05.06.2019.
//

#include <stdio.h>

int main(int argc, const char* argv[])
{
    FILE* fd = fopen("students.dat", "w+");

    int id = 1;
    fwrite(&id, 1, 1, fd);
    fclose(fd);

    return 0;
}
