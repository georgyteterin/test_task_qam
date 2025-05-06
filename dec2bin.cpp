#include <iostream>
#include <vector>

std::vector<int> dec2bin(std::vector<int> decimal, int base){
    std::vector<int> binary;
    int len = size(decimal);
    int num;
    int sz;
    for (int k=0; k<len; ++k){
        num = decimal[k];
        sz = size(binary);
        binary.resize(sz+base);
        for (int i=0; i<base; ++i){
            binary[base*(k+1)-i-1] = num%2;
            num = num/2;
        } 
    }
    return binary;
}