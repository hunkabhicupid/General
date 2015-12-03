#include <stdio.h>
//cl -Od /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

int main () {
    printf("%s", __FILE__);
}


