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
// посчитать энергию бита
double mapper::get_eb() {
    int log2M = log2(M);
    double bit_energy;
    //std::vector<std::complex<double>> symbol_energy;
    double symbol_energy = 0;
    switch (M){
        case 4:
            //bit_energy = 1.0;
            for (int i = 0; i < 4; ++i) {
                //symbol_energy.push_back(pow(abs(constellation_4[i]), 2));
                symbol_energy += pow(abs(constellation_4[i]), 2);
            }
            break;
        case 16:
            //bit_energy = 2.5;
            for (int i = 0; i < 16; ++i) {
                //symbol_energy.push_back(pow(abs(constellation_16[i]), 2));
                symbol_energy += pow(abs(constellation_16[i]), 2);
            }
            break;
        case 64:
            //bit_energy = 7;
            for (int i = 0; i < 64; ++i) {
                //symbol_energy.push_back(pow(abs(constellation_64[i]), 2));
                symbol_energy += pow(abs(constellation_64[i]), 2);
            }
            break;
        default:
            bit_energy = 1.0;
            break;
    }
    symbol_energy = symbol_energy / double(M);
    bit_energy = symbol_energy / double(log2M);

    return bit_energy;
}