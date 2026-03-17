// sum-nbo.cpp

#include <stdint.h>
#include <netinet/in.h>
#include "sum-nbo.h"

uint32_t sum_nbo(uint32_t* values, int count)
{
    uint32_t total = 0;
    int i;
    for(i=0; i<count; i++)
    {
        total += ntohl(values[i]);
    }
    return total;
}