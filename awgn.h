#ifndef AWGN_H
#define AWGN_H

#include <iostream>
#include <complex>
#include <vector>
#include <random>

class awgn {
private:

public:
    awgn();
    std::vector<std::complex<double>> step(std::vector<std::complex<double>> signal, double SNR, double Eb);

};

#endif