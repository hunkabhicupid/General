#include <stdio.h>
#include <memory> // std::shared_ptr
#include <thread> // std::thread
using namespace std;

/**
 * Dummy class
 */
class A {
public:
    A() {
        x = new int(100);        
    }
    ~A(){
        printf("This is deleted once");
        delete x;
    }

    // copy constrcutor
    // deep copy
    A(const A& pLHS)
    {
        // deep copy
        x = new int(*(pLHS.x));        
    }

    // move constructor
    // less costlier than copy
    A(A&& pRHS)
    {
        // deep copy
        x = pRHS.x;        
        pRHS.x = nullptr;
    }

    void Use ()
    {
        *x = (*x)+1;
    }
private:
    int* x;
};

// function returning rvalue
A func ()
{
    return A();
}

int main ()
{
    A a;

    A b(a);
    A c(std::move(func()));
    
    return 0;
}



// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
