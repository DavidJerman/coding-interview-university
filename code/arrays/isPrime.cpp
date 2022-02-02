#include <iostream>

void printPrimes(int n) {
    bool prime[n + 1];
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    for (int divisor = 2; divisor * divisor <= n; divisor++) {
        if (prime[divisor]) {
            for (int i = divisor * 2; i <= n; i += divisor)
                prime[i] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (prime[i]) std::cout << i << " ";
    std::cout << std::endl;
}

int main() {

    printPrimes(11);

    return 0;
}
