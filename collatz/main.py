def collatz(n):
    # Initialize the list to store the numbers and the counter for the number of iterations
    collatz_list = []
    counter = 0

    # Continuously apply the Collatz conjecture until we reach the number 1
    while n != 1:
        # If the current number is even, divide it by 2. If it is odd, multiply it by 3 and add 1
        if n % 2 == 0:
            n = n // 2
        else:
            n = n * 3 + 1

        # Append the current number to the list
        collatz_list.append(n)

        # Increment the counter for the number of iterations
        counter += 1

    # Return the list and the counter
    return collatz_list, counter

# Test the function with the number 27
collatz_list, counter = collatz(27)

# Print the list of numbers and the counter
print(collatz_list)
print(counter)

# Get the largest number from the list
largest = max(collatz_list)
print(largest)



