clear, clc, close all

data_cpp = readmatrix("results/qam_4_results.txt");
numBits = data_cpp(1);
ber_cpp = data_cpp(3:2:end);
EbN0 = data_cpp(2:2:end);
N0 = 1./(10.^(EbN0./10));

ber_mtlb = berawgn(EbN0, 'qam', 4);

figure();
semilogy(EbN0, ber_cpp, 'o-');
hold on;
semilogy(EbN0, ber_mtlb);
grid on
legend("Реализация в C++", "Реализация в MATLAB")
title("Помехоустойчивость 4-QAM");
xlabel("EbN0");
ylabel("BER");

figure();
semilogy(N0, ber_cpp, 'o-');
hold on;
semilogy(N0, ber_mtlb);
grid on
legend("Реализация в C++", "Реализация в MATLAB")
title("Зависимость BER от дисперсии шума 4-QAM");
xlabel("Дисперсия шума");
ylabel("BER");