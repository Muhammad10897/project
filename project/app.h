#ifndef APP
#define APP

#include "single_linked_list.h"

typedef enum
{
    DISPLAY_DATABASE = 1,
    VIEW_EMPLOYEE,
    ADD_EMPLOYEE,
    MODIFY_EMPLOYEE,
    DELETE_EMPLOYEE,
    EXIT_PROGRAM
} EN_user_options;

// function to add the initial data
void initializing_data();

void run();

#endif