//#include<iostream>
//#include<fstream>
//using namespace std;

#include <stdio.h>

int main () {
    //fstream file;
    //file.open("a.txt", ios::in, ios::out);
    // 
    FILE* f;
    char buff[100];
    //f = fopen("a.txt", "a+");
    f = fopen("a.txt", "r");

    //fprintf(f, "Test1\n");
    //fputs("Test2\n", f);

    while (fscanf(f, "%s\n", buff) != EOF)
    {
        printf("%s\n", buff);
    }

    //fread / fwrite ptr, size, num, FILE*

    fclose(f);
}


