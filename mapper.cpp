#include "mapper.h"
#include "bin2dec.h"



// фулл-кастом конструктор
mapper::mapper(int M) {
    this-> M = M;
}

// фулл-дефолт конструктор, тип модулции по умолчанию - 4-QAM
mapper::mapper(){
    this-> M = 4;
}
// основная функция
std::vector<std::complex<double>> mapper::step(std::vector<int> binary){
    int log2M = log2(M);
    int numSyms = binary.size()/log2M;
    std::vector<int> decimal;
    decimal = bin2dec(binary, log2M);
    std::vector<std::complex<double>> symbols;
    for (int i=0; i<numSyms; ++i){
        switch (M){
            case 4:
                symbols.push_back(constellation_4[decimal[i]]);
                break;
            case 16:
                symbols.push_back(constellation_16[decimal[i]]);
                break;
            case 64:
                symbols.push_back(constellation_64[decimal[i]]);
                break;
        }
    }
    return symbols;
}