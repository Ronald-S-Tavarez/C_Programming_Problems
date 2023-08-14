#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>

/**
 * @param a integer operand one
 * @param b integer operand two
 * @return int64_t The larger of the two values or one of the two if they are equal.
 */
int64_t utility_max(int64_t a, int64_t b);

/**
 * @param a integer operand one
 * @param b integer operand two
 * @return int64_t The Smaller of the two values or one of thhe two if they are equal.
 */
int64_t utility_min(int64_t a, int64_t b);

/**
 * @param value Value to be clamped
 * @param min minimum value breakpoint
 * @param max maximum value breakpoint
 * @return int64_t A value that is guaranteed to be between min and max.
 */
int64_t utility_clamp(int64_t value, int64_t min, int64_t max);


#endif