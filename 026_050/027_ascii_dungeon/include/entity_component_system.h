#ifndef ENTITY_COMPONENT_SYSTEM_H
#define ENTITY_COMPONENT_SYSTEM_H
#include <stdint.h>
/**
 * @brief Enum for containing all types of components.
 * 
 * Includes COMPONENT_NONE and COMPONENT_MAX values.
 */
typedef enum Component_Type Component_Type;

/**
 * @brief Struct for containing 2 integer point values.
 * 
 * Has {int} x and {int} y for struct members.
 */
typedef struct Vector_2i Vector_2i;

/**
 * @brief Struct Redefinition of Vector_2i as position for use with ECS.
 * 
 * Has {int} x and {int} y for struct members.
 */
typedef Vector_2i Component_Position;

/**
 * @brief Struct Redefinition of Vector_2i as velocity for use with ECS.
 *
 * Has {int} x and {int} y for struct members.
 */
typedef Vector_2i Component_Velocity;

/**
 * @brief Struct Redefinition of Vector_2i as input for use with ECS.
 * 
 * Has {int} x and {int} y for struct members.
 */
typedef Vector_2i Component_Input;

/**
 * @brief Struct for defining an Entity for use with ECS.
 * 
 * Has {Component_Mask} mask and {Component* [COMPONENT_MAX]} component_list for struct members.
 */
typedef struct Entity Entity;

/**
 * @brief Struct for defining a System for use with ECS.
 * 
 * Has {System_Function} update and {Component_Mask} required_components for struct members.
 */
typedef struct System System;

/**
 * @brief Union for allowing all Component_Types do be stored in the same memory space.
 * 
 * Has all Components as struct members.
 */
typedef union Component_Memory_Pool Component;

/**
 * @brief Component_Mask is used to keep track of what components are being used by an Entity or System.
 * 
 * Components are bitwised or'd into the mask using component_add();
 */
typedef uint32_t Component_Mask;

/**
 * @brief Function Pointer meant to be part of a System for use with ECS.
 * 
 * Each Function Pointer returns void and takes a pointer to an entity array and the array's size as parameters.
 */
typedef void (*System_Function)(Entity * entities, size_t size);

#endif