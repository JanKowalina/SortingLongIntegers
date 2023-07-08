#include <iostream>
#include <cstring>

// Function to check if two strings need to be swapped
bool swapping(const char* d1, const char* d2) {
    if (std::strlen(d1) == std::strlen(d2)) {
        // If the strings have the same length, compare character by character
        int i = 0;
        while (d1[i] == d2[i] && d1[i] != '\0') {
            i++;
        }
        return d1[i] > d2[i]; // Swap if the current character of d1 is greater than d2
    }
    else {
        return std::strlen(d1) > std::strlen(d2); // Swap if the length of d1 is greater than d2
    }
}

// Function to exchange two strings
void exchange(char** d1, char** d2) {
    char* exchanger = *d1;
    *d1 = *d2;
    *d2 = exchanger;
}

// Shell sort implementation for sorting the array of strings
void shellSort(char** dates, int start, int end) {
    int step = (end - start) / 2;
    bool swapped;
    while (step >= 1) {
        for (int i = start; i < end - step; i++) {
            int preceding = i;
            swapped = true;
            while (preceding >= start && swapped) {
                swapped = swapping(dates[preceding], dates[preceding + step]);
                if (swapped)
                    exchange(&dates[preceding], &dates[preceding + step]);

                preceding -= step;
            }
        }
        step /= 2;
    }
}

int main() {
    int n;
    std::cin >> n;

    char** numbers = new char*[n];

    int negativeCounter = 0;
    int positiveCounter = n - 1;

    // Read input numbers and store them in appropriate indices
    for (int i = 0; i < n; i++) {
        char s[1000];
        std::cin >> s;
        int length = std::strlen(s);
        if (s[0] == '-') {
            numbers[negativeCounter] = new char[length + 1];
            std::strcpy(numbers[negativeCounter], s);
            negativeCounter++;
        }
        else {
            numbers[positiveCounter] = new char[length + 1];
            std::strcpy(numbers[positiveCounter], s);
            positiveCounter--;
        }
    }

    // Sort negative numbers in descending order
    if (negativeCounter != 0)
        shellSort(numbers, 0, negativeCounter);

    // Sort positive numbers in descending order
    if (negativeCounter != n)
        shellSort(numbers, negativeCounter, n);

    // Print the sorted array
    for (int i = negativeCounter - 1; i >= 0; i--) {
        std::cout << numbers[i] << std::endl;
    }
    for (int i = negativeCounter; i < n; i++) {
        std::cout << numbers[i] << std::endl;
    }

    // Deallocate memory for dynamically allocated strings
    for (int i = 0; i < n; i++) {
        delete[] numbers[i];
    }
    delete[] numbers;

    return 0;
}
