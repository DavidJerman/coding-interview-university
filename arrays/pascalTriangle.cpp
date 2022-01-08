#include <iostream>
#include <iomanip>

/*
 * int [][] pt = new int[n][];
 * for (i = 0 to < n)
 *     pt[i] = new int[n + 1]
 *     pt[i][0] = 1
 *     for (j = 1 to j < i)
 *         pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j]
 *     pt[i][i] = 1
 * end
 */

void pascalTriangle(int n) {
    int ** arr = new int * [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[i + 1];
        arr[i][0] = 1;
        for (int j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        arr[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) std::cout << "   ";
        for (int j = 0; j < n / 2 - (i / 2 + 1); j++)
            std::cout << "      ";
        for (int j = 0; j <= i; j++)
            std::cout << std::setw(5) << arr[i][j] << " ";
        std::cout << std::endl;
    }

}

int main() {

    pascalTriangle(20);

    return 0;
}