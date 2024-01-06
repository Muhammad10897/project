#include "single_linked_list.h"

// funtion to create a linked list
SingleLinkedList_t *SLL_create_sll()
{
    SingleLinkedList_t *new_sll = (SingleLinkedList_t *)malloc(1 * sizeof(SingleLinkedList_t));
    // making sure that the sll has been created >> error handling
    if (new_sll != NULL)
    {
        // now the list is empty
        new_sll->size = 0;
        new_sll->head = NULL;
        return new_sll;
    }
    else
    {
        printf("Can't Create the Linked List!\n Exiting ...\n");
        exit(1);
    }
}

// funciton to create a node
node_t *SLL_create_node(employee_t *sample_employee)
{
    node_t *new_node = malloc(1 * sizeof(node_t));
    if (new_node != NULL)
    {
        // copying
        new_node->employee.id = sample_employee->id;
        strncpy(new_node->employee.name, sample_employee->name, NAME_SIZE);
        new_node->employee.age = sample_employee->age;
        new_node->employee.salary = sample_employee->salary;
        strncpy(new_node->employee.title, sample_employee->title, TITLE_SIZE);
        new_node->next = NULL;
    }

    return new_node;
}

// funciton to append node
EN_SLL_status_t SLL_append_node(SingleLinkedList_t *my_sll, employee_t *sample_employee)
{
    if (my_sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    // create new node
    node_t *new_node = SLL_create_node(sample_employee);
    if (new_node == NULL)
    {
        return SLL_NODE_NOT_CREATED;
    }

    node_t *current = my_sll->head;
    my_sll->size++;

    // check if the list is empty
    if (my_sll->head == NULL)
    {
        my_sll->head = new_node;
        return SLL_OK;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    // now current points at the last node in the list
    current->next = new_node;

    return SLL_OK;
}

// funciton to diplay the data in the list
EN_SLL_status_t SLL_display(SingleLinkedList_t *my_sll)
{
    if (my_sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    if (my_sll->head == NULL)
    {
        printf("list is emtpy \n");
        return SLL_EMPTY;
    }

    printTableHeader();
    node_t *current = my_sll->head;
    while (current != NULL)
    {
        printf("| %-3d | %-30s | %-5d | %-30s | %-10.2f | \n", current->employee.id,
               current->employee.name, current->employee.age, current->employee.title,
               current->employee.salary);
        current = current->next;
    }
    printf("\n");

    return SLL_OK;
}

// to search node by id
node_t *SLL_search_by_id(SingleLinkedList_t *my_sll, id_t id)
{
    if (my_sll == NULL)
    {
        return NULL;
    }
    if (my_sll->head == NULL)
    {
        printf("empty list \n");
        return NULL;
    }

    node_t *current = my_sll->head;

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

// funciton to  free the linked list
EN_SLL_status_t SLL_free(SingleLinkedList_t *my_sll)
{
    if (my_sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    node_t *current = my_sll->head;

    while (current != NULL)
    {
        my_sll->head = my_sll->head->next;
        free(current);
        current = my_sll->head;
    }
    free(my_sll);
    return SLL_OK;
}

// delete some employee
EN_SLL_status_t SLL_delete_employee(SingleLinkedList_t *my_sll)
{
    if (my_sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    if (my_sll->head == NULL)
    {
        printf("empty list \n");
        return SLL_EMPTY;
    }

    id_t id = get_id();
    node_t *current = my_sll->head, *prev;

    if (my_sll->head->employee.id == id)
    {
        my_sll->head = my_sll->head->next;
        free(current);
        my_sll->size--;
        return SLL_OK;
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
        return SLL_NODE_NOT_FOUND;
    }

    prev->next = current->next;

    free(current);
    my_sll->size--;

    return SLL_OK;
}

EN_SLL_status_t SLL_display_node(node_t *sample_node)
{
    if (sample_node == NULL)
    {
        return SLL_NODE_NOT_FOUND;
    }

    printTableHeader();
    printf("| %-3d | %-30s | %-5d | %-30s | %-10.2f | \n", sample_node->employee.id,
           sample_node->employee.name, sample_node->employee.age, sample_node->employee.title,
           sample_node->employee.salary);
    printf("\n");

    return SLL_OK;
}

EN_SLL_status_t SLL_modify_by_id(SingleLinkedList_t *my_sll)
{
    if (my_sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    if (my_sll->head == NULL)
    {
        printf("empty list \n");
        return SLL_EMPTY;
    }

    id_t id = get_id();
    node_t *selected_node = SLL_search_by_id(my_sll, id);
    if (selected_node == NULL)
    {
        return SLL_NODE_NOT_FOUND;
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
        selected_node->employee.id = get_unique_id(my_sll);
        break;
    case NAME:
        printf("Enter the new name: ");
        fflush(stdin);
        gets(selected_node->employee.name);
        break;
    case AGE:
        printf("Enter the new Age: ");
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

    return SLL_OK;
}

EN_SLL_status_t SLL_add_employee(SingleLinkedList_t *my_sll)
{
    employee_t new_employee;
    printf("Adding an employee ...\n");
    new_employee.id = get_unique_id(my_sll);
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

    SLL_append_node(my_sll, &new_employee);
}

void SLL_view_employee(SingleLinkedList_t *my_sll)
{
    id_t id = get_id();
    SLL_display_node(SLL_search_by_id(my_sll, id));
}

char SLL_is_id_unique(SingleLinkedList_t *my_sll, id_t id)
{
    node_t *current = my_sll->head;
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

// function to get a unique id
id_t get_unique_id(SingleLinkedList_t *my_linked_list)
{
    id_t id = 0;
    while (1)
    {
        id = get_id();
        if (SLL_is_id_unique(my_linked_list, id))
        {
            return id;
        }
        else
        {
            printf("this id already exist! please enter a different id.\n");
        }
    }
}
