#include <stdio.h>
#include <string>

struct tIPRange {
    tIPRange(){
        uStart = 0;
        uEnd = 0;
    }
    unsigned int uStart;
    unsigned int uEnd;
};

unsigned char ConvertStrtoNum (std::string& pNum)
{
    int len = (int)pNum.length();
    unsigned char multiplier = 1;    
    unsigned char num = 0;


    for(int i = 0; i < len; i++) {        
        num += (pNum[len-(i+1)] - ((char)'0')) * multiplier;
        multiplier *= 10;
    };
    return num;
}

#define MAX_DOTS    3
#define MAX_SLASH   1

tIPRange * ParseSubnet (char * pSubnet)
{
    tIPRange *  ret      = new tIPRange;
    unsigned char numbits  = 0;
    int         numdots  = 0;
    char*       temp     = pSubnet;
    std::string num;

    while (*temp != '\0') {
        // if dot reached, reset get number and reset string
        if(*temp == '.' && ++numdots <= MAX_DOTS) {               
            ((unsigned char*)(&ret->uStart))[MAX_DOTS - (numdots-1)] = ConvertStrtoNum(num);
            num = "";
            temp++;
            continue;
        } else if (*temp == '/') {
            numbits = 1;
            num = "";
            temp++;
            continue;
        }

        num.append(temp, 1);        
        temp++;
    }

    // Parse the numbits
    if (numbits) {
        numbits = ConvertStrtoNum(num);
    }

    ret->uEnd = ((unsigned int)-1) >> 24; 
    ret->uEnd = ret->uStart | ret->uEnd;

    // validate everything
    if (!numbits || numdots != MAX_DOTS) {
        delete ret;
        ret = nullptr;
    }

    return ret;
}

bool  IsContains (tIPRange* r1, tIPRange* r2)
{
    if (r2->uEnd >= r1->uStart && r2->uStart <= r1->uEnd) 
        return true;

    return false;
}

int __cdecl main ()
{
        int ret =  0;
        int numsubnets;
        char subnet [35];

    scanf("%d", &numsubnets);
    tIPRange ** rangearr =  new tIPRange*[numsubnets];

    for(int i = 0; i < numsubnets; i++) {
        // Get the subnet 
        scanf("%s", subnet);
        // Parse the subnet
        rangearr[i] = ParseSubnet(subnet);
    }

    // Compare
    for (int i = 0; i < numsubnets; i++) {
        for (int j = i+1; rangearr[i] && j < numsubnets; j++) {
            if (rangearr[j] && IsContains(rangearr[i], rangearr[j]))
                printf("Subnet %d overlaps %d subnet", j+1, i+1);
        }
    }

    // free resources
    for(int i = 0; i < numsubnets; i++) {
        delete rangearr[i];
    }
    delete [] rangearr;

    return ret;
}
