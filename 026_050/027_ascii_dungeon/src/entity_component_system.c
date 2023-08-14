#include "entity_component_system.h"

enum Component_Type {
    COMPONENT_NONE = 0,
    COMPONENT_POSITION,
    COMPONENT_VELOCITY,
    COMPONENT_INPUT,
    COMPONENT_MAX
};

union Component_Memory_Pool {
    Component_Position position;
    Component_Velocity velocity;
    Component_Input input;
};

struct Vector_2i{
    int32_t x;
    int32_t y;
};

struct Entity {
    Component_Mask mask;
    Component * component_list[COMPONENT_MAX];
};

struct System {
    System_Function update;
    Component_Mask required_components;
};