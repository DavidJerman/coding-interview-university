#include <iostream>

/**
 * Recursive binary search
 *
 * @param arr Array to search
 * @param left Left index
 * @param right Right index
 * @param x Sought value
 * @return Found value's index
 */
int binSearchR(const int * const arr, const int left, const int right, const int & x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        else {
            if (arr[mid] > x) return binSearchR(arr, left, mid - 1, x);
            else return binSearchR(arr, mid + 1, right, x);
        }
    } else return -1;
}

/**
 * Recursive binary search wrapper
 *
 * @param arr Array to search
 * @param MAX Maximum size of the array
 * @param x Sought value
 * @return Found value's index
 */
int binSearchR(const int * const arr, const size_t & MAX, const int x) {
    int left = 0, right = MAX - 1;
    return binSearchR(arr, left, right, x);
}

/**
 * Binary search
 *
 * @param arr Array to search
 * @param MAX Maximum size of the array
 * @param x Sought value
 * @return Found value's index
 */
int binSearch(const int * const arr, const size_t & MAX, const int x) {
    int left = 0, right = MAX - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        else {
            if (arr[mid] > x) right = mid - 1;
            else left = mid + 1;
        }
    }
    return -1;
}

int main() {

    // Creating the array
    const size_t MAX = 1024;
    int * arr;
    arr = new int[MAX];
    for (auto i = 0; i < MAX; i++) arr[i] = i + 1;

    // Binary searching
    std::cout << "Index  (743): " << binSearch(arr, MAX, 743) << std::endl;
    // Recursive
    std::cout << "Index (1023): " << binSearchR(arr, MAX, 1023) << std::endl;

    return 0;
}
