#include "awgn.h"

awgn::awgn(){}

std::vector<std::complex<double>> awgn::step(std::vector<std::complex<double>> signal, double SNR, double Eb){
    std::random_device rd;
    std::mt19937 gen(rd());
    int len_sig = signal.size();

    double N0;
    N0 = (Eb/pow(10, SNR/10));
    std::normal_distribution<double> dist(0.0, sqrt(N0/2));

    std::vector<std::complex<double>> noise;
    std::vector<std::complex<double>> noisy_sig;
    std::complex<double> re = {1.0, 0.0}; 
    std::complex<double> im = {0.0, 1.0}; 
    for (int i=0; i<len_sig; ++i){
        noise.push_back(re*dist(gen) + im*dist(gen));
        noisy_sig.push_back(signal[i] + noise[i]);
    }
    return noisy_sig;
}