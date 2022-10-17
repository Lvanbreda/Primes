#include <iostream> // use the standard library of C++
#include <cmath> // use predefined math functions
#include <ctime> // used to measure time taken
#include <chrono> // used to measure time taken

int current_number = 3; // define an integer variable to calculate the primes with
int current_prime = 0; // define a number used to change numbers in our set of primes
constexpr std::size_t ARRAY_SZ = 10000000000; // prevent a stack overflow
int* prime_array = new int[ARRAY_SZ]; // define the set of integers where we put all primes in of size 10^10
bool is_prime; // define an argument to check if the current number is prime

int main() { // initialise the code
    std::chrono::time_point beginTime = std::chrono::system_clock::now(); // note down the start time
    prime_array[0] = 2; // add 2 to the list
    current_prime++; // increment the current prime count by 1
    while (current_number < ARRAY_SZ) { // keeps calculating until we have 10^10 primes
        for (int i = 0; i < current_prime; ++i) { // looks if the current number is divisible by any prime in the set
            if (current_number % prime_array[i] == 0) {
                is_prime = false; // if it is divisible by any prime in the set, it is not defined as a prime
                break; // break the loop if it is divisible
            }
            else { // if it is not divisible
                if(prime_array[i] > sqrt(current_number)){ // if the number we're dividing by is bigger than the square root of the number we're checking, (cont.)
                    break; // (cont.) break the loop
                }
                is_prime = true; // define the number as prime
            }
        }

        if (is_prime) { // if the number is prime, then
            prime_array[current_prime] = current_number; // add the number to the set
            current_prime++; // increment the current prime count by one after this cycle
            std::cout << "Prime: " << current_number << std::endl; // print the prime we just found
        }

        current_number += 2; // increment the number we check by 2
    }
    std::chrono::time_point endTime = std::chrono::system_clock::now(); // note down the end time

    std::chrono::duration<double> elapsed_seconds = endTime - beginTime; // calculate the total time

    std::cout << "elapsed: " << elapsed_seconds.count() << std::endl; // print the total time

    free(prime_array); // free the memory occupied by the array
    return 0; // end the program
}