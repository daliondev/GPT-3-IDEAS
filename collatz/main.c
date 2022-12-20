#include <stdio.h>
#include <stdlib.h>

int collatz(int n) {
    // Initialize the counter for the number of iterations
    int counter = 0;

    // Continuously apply the Collatz conjecture until we reach the number 1
    while (n != 1) {
        // If the current number is even, divide it by 2. If it is odd, multiply it by 3 and add 1
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }

        // Increment the counter for the number of iterations
        counter++;
    }

    // Return the counter
    return counter;
}

int main() {
    // Test the function with the number 27
    int counter = collatz(27);

    // Print the counter
    printf("%d\n", counter);

    return 0;
}
