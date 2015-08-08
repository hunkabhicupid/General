#include <stdio.h>
#include <stdint.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

int main ()
{
    char    i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;

    unsigned char iu8;
    uint16_t iu16;
    uint32_t iu32;
    uint64_t iu64;

    printf("\nHello!!\n");

    // input
    //printf ("Input char:\n");
    //scanf ("%hh", &i8);
    //printf ("char    %hh\n", i8);
    // 
    //printf ("Input int16_t:\n");
    //scanf ("%h", &i16);
    //printf ("int16_t %h\n", i16);
     
    printf ("Input int32_t:\n");
    scanf ("%d", &i32);
    printf ("int32_t %d\n", i32);

    printf ("Input int64_t:\n");
    scanf ("%lld", &i64);
    printf ("int64_t %lld\n", i64);

    printf ("Input unsigned char:\n");
    scanf ("%hhu", &iu8);
    printf ("uchar    %hhu\n", iu8);

    printf ("Input uint16_t:\n");
    scanf ("%hu", &iu16);
    printf ("uint16_t %hu\n", iu16);

    printf ("Input uint32_t:\n");
    scanf ("%u", &iu32);
    printf ("uint32_t %u\n", iu32);

    printf ("Input uint64_t:\n");
    scanf ("%llu", &iu64);
    printf ("uint64_t %llu\n", iu64);

    return 0;
}
