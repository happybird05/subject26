// main.cpp

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "sum-nbo.h"

int main(int argc, char** argv)
{
    int i;
    uint32_t *value = (uint32_t*) malloc(sizeof(uint32_t) * (argc-1));
    uint32_t sum;

    if(argc < 2)
    {
        printf("./sum-nbo <file1> [<file2> ...]");
        return -1;
    }

    if(value == NULL)
    {
        fprintf(stderr, "[Error] Can not use malloc");
        return -1;
    }

    for(i=1; i<argc; i++)
    {
        FILE* fp = fopen(argv[i], "rb");

        if(fp == NULL)
        {
            fprintf(stderr, "[Error] Can not open the file: %s", argv[i]);
            free(value);
            return -1;
        }

        if(fread(&value[i-1], 1, 4, fp) != 4)
        {
            fprintf(stderr, "[Error] %s File is too small", argv[i]);
            fclose(fp);
            free(value);
            return -1;
        }
        fclose(fp);
    }

    sum = sum_nbo(value, argc-1);

    for(i=0; i<argc-1; i++)
    {
        printf("%u(0x%08x)", ntohl(value[i]), ntohl(value[i]));
        if (i < argc-2)
            printf(" + ");
    }
    printf(" = %u(0x%08x)", sum, sum);

    free(value);
    
    return 0;
}