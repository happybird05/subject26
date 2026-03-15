// main.cpp

#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#include "sum-nbo.h"

int main(int argc, char** argv)
{
    uint32_t a, b, c, sum;

    FILE* fp1 = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");
    FILE* fp3 = fopen(argv[3], "rb");

    fread(&a, 4, 1, fp1);
    fread(&b, 4, 1, fp2);
    fread(&c, 4, 1, fp3);
    
    sum = sum_nbo(a, b, c);
    a = ntohl(a);
    b = ntohl(b);
    c = ntohl(c);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("%d(0x%08x) + %d(0x%08x) + %d(0x%08x) = %d(0x%08x)", a, a, b, b, c, c, sum, sum);
    
    return 0;
}


