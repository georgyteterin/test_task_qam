#ifndef DEMAPPER_H
#define DEMAPPER_H

#include <iostream>
#include <complex>
#include <vector>

class demapper {
private:
    int M;
    std::complex<double> constellation_4[4] = { std::complex<double>(-1.0, 1.0),
        std::complex<double>(-1.0, -1.0),
        std::complex<double>(1.0, 1.0),
        std::complex<double>(1.0, -1.0) };
    std::complex<double> constellation_16[16] = { std::complex<double>(-3.0, 3.0),
        std::complex<double>(-3.0, 1.0),
        std::complex<double>(-3.0, -3.0),
        std::complex<double>(-3.0, -1.0),
        std::complex<double>(-1.0, 3.0),
        std::complex<double>(-1.0, 1.0),
        std::complex<double>(-1.0, -3.0),
        std::complex<double>(-1.0, -1.0),
        std::complex<double>(3.0, 3.0),
        std::complex<double>(3.0, 1.0),
        std::complex<double>(3.0, -3.0),
        std::complex<double>(3.0, -1.0),
        std::complex<double>(1.0, 3.0),
        std::complex<double>(1.0, 1.0),
        std::complex<double>(1.0, -3.0),
        std::complex<double>(1.0, -1.0) };
    std::complex<double> constellation_64[64] = { std::complex<double>(-7.0, 7.0),
        std::complex<double>(-7.0, 5.0),
        std::complex<double>(-7.0, 1.0),
        std::complex<double>(-7.0, 3.0),
        std::complex<double>(-7.0, -7.0),
        std::complex<double>(-7.0, -5.0),
        std::complex<double>(-7.0, -1.0),
        std::complex<double>(-7.0, -3.0),
        std::complex<double>(-5.0, 7.0),
        std::complex<double>(-5.0, 5.0),
        std::complex<double>(-5.0, 1.0),
        std::complex<double>(-5.0, 3.0),
        std::complex<double>(-5.0, -7.0),
        std::complex<double>(-5.0, -5.0),
        std::complex<double>(-5.0, -1.0),
        std::complex<double>(-5.0, -3.0),
        std::complex<double>(-1.0, 7.0),
        std::complex<double>(-1.0, 5.0),
        std::complex<double>(-1.0, 1.0),
        std::complex<double>(-1.0, 3.0),
        std::complex<double>(-1.0, -7.0),
        std::complex<double>(-1.0, -5.0),
        std::complex<double>(-1.0, -1.0),
        std::complex<double>(-1.0, -3.0),
        std::complex<double>(-3.0, 7.0),
        std::complex<double>(-3.0, 5.0),
        std::complex<double>(-3.0, 1.0),
        std::complex<double>(-3.0, 3.0),
        std::complex<double>(-3.0, -7.0),
        std::complex<double>(-3.0, -5.0),
        std::complex<double>(-3.0, -1.0),
        std::complex<double>(-3.0, -3.0),
        std::complex<double>(7.0, 7.0),
        std::complex<double>(7.0, 5.0),
        std::complex<double>(7.0, 1.0),
        std::complex<double>(7.0, 3.0),
        std::complex<double>(7.0, -7.0),
        std::complex<double>(7.0, -5.0),
        std::complex<double>(7.0, -1.0),
        std::complex<double>(7.0, -3.0),
        std::complex<double>(5.0, 7.0),
        std::complex<double>(5.0, 5.0),
        std::complex<double>(5.0, 1.0),
        std::complex<double>(5.0, 3.0),
        std::complex<double>(5.0, -7.0),
        std::complex<double>(5.0, -5.0),
        std::complex<double>(5.0, -1.0),
        std::complex<double>(5.0, -3.0),
        std::complex<double>(1.0, 7.0),
        std::complex<double>(1.0, 5.0),
        std::complex<double>(1.0, 1.0),
        std::complex<double>(1.0, 3.0),
        std::complex<double>(1.0, -7.0),
        std::complex<double>(1.0, -5.0),
        std::complex<double>(1.0, -1.0),
        std::complex<double>(1.0, -3.0),
        std::complex<double>(3.0, 7.0),
        std::complex<double>(3.0, 5.0),
        std::complex<double>(3.0, 1.0),
        std::complex<double>(3.0, 3.0),
        std::complex<double>(3.0, -7.0),
        std::complex<double>(3.0, -5.0),
        std::complex<double>(3.0, -1.0),
        std::complex<double>(3.0, -3.0) };
public:
    demapper();
    demapper(int M);

    std::vector<int> step(std::vector<std::complex<double>> noisy_sig);

};

#endif
