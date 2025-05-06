#include "bin2dec.h"
#include <vector>
#include <cmath>

std::vector<int> bin2dec(std::vector<int> binary, int base){
    std::vector<int> dec;
    int len = size(binary)/base;
    for (int k=0; k<len; ++k){
        dec.push_back(0);
        for (int i=0; i<base; ++i){
            dec[k] = dec[k] + binary[k*base+i]*pow(2, base-1-i);
        }
    }
    return dec;
}