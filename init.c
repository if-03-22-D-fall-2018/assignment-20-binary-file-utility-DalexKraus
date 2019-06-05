#include <stdio.h>

int main(int argc, const char* argv[])
{
    FILE* fd = fopen("student.dat", "w+");

    int id = 1;
    fwrite(&id, sizeof(int), 1, fd);
    fclose(fd);

    return 0;
}
