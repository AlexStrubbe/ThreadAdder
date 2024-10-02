#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

/**
 * @brief Main function to create threads for calculating the sum of tangent
 * values in an array of integers.
 *
 * This program initializes an array of 1,000,000 elements, filling it with the
 * tangent values of integers from 1 to 1,000,000. It then creates five threads
 * to compute the sum of different segments of the array in parallel. Finally,
 * the main thread collects the results, computes the total sum and the elapsed
 * time for each thread, and prints the results to the console.
 *
 * @return int Exit status of the program.
 */
int main() {
  int i = 0;  ///< Loop index for array initialization
  pthread_t adder1, adder2, adder3, adder4, adder5;  ///< Thread identifiers
  Result *result1, *result2, *result3, *result4, *result5;  ///< Result pointers

  // Allocate memory for the decimal array
  int *decimal = malloc(1000000 * sizeof(int));
  if (decimal == NULL) {
    perror(
        "Failed to allocate memory");  ///< Error handling for memory allocation
    exit(EXIT_FAILURE);
  }

  // Fill the decimal array with tangent values of integers from 1 to 1,000,000
  for (i = 0; i < 1000000; i++) {
    decimal[i] = tan(1 + i);
  }

  // Create threads to compute sums of different segments of the array
  pthread_create(&adder1, NULL, Adder1, (void *)decimal);
  pthread_create(&adder2, NULL, Adder2, (void *)decimal);
  pthread_create(&adder3, NULL, Adder3, (void *)decimal);
  pthread_create(&adder4, NULL, Adder4, (void *)decimal);
  pthread_create(&adder5, NULL, Adder5, (void *)decimal);

  // Wait for all threads to finish and collect their results
  pthread_join(adder1, (void **)&result1);
  pthread_join(adder2, (void **)&result2);
  pthread_join(adder3, (void **)&result3);
  pthread_join(adder4, (void **)&result4);
  pthread_join(adder5, (void **)&result5);

  // Calculate the total sum from all thread results
  long total_sum = result1->value + result2->value + result3->value +
                   result4->value + result5->value;
  printf("This is the total value of the sum: %ld\n", total_sum);

  // Print the time taken by each thread
  printf("Total time elapsed for T1: %f\n", result1->time);
  printf("Total time elapsed for T2: %f\n", result2->time);
  printf("Total time elapsed for T3: %f\n", result3->time);
  printf("Total time elapsed for T4: %f\n", result4->time);
  printf("Total time elapsed for T5: %f\n", result5->time);

  // Calculate and print the total elapsed time
  double total_time = result1->time + result2->time + result3->time +
                      result4->time + result5->time;
  printf("Total time elapsed: %f\n", total_time);

  // Free allocated memory
  free(decimal);  // Free the array of integers
  free(result1);  // Free the result structures
  free(result2);
  free(result3);
  free(result4);
  free(result5);

  return 0;
}
