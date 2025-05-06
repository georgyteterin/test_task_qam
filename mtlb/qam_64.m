clear, clc

data_cpp = readmatrix("results/qam_64_results.txt");
numBits = data_cpp(1);
ber_cpp = data_cpp(3:2:end);
EbN0 = data_cpp(2:2:end);
N0 = 1./(10.^(EbN0./10));
variance = N0./2;

ber_mtlb = zeros(size(EbN0));

for k=1:length(EbN0)
    bits = randi([0 1], numBits, 1);
    txSig = qammod(bits, 64, "InputType","bit");
    rxSig = awgn(txSig, EbN0(k));
    out_bits = qamdemod(rxSig, 64, "OutputType", "bit");
    ber_mtlb(k) = biterr(bits, out_bits)/numBits;
end

figure();
semilogy(EbN0, ber_cpp, 'o-');
hold on;
semilogy(EbN0, ber_mtlb);
grid on
legend("Реализация в C++", "Реализация в MATLAB")
title("Помехоустойчивость 64-QAM");
xlabel("EbN0");
ylabel("BER");

figure();
semilogy(variance, ber_cpp, 'o-');
hold on;
semilogy(variance, ber_mtlb);
grid on
legend("Реализация в C++", "Реализация в MATLAB")
title("Зависимость BER от дисперсии шума 64-QAM");
xlabel("Дисперсия шума");
ylabel("BER");