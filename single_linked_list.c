#include "single_linked_list.h"

// a function to draw the table header
void printTableHeader()
{
    printf("| %-3s | %-30s | %-5s | %-30s | %-10s | \n", "id", "Name", "Age", "Title", "Salary");
    printf("|-----|--------------------------------|-------|--------------------------------|------------\n");
}

// get integer
int get_integer()
{
    int value;
    char newline; // To capture the Enter key after the number input

    while (1)
    {
        fflush(stdin);
        if (scanf("%d%c", &value, &newline) == 2 && newline == '\n')
        {
            return value;
        }
        else
        {
            // Invalid input, clear the input buffer
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

// get number
float get_number()
{
    float value;
    char newline; // To capture the Enter key after the number input

    while (1)
    {
        fflush(stdin);
        if (scanf("%f%c", &value, &newline) == 2 && newline == '\n')
        {
            return value;
        }
        else
        {
            // Invalid input, clear the input buffer
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

/* a helper function to get the id by which we search, view, modify, or delete some employee
we make it as it is reprating in the code */
id_t get_id()
{
    id_t id;
    printf("enter the employee id: ");
    id = get_integer();
    return id;
}

// function to get a unique id
id_t get_unique_id(LinkedList_t *my_linked_list)
{
    id_t id = 0;
    while (1)
    {
        id = get_id();
        if (is_id_unique(my_linked_list, id))
        {
            return id;
        }
        else
        {
            printf("this id already exist! please enter a different id.\n");
        }
    }
}

// 
char * get_limited_string()
{
    char *string;
    gets(string);
    strlen(string);

}

// funtion to create a linked list
LinkedList_t *LL_create_linked_list()
{
    LinkedList_t *new_linked_list = (LinkedList_t *)malloc(1 * sizeof(LinkedList_t));
    if (new_linked_list == NULL)
    {
        return NULL;
    }
    // now the list is empty
    new_linked_list->size = 0;
    new_linked_list->head = NULL;
    return new_linked_list;
}

// funciton to create a node
node_t *LL_create_node(employee_t *sample_employee)
{
    node_t *newNode = malloc(1 * sizeof(node_t));
    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->employee.id = sample_employee->id;
    strncpy(newNode->employee.name, sample_employee->name, STRING_SIZE);
    newNode->employee.age = sample_employee->age;
    newNode->employee.salary = sample_employee->salary;
    strncpy(newNode->employee.title, sample_employee->title, STRING_SIZE);

    newNode->next = NULL;

    return newNode;
}

// funciton to append node
EN_SLL_status_t LL_append_node(LinkedList_t *my_linked_list, employee_t *sample_employee)
{
    if (my_linked_list == NULL)
    {
        return LL_NULL_POINTER;
    }

    // create new node
    node_t *newNode = LL_create_node(sample_employee);
    if (newNode == NULL)
    {
        return LL_NODE_NOT_CREATED;
    }
    node_t *current = my_linked_list->head;

    my_linked_list->size++;

    // check if the list is empty
    if (my_linked_list->head == NULL)
    {
        my_linked_list->head = newNode;
        return LL_OK;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    // now current points at the last node in the list
    current->next = newNode;

    return LL_OK;
}

// funciton to diplay the data in the list
EN_SLL_status_t LL_display(LinkedList_t *my_linked_list)
{
    if (my_linked_list == NULL)
    {
        return LL_NULL_POINTER;
    }

    if (my_linked_list->head == NULL)
    {
        printf("list is emtpy \n");
        return LL_EMPTY;
    }

    printTableHeader();
    node_t *current = my_linked_list->head;
    while (current != NULL)
    {
        printf("| %-3d | %-30s | %-5d | %-30s | %-10.2f | \n", current->employee.id,
               current->employee.name, current->employee.age, current->employee.title,
               current->employee.salary);
        current = current->next;
    }
    printf("\n");

    return LL_OK;
}

// funciton to  free the linked list
EN_SLL_status_t LL_free(LinkedList_t *my_linked_list)
{
    if (my_linked_list == NULL)
    {
        return LL_NULL_POINTER;
    }

    node_t *current = my_linked_list->head;

    while (current != NULL)
    {
        my_linked_list->head = my_linked_list->head->next;
        free(current);
        current = my_linked_list->head;
    }
    free(my_linked_list);
    return LL_OK;
}

EN_SLL_status_t delete_employee(LinkedList_t *my_linked_list)
{
    if (my_linked_list == NULL)
    {
        return LL_NULL_POINTER;
    }

    if (my_linked_list->head == NULL)
    {
        printf("empty list \n");
        return LL_EMPTY;
    }

    id_t id = get_id();
    node_t *current = my_linked_list->head, *prev;

    if (my_linked_list->head->employee.id == id)
    {
        my_linked_list->head = my_linked_list->head->next;
        free(current);
        my_linked_list->size--;
        return LL_OK;
    }

    while (current != NULL)
    {
        if (current->employee.id == id)
        {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("value not found\n");
        return LL_NODE_NOT_FOUND;
    }

    prev->next = current->next;

    free(current);
    my_linked_list->size--;

    return LL_OK;
}

node_t *LL_search_node(LinkedList_t *my_linked_list, id_t id)
{
    if (my_linked_list == NULL)
    {
        return NULL;
    }
    if (my_linked_list->head == NULL)
    {
        printf("empty list \n");
        return NULL;
    }

    node_t *current = my_linked_list->head;

    while (current != NULL)
    {
        if (current->employee.id == id)
        {
            return current;
        }
        current = current->next;
    }

    printf("value not found\n");
    return NULL;
}

EN_SLL_status_t display_node(node_t *sample_node)
{
    if (sample_node == NULL)
    {
        return LL_NODE_NOT_FOUND;
    }

    printTableHeader();
    printf("| %-3d | %-30s | %-5d | %-30s | %-10.2f | \n", sample_node->employee.id,
           sample_node->employee.name, sample_node->employee.age, sample_node->employee.title,
           sample_node->employee.salary);
    printf("\n");

    return LL_OK;
}

EN_SLL_status_t modify_employee(LinkedList_t *my_linked_list)
{
    if (my_linked_list == NULL)
    {
        return LL_NULL_POINTER;
    }

    if (my_linked_list->head == NULL)
    {
        printf("empty list \n");
        return LL_EMPTY;
    }

    id_t id = get_id();
    node_t *selected_node = LL_search_node(my_linked_list, id);
    if (selected_node == NULL)
    {
        return LL_NODE_NOT_FOUND;
    }

    printf("Choose the data which you need to modify:\n\
    1. id   2. Name 3. Age  4. Title    5. Salary\n");
    int choice = 0;
    do
    {
        fflush(stdin);
        scanf("%d", &choice);
        if (choice < 1 || choice > 5)
        {
            printf("Wrong choice, please enter form 1 to 5!\n");
        }
    } while (choice < 1 || choice > 5);

    switch (choice)
    {
    case ID:
        selected_node->employee.id = get_unique_id(my_linked_list);
        break;
    case NAME:
        printf("Enter the new name: ");
        fflush(stdin);
        gets(selected_node->employee.name);
        break;
    case AGE:
        printf("Enter the new Age: ");
        // fflush(stdin);
        // scanf("%d", &(selected_node->employee.age));
        selected_node->employee.age = get_integer();
        printf("title is: %s\n", selected_node->employee.title);
        break;
    case TITLE:
        printf("Enter the new Title: ");
        fflush(stdin);
        gets(selected_node->employee.title);
        break;
    case SALARY:
        printf("Enter the new Salary: ");
        // fflush(stdin);
        // scanf("%f", &(selected_node->employee.salary));
        selected_node->employee.salary = get_number();
        break;
    default:
        printf("Wrong Choice entered!");
        break;
    }

    return LL_OK;
}

EN_SLL_status_t add_employee(LinkedList_t *my_linked_list)
{
    employee_t new_employee;
    printf("Adding an employee ...\n");
    new_employee.id = get_unique_id(my_linked_list);
    printf("Enter the Name: ");
    fflush(stdin);
    gets(new_employee.name);
    printf("Enter the Age: ");
    // fflush(stdin);
    // scanf("%d", &(new_employee.age));
    new_employee.age = get_integer();
    printf("ENter the Title: ");
    fflush(stdin);
    gets(new_employee.title);
    printf("Enter the Salary: ");
    // fflush(stdin);
    // scanf("%f", &(new_employee.salary));
    new_employee.salary = get_number();

    LL_append_node(my_linked_list, &new_employee);
}

void view_employee(LinkedList_t *my_linked_list)
{
    id_t id = get_id();
    display_node(LL_search_node(my_linked_list, id));
}

char is_id_unique(LinkedList_t *my_linked_list, id_t id)
{
    node_t *current = my_linked_list->head;
    while (current != NULL)
    {
        if (current->employee.id == id)
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}
