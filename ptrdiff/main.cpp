#include <stdio.h>
#include <stdint.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

int main ()
{
    int * a = (int*)1000;
    int * b = a + 100;
    printf("Pointer Artimetic: %u\n", b); // %p prints in hex

    uintptr_t x = (uintptr_t)a;
    uintptr_t y = x + 100;
    printf("Normal Artimetic: %u\n", y);
    return 0;
}
