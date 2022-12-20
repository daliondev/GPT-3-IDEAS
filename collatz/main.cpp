#include <iostream>
#include <vector>

std::vector<int> collatz(int n) {
    // Initialize the list to store the numbers and the counter for the number of iterations
    std::vector<int> collatz_list;
    int counter = 0;

    // Continuously apply the Collatz conjecture until we reach the number 1
    while (n != 1) {
        // If the current number is even, divide it by 2. If it is odd, multiply it by 3 and add 1
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }

        // Append the current number to the list
        collatz_list.push_back(n);

        // Increment the counter for the number of iterations
        counter++;
    }

    // Append the number 1 to the list and return the list and the counter
    collatz_list.push_back(1);
    return collatz_list;
}

int main() {
    // Test the function with the number 27
    std::vector<int> collatz_list = collatz(27);

    // Print the list of numbers
    for (int i : collatz_list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Print the number of iterations
    std::cout << collatz_list.size() - 1 << std::endl;

    // Find the maximum number in the list
    int max_num = collatz_list[0];
    for (int i : collatz_list) {
        if (i > max_num) {
            max_num = i;
        }
    }
    std::cout << max_num << std::endl;

    return 0;
}
