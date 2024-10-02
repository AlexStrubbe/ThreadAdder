#include "functions.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  ///< Mutex for thread safety

/**
 * @brief This file contains functions for five threads that calculate the sum
 *        of segments of an integer array. Each thread processes a specific
 *        portion of the array, measuring the elapsed time for the computation.
 *        The results, including the computed sum and time taken, are returned
 *        through a dynamically allocated Result structure.
 */
void *Adder1(void *param) {
  Result *result =
      (Result *)malloc(sizeof(Result));  // Allocate memory for result
  if (result == NULL) {
    perror("Failed to allocate memory for result");
    pthread_exit(NULL);
  }

  clock_t start = clock();  ///< Start timer
  long sum = 0;             ///< Initialize sum
  int *ptr = (int *)param;  ///< Cast parameter to integer pointer

  pthread_mutex_lock(&mutex);  // Lock the mutex for the whole loop
  for (int i = 0; i < 200000; i++) {
    sum += ptr[i];  ///< Sum the segment
  }
  pthread_mutex_unlock(&mutex);  // Unlock the mutex after the loop

  result->value = sum;  ///< Store computed sum
  clock_t finish = clock();
  result->time =
      (double)(finish - start) / CLOCKS_PER_SEC;  // Store elapsed time

  pthread_exit((void *)result);
}

void *Adder2(void *param) {
  Result *result =
      (Result *)malloc(sizeof(Result));  // Allocate memory for result
  if (result == NULL) {
    perror("Failed to allocate memory for result");
    pthread_exit(NULL);
  }

  clock_t start = clock();  ///< Start timer
  long sum = 0;             ///< Initialize sum
  int *ptr = (int *)param;  ///< Cast parameter to integer pointer

  pthread_mutex_lock(&mutex);  // Lock the mutex for the whole loop
  for (int i = 200000; i < 400000; i++) {
    sum += ptr[i];  ///< Sum the segment
  }
  pthread_mutex_unlock(&mutex);  // Unlock the mutex after the loop

  result->value = sum;  ///< Store computed sum
  clock_t finish = clock();
  result->time =
      (double)(finish - start) / CLOCKS_PER_SEC;  // Store elapsed time

  pthread_exit((void *)result);
}

void *Adder3(void *param) {
  Result *result =
      (Result *)malloc(sizeof(Result));  // Allocate memory for result
  if (result == NULL) {
    perror("Failed to allocate memory for result");
    pthread_exit(NULL);
  }

  clock_t start = clock();  ///< Start timer
  long sum = 0;             ///< Initialize sum
  int *ptr = (int *)param;  ///< Cast parameter to integer pointer

  pthread_mutex_lock(&mutex);  // Lock the mutex for the whole loop
  for (int i = 400000; i < 600000; i++) {
    sum += ptr[i];  ///< Sum the segment
  }
  pthread_mutex_unlock(&mutex);  // Unlock the mutex after the loop

  result->value = sum;  ///< Store computed sum
  clock_t finish = clock();
  result->time =
      (double)(finish - start) / CLOCKS_PER_SEC;  // Store elapsed time

  pthread_exit((void *)result);
}

void *Adder4(void *param) {
  Result *result =
      (Result *)malloc(sizeof(Result));  // Allocate memory for result
  if (result == NULL) {
    perror("Failed to allocate memory for result");
    pthread_exit(NULL);
  }

  clock_t start = clock();  ///< Start timer
  long sum = 0;             ///< Initialize sum
  int *ptr = (int *)param;  ///< Cast parameter to integer pointer

  pthread_mutex_lock(&mutex);  // Lock the mutex for the whole loop
  for (int i = 600000; i < 800000; i++) {
    sum += ptr[i];  ///< Sum the segment
  }
  pthread_mutex_unlock(&mutex);  // Unlock the mutex after the loop

  result->value = sum;  ///< Store computed sum
  clock_t finish = clock();
  result->time =
      (double)(finish - start) / CLOCKS_PER_SEC;  // Store elapsed time

  pthread_exit((void *)result);
}

void *Adder5(void *param) {
  Result *result =
      (Result *)malloc(sizeof(Result));  // Allocate memory for result
  if (result == NULL) {
    perror("Failed to allocate memory for result");
    pthread_exit(NULL);
  }

  clock_t start = clock();  ///< Start timer
  long sum = 0;             ///< Initialize sum
  int *ptr = (int *)param;  ///< Cast parameter to integer pointer

  pthread_mutex_lock(&mutex);  // Lock the mutex for the whole loop
  for (int i = 800000; i < 1000000; i++) {
    sum += ptr[i];  ///< Sum the segment
  }
  pthread_mutex_unlock(&mutex);  // Unlock the mutex after the loop

  result->value = sum;  ///< Store computed sum
  clock_t finish = clock();
  result->time =
      (double)(finish - start) / CLOCKS_PER_SEC;  // Store elapsed time

  pthread_exit((void *)result);
}
