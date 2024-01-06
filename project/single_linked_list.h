#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include "underground.h"

/*********************************Defining Employee Data****************************************/
#define NAME_SIZE 60
#define TITLE_SIZE 60


typedef unsigned char age_t; /* when make it typedef unsigned short that makes a bug!
our datatype here is a structure as the following:*/

typedef struct tag_employee // our data type
{
    id_t id;
    char name[NAME_SIZE];
    age_t age;
    char title[TITLE_SIZE];
    float salary;
} employee_t;
/**************************************************************************************************/

typedef struct tag_node
{
    employee_t employee;
    struct tag_node *next; // pointer to structure (node) >> this pointer points to the stucture
} node_t;

typedef struct
{
    node_t *head;
    int size;
} SingleLinkedList_t;

typedef enum
{
    SLL_OK,
    SLL_NULL_POINTER,
    SLL_NODE_NOT_FOUND,
    SLL_NODE_NOT_CREATED,
    SLL_EMPTY
} EN_SLL_status_t;

typedef enum
{
    ID = 1,
    NAME,
    AGE,
    TITLE,
    SALARY
} EN_coloumn_no_t;

// function to get a unique id
id_t get_unique_id(SingleLinkedList_t *my_linked_list);

// funtion to create a linked list
SingleLinkedList_t *SLL_create_sll(); // sll refers to single linked list

// funciton to create a node. It's an assistant function for LL_append_node function
node_t *SLL_create_node(employee_t *sample_employee);

// funciton to append a node. It's an assistant function for add_employee function
EN_SLL_status_t SLL_append_node(SingleLinkedList_t *my_sll, employee_t *sample_employee);

//// funciton to diplay the data in the list
EN_SLL_status_t SLL_display(SingleLinkedList_t *my_sll);

// function to search for a node by value
node_t *SLL_search_by_id(SingleLinkedList_t *my_sll, id_t id);

// funciton to  free the linked list
EN_SLL_status_t SLL_free(SingleLinkedList_t *my_sll);

// function to delete a node by value
EN_SLL_status_t SLL_delete_employee(SingleLinkedList_t *my_sll);

// a helper function to view_employee function, to display some node
EN_SLL_status_t SLL_display_node(node_t *sample_employee);

// modify some node data
EN_SLL_status_t SLL_modify_by_id(SingleLinkedList_t *my_sll);

// function to add an employee in our database
EN_SLL_status_t SLL_add_employee(SingleLinkedList_t *my_sll);

// a function to view some employee
void SLL_view_employee(SingleLinkedList_t *my_sll);

// additional functions: 1- check if id is unique
char SLL_is_id_unique(SingleLinkedList_t *my_sll, id_t id);

#endif