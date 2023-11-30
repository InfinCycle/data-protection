#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

long long mod_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

long long baby_step_giant_step(long long G, long long H, long long Q) {
    long long m = static_cast<long long>(sqrt(Q)) + 1;

    unordered_map<long long, long long> baby_steps;
    for (long long i = 0; i < m; ++i) {
        long long val = mod_pow(G, i, Q);
        baby_steps[val] = i;
    }

    long long inverse = mod_pow(mod_pow(G, m * (Q - 2), Q), 1, Q);

    for (long long j = 0; j < m; ++j) {
        long long val = (H * mod_pow(inverse, j, Q)) % Q;
        if (baby_steps.find(val) != baby_steps.end()) {
            long long x = (j * m + baby_steps[val]);
            return x;
        }
    }

    return -1;
}

int main() {
    long long G, H, Q;
    cin >> G >> H >> Q;

    long long result = baby_step_giant_step(G, H, Q);

    cout << result << endl;

    return 0;
}
