#include "demapper.h"
#include "dec2bin.h"


demapper::demapper(){
    this->M = 4;
}
demapper::demapper(int M){
    this->M = M;
}

std::vector<int> demapper::step(std::vector<std::complex<double>> noisy_sig){
    int log2M = log2(M);
    int len_sig = noisy_sig.size();
    double min_distance;
    double current_distance;
    std::vector<int> output;
    std::vector<int> output_bits;

    for (int i=0; i<len_sig; ++i){
        min_distance = 100.0;
        output.push_back(i);
        for (int k=0; k<M; ++k){
            switch(M){
                case 4:
                    current_distance = sqrt(pow(real(noisy_sig[i]) - real(constellation_4[k]), 2) 
                        + pow(imag(noisy_sig[i]) - imag(constellation_4[k]), 2));
                        break;
                case 16:
                    current_distance = sqrt(pow(real(noisy_sig[i]) - real(constellation_16[k]), 2) 
                        + pow(imag(noisy_sig[i]) - imag(constellation_16[k]), 2));
                            break;
                case 64:
                    current_distance = sqrt(pow(real(noisy_sig[i]) - real(constellation_64[k]), 2) 
                        + pow(imag(noisy_sig[i]) - imag(constellation_64[k]), 2));
                            break;
            }
            if (current_distance < min_distance){
                min_distance = current_distance;
                output[i] = k;
            }
        }
    }

    output_bits = dec2bin(output, log2M);

    return output_bits;
}