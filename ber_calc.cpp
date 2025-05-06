#include <vector>
#include "ber_calc.h"

double ber_calc(std::vector<int> inp, std::vector<int> outp){
    int counter = 0;
    int numBits = inp.size();
    double ber;
    for (int t=0; t<numBits; ++t){
        if (inp[t] != outp[t]){
            counter ++;
        }
    }
    ber = double(counter)/double(numBits);
    return ber;
}