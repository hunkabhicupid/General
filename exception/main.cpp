// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
#include <Windows.h>
#include <stdio.h>
#include <stdexcept>

class B {
public:
    B()
    {
        c = 0;
        printf ("Constructor\n");
    }

   ~B()
    {
        printf ("Destructor\n");
    }

    void Add(int a)
    {
        c=c+a;
    }
    int Get()
    {
        return c;
    }
private:
    int c;
};

// dynamic
void func1 ()
{
    B* b = new B;
    b->Add(10);
    printf("%d\n", b->Get());
    throw std::runtime_error("To be passed between threads"); 
    delete b;
    printf("Post throw\n");
}

// static
void func2 ()
{
    B b;
    b.Add(10);
    printf("%d\n", b.Get());
    throw std::runtime_error("To be passed between threads");     
    printf("Post throw\n");
}

void func3()
{
    B b;
    b.Add(10);
    printf("%d\n", b.Get());
    func2();
}

LONG WINAPI HandleException(EXCEPTION_POINTERS* pEXInfo)
{
    DWORD   code = pEXInfo->ExceptionRecord->ExceptionCode;
    // 3765269347 == 0xE06D7363
    // All Visual C++ exceptions thrown from code generated by the Microsoft Visual C++ compiler 
    // contain this error code. Because this is a compiler-generated error, the code is not listed 
    // in the Win32 API header files. The code is actually a cryptic mnemonic device, with the initial
    //  "E" standing for "exception" and the final 3 bytes (0x6D7363) representing the ASCII values of "msc".
    printf("Exception Code: %u\n", code);
    return EXCEPTION_EXECUTE_HANDLER;
}

int main()
{
    B b;
    b.Add(10);
    printf("%d\n", b.Get());
    SetUnhandledExceptionFilter(HandleException);

    int ret = 0; 
    try {
        //func1();
        func3();
        printf("PostThrow2\n");
    } catch (...) {        
        printf("Program failed\n");
        ret = -1;
    }

    printf("Program Termination\n");
    return ret;
}
