#include <stdio.h>

class GATE {
public:
    ~GATE(){}    
};

class AND : public GATE {
public:
    bool operator () (bool p1, bool p2)
    {
        return (p1&&p2);
    }
};

class NOT : public GATE {
public:
    bool operator () (bool p)
    {
        return (!p);
    }
};

class NAND : public AND, public NOT {
public:
    bool operator () (bool p1, bool p2)
    {
        return NOT::operator()(AND::operator()(p1, p2));
    }
};

int main()
{
    //bool a = true;
    //bool b = true;
    //
    //NAND c;
    //printf("NAND of %d and %d is: %d", (a?1:0), (b?1:0), c(a,b));

    // small test 1
    //int arr[] = {1,2,3,4,5};
    //char arr[] = "abhishek";
    //
    //printf ("%p\n",arr+1);
    //printf ("%p\n",&arr+1);

    //int* a  = (int *) 60;
    //int* b = (int *) 40;
    ////((void*)a-(void*)b)
    //printf("%d\n",a-b);
    ////printf("%d\n",((char*)a-(char*)b));
    // 

    char * str1 = "hello";
    char * str2 = "hello";
    printf("%p\n",str1);
    printf("%p\n",str2);
    if (str1 == str2) {
        printf("Equal");
    }
    
    return 0;
}
