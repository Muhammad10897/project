#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <assert.h>

#define STRING_SIZE 60

typedef unsigned int id_t;   //
typedef unsigned char age_t; // when make it typedef unsigned short that makes a bug!
typedef struct tag_employee
{
    id_t id;
    char name[STRING_SIZE];
    age_t age;
    char title[STRING_SIZE];
    float salary;
} employee_t;

typedef struct tag_node
{
    employee_t employee;
    struct tag_node *next; // pointer to structure
} node_t;

typedef struct
{
    node_t *head;
    int size;
} LinkedList_t;

typedef enum
{
    LL_OK,
    LL_NULL_POINTER,
    LL_NODE_NOT_FOUND,
    LL_NODE_NOT_CREATED,
    LL_EMPTY
} EN_SLL_status_t;

typedef enum
{
    ID = 1,
    NAME,
    AGE,
    TITLE,
    SALARY
} EN_coloumn_no_t;

typedef enum
{
    DISPLAY_DATABASE = 1,
    VIEW_EMPLOYEE,
    ADD_EMPLOYEE,
    MODIFY_EMPLOYEE,
    DELETE_EMPLOYEE,
    EXIT_PROGRAM
} EN_user_options;

// a function to draw the table header
void printTableHeader();

/* a helper function to get the id by which we search, view, modify, or delete some employee
we make it as it is reprating in the code */
id_t get_id();

// function to get a unique id
id_t get_unique_id(LinkedList_t *my_linked_list);

// to get interger
int get_integer();

// to get interger
float get_number();

// get a string with maximum specific length
char * get_limited_string();

// funtion to create a linked list
LinkedList_t *LL_create_linked_list();

// funciton to diplay the data in the list
EN_SLL_status_t LL_display(LinkedList_t *my_linked_list);

// function to search for a node by value
node_t *LL_search_node(LinkedList_t *my_linked_list, id_t id);

// a helper function to view_employee function, to display some node
EN_SLL_status_t display_node(node_t *sample_employee);

// a function to view some employee
void view_employee(LinkedList_t *my_linked_list);

// funciton to create a node. It's an assistant function for LL_append_node function
node_t *LL_create_node(employee_t *sample_employee);

// funciton to append a node. It's an assistant function for add_employee function
EN_SLL_status_t LL_append_node(LinkedList_t *my_linked_list, employee_t *sample_employee);

// function to add an employee in our database
EN_SLL_status_t add_employee(LinkedList_t *my_linked_list);

// modify some node data
EN_SLL_status_t modify_employee(LinkedList_t *my_linked_list);

// function to delete a node by value
EN_SLL_status_t delete_employee(LinkedList_t *my_linked_list);

// funciton to  free the linked list
EN_SLL_status_t LL_free(LinkedList_t *my_linked_list);

// additional functions: 1- check if id is unique
char is_id_unique(LinkedList_t *my_linked_list, id_t id);

#endif