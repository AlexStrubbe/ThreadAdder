#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>  // Include pthread header for mutex types

/// Global mutex for thread safety.
extern pthread_mutex_t mutex;

/**
 * @struct Result
 * @brief Structure to hold the result of the sum and elapsed time.
 */
typedef struct {
  double time;  ///< Elapsed time for the operation.
  long value;   ///< The computed sum of the values.
} Result;

/// Function prototypes for the adder threads.

/**
 * @brief Function executed by the Adder threads.
 *
 * @param param Pointer to parameters needed by the thread.
 * @return Pointer to the result structure containing the sum and time.
 */
void *Adder1(void *param);
void *Adder2(void *param);
void *Adder3(void *param);
void *Adder4(void *param);
void *Adder5(void *param);

#endif  // FUNCTIONS_H
