# Collatz Conjeture

The conjecture asks whether repeating two simple arithmetic operations will eventually transform every positive integer into 1. It concerns sequences of integers in which each term is obtained from the previous term as follows: if the previous term is even, the next term is one half of the previous term. If the previous term is odd, the next term is 3 times the previous term plus 1. 

[![collatz](https://user-images.githubusercontent.com/111100025/196279601-763cd88f-a571-40d7-9544-137a078af49b.png)](https://en.wikipedia.org/wiki/Collatz_conjecture#:~:text=The%20Collatz%20conjecture%20is%20one,every%20positive%20integer%20into%201.)

The Collatz conjecture, also known as the 3x+1 conjecture, is a mathematical problem that states that for any positive integer n, the following process will eventually reach the number 1:

1. If n is even, divide it by 2.
2. If n is odd, multiply it by 3 and add 1.
For example, starting with the number 10, the sequence of numbers generated by the above process is: [5, 16, 8, 4, 2, 1]

The conjecture is that this process will eventually reach the number 1 for any positive integer n.


## About repo
This repository seeks to recreate the collatz conjecture in a pure way in different languages, using only dependencies that the language brings with it.

#### must meet 2 fundamental parameters which are

• Each number passed by should be added to a list

• You must create a search engine that returns the largest number that was reached with the number that was given as input
