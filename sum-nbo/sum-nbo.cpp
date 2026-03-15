// sum-nbo.cpp

#include <stdint.h>
#include <netinet/in.h>
#include "sum-nbo.h"

uint32_t sum_nbo(uint32_t n1, uint32_t n2, uint32_t n3)
{
    return ntohl(n1) + ntohl(n2) + ntohl(n3); 
}
