#ifndef VECTOR_2I_H
#define VECTOR_2I_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief A struct containing 2 elements, used to represent any pair of integers.
 * Has members ( x : int ) and ( y : int ).
 */
typedef struct Vector_2i {
    int64_t x;
    int64_t y;    
} Vector_2i;

/**
 * @return Vector_2i - Returns a vector with components (x: 0, y: 0);
 */
Vector_2i vector_2i_zero(void);

/**
 * @return Vector_2i - Returns a vector with components (x: 1, y: 1);
 */
Vector_2i vector_2i_one(void);

/**
 * @return Vector_2i - Returns a vector with components (x: -1, y: 0).
 */
Vector_2i vector_2i_left(void);

/**
 * @return Vector_2i - Returns a vector with components (x: 1, y: 0).
 */
Vector_2i vector_2i_right(void);

/**
 * @brief Vector_2i - Returns a vector with components (x: 0, y: -1).
 */
Vector_2i vector_2i_up(void);

/**
 * @brief Vector_2i - Returns a vector with components (x: 0, y: 1).
 */
Vector_2i vector_2i_down(void);

/**
 * @param source Vector that contains copy data.
 * @return Vector_2i - Returns a vector with components (x: source->x, y: source->y).
 */
Vector_2i vector_2i_copy(const Vector_2i * source);

/**
 * @param x x component of new vector.
 * @param y Y component of new vector.
 * @return Vector_2i - Returns a vector with components (x: x, y: y);
 */
Vector_2i vector_2i_from(int64_t x, int64_t y);

/**
 * @brief Assigns a vector_2i's components to be equal to the value of x and y;
 *
 * @param destination The vector to be modified. 
 * @param x The X component to be assigned to the vector.
 * @param y The Y component to be assigned to the vector.
 */
void vector_2i_assign(Vector_2i * destination, int64_t x, int64_t y);

/**
 * @param source Vector to be copied from.
 * @return Returns a vector with components (x: abs(source->x), y: abs(source->y));
 */
Vector_2i vector_2i_abs(const Vector_2i * source);

/**
 * @param source The vector to be calculated from.
 * @return float - The aspect ratio of the vector's components
 */
float vector_2i_aspect_ratio(const Vector_2i * source);

/**
 * @param source The vector with original values.
 * @param min The minimum value of both components.
 * @param max The maximum value of both components.
 * @return Vector_2i - Returns a vector with components (x: clamp(source->x, min->x, max->x), y: clamp(source->y, min->y, max->y));
 */
Vector_2i vector_2i_clamp(const Vector_2i * source, const Vector_2i * min, const Vector_2i * max);

/**
 * @param source The Vector to be calculated from.
 * @return float - The length (magnitude) of the vector.
 */
float vector_2i_length(const Vector_2i * source);

/**
 * @param source The vector to be calculated from.
 * @return int - The squared length (magnitude) of the vector.
 */
int vector_2i_length_squared(const Vector_2i * source);

/**
 * @param source The vector to be calculated from.
 * @return Vector_2i - Returns a vector with components (x: (source->x * -1), y: (source->y * -1));
 */
Vector_2i vector_2i_sign(Vector_2i * source);

/**
 * @param a A vector to be checked for equality to b.
 * @param b A vector to be checked for equality to c.
 * @return true - If both components of each vector are equal.
 * @return false - If x or y components of one vector are not equal to the x or y components of the other.
 */
bool vector_2i_equal(const Vector_2i * a, const Vector_2i * b);

/**
 * @param a The vector dividend.
 * @param b The vector divisor.
 * @return Vector_2i - Returns a vector with components (x: (abs(a->x) % abs(b->x)), y: (abs(a->y) % abs(b->y)));
 */
Vector_2i vector_2i_modulo(const Vector_2i * a, const Vector_2i * b);

/**
 * @param dividend The vector dividend.
 * @param divisor The integer divisor.
 * @return Vector_2i - Returns a vector with components (x: (abs(divided->x) % abs(divisor)), y: (abs(dividend->y) % abs(divisor)));
 */
Vector_2i vector_2i_modulo_int(const Vector_2i * dividend, int64_t divisor);

/**
 * @param a The vector multiplicand.
 * @param b The vector multiplier.
 * @return Vector_2i - Returns a vector with components (x: (a->x * b->x), y: (a->y * b->y));
 */
Vector_2i vector_2i_multiply(const Vector_2i * a, const Vector_2i * b);

/**
 * @param multiplicand The vector multiplicand.
 * @param multiplier The integer multiplier.
 * @return Vector_2i - Returns a vector with components (x: (multiplicand->x * multiplier), y: (multiplicand->y * multiplier));
 */
Vector_2i vector_2i_multiply_int(const Vector_2i * multiplicand, int64_t multiplier);

/**
 * @param a The first vector addend;
 * @param b The second vector addend;
 * @return Vector_2i - Returns a vector with components (x: (a->x + b->x), y: (a->y + b->y));
 */
Vector_2i vector_2i_add(const Vector_2i * a, const Vector_2i * b);

/**
 * @param a The first addend : vector;
 * @param b The second addend : int64_t;
 * @return Vector_2i - Returns a vector with components (x: (a->x + b), y: (a->y + b));
 */
Vector_2i vector_2i_add_int(const Vector_2i * a, int64_t b);

/** 
 * @param a The vector minuend.
 * @param b The vector subtrahend. 
 * @return Vector_2i - Returns a vector with components (x: (a->x - b->x), y: (a->y - b->y)); 
 */
Vector_2i vector_2i_subtract(const Vector_2i * a, const Vector_2i * b);

/** 
 * @param minuend The vector to be subtracted from.
 * @param subtrahend The integer to subtract by. 
 * @return Vector_2i - Returns a vector with components (x: (minuend->x - subtrahend), y: (minuend->y - subtrahend)); 
 */
Vector_2i vector_2i_subtract_int(const Vector_2i * minuend, int64_t subtrahend);

/**
 * @param a The vector dividend;
 * @param b The vector divisor;
 * @return Vector_2i - Returns a vector with components (x: (a->x / b->x), y: (a->y / b->y)); 
 */
Vector_2i vector_2i_divide(const Vector_2i * a, const Vector_2i * b);

/**
 * @param divided The vector divided;
 * @param divisor The int64_t divisor; 
 * @return Vector_2i - Returns a vector with components (x: (dividend->x / divisor), y: (dividend->y / divisor)); 
 */
Vector_2i vector_2i_divide_int(const Vector_2i * divided, int64_t divisor);

/**
 * @brief Prints vector to the console for debug purposes.
 * @param source The vector to print.
 */
void vector_2i_print(const Vector_2i * source);

#endif