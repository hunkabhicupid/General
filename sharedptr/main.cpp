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

   void Use ()
   {
       *x = (*x)+1;
   }
private:
    int* x;
};

#define NUM_THREADS 1000

void ThreadFunc (shared_ptr<A> pPtr)
{
    shared_ptr<A> a;    
    a = pPtr;
	a->Use();

    // two shared_ptrs get deleted when this function exits
    // a and pPtr go out of scope
}

int main ()
{
    shared_ptr<A> a(new A);

    thread * t[NUM_THREADS];    

    for (int i =0; i < NUM_THREADS; i++) {
        t[i] = new thread (ThreadFunc, a);
    }

    for (int i =0; i < NUM_THREADS; i++) {
        t[i]->join();
    }

    for (int i =0; i < NUM_THREADS; i++) {
        delete t[i];
    }
    
    return 0;
}



// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
