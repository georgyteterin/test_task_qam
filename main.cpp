#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include "mapper.h"
#include "awgn.h"
#include "demapper.h"
#include "ber_calc.h"

int main(){
    srand((unsigned int)time(NULL));
    int M = 16;
    int log2M = log2(M);
     int numBits = 660000;
    //int numBits = 240000;
    int numSymbols = numBits/log2M;
    std::vector<int> bits;
    std::vector<std::complex<double>> tx_sig;
    std::vector<std::complex<double>> rx_sig;
    std::vector<int> out_bits;
    std::string filename = "qam_16_results.txt";
    mapper Mapper(M);
    demapper deMapper(M);
    awgn Channel;

    double SNR[16] = {0.0, 1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 
                    11.0, 12.0, 13.0, 14.0, 15.0};
    double ber[16];
  /*  double SNR[11] = { 0.0, 1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double ber[11];*/
    double SNR_current;
    int snr_len = sizeof(SNR) / sizeof(SNR[0]);
    double Eb = Mapper.get_eb();
 
    std::ofstream res;
    res.open("mtlb/results/" + filename);
    //res.open(filename);
    if (res.is_open()) {
        res << numBits << ';';
    }
    else{
        std::cout << "o kak" << std::endl;
    }


    for (int i=0; i< snr_len; ++i){
        SNR_current = SNR[i];

        // генерируем случайный поток битов
        for (int i=0; i<numBits; i++){ 
            bits.push_back(rand()%2);
        }

        tx_sig = Mapper.step(bits);
        rx_sig = Channel.step(tx_sig, SNR_current, Eb);
        out_bits = deMapper.step(rx_sig);

        ber[i] = ber_calc(bits, out_bits);
        if (res.is_open()){
            res << std::fixed << std::setprecision(3) << SNR_current << ';' << std::fixed << std::setprecision(8) << ber[i] << ';';
        }
    }
    res.close();
    return 0;
}
