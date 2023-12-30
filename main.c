#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "single_linked_list.h"
#include <windows.h>

void main()
{
    // Initially Loaded data:
    employee_t emp1 = {1, "Hamed Refaat", 45, "Accountant", 214.23};
    employee_t emp2 = {2, "Hatem Reyad", 36, "Procurement Specialist", 340.25};
    employee_t emp3 = {3, "Ahmed Mostafa", 41, "Technician", 163.47};
    employee_t emp4 = {4, "Mohamed Ali", 32, "Production Engineer", 544.98};
    employee_t emp5 = {5, "Salah Amen", 35, "R&D Engineer", 641.68};
    employee_t emp6 = {6, "Hosam Hemeda", 39, "QA Engineer", 214.23};
    employee_t emp7 = {7, "Mahmoud Basiony", 49, "Worker", 111.21};
    employee_t emp8 = {8, "Elsayed Amen", 21, "Warehouse Keeper", 87.24};
    employee_t emp9 = {9, "Amir Sobhy", 56, "Supervisor", 352.14};
    employee_t emp10 = {10, "Moneeb Medhat", 37, "Procurement Manager", 365.58};

    // Linked list Making ...
    LinkedList_t *my_linked_list = LL_create_linked_list();

    // Adding initial data ...
    LL_append_node(my_linked_list, &emp1);
    LL_append_node(my_linked_list, &emp2);
    LL_append_node(my_linked_list, &emp3);
    LL_append_node(my_linked_list, &emp4);
    LL_append_node(my_linked_list, &emp5);
    LL_append_node(my_linked_list, &emp6);
    LL_append_node(my_linked_list, &emp7);
    LL_append_node(my_linked_list, &emp8);
    LL_append_node(my_linked_list, &emp9);
    LL_append_node(my_linked_list, &emp10);

    // Program running ...
    while (1)
    {
        // getting the command form the user ...
        printf("Choose what to do:\n1. Display the database\n\
2. View some emploee data by id\n3. Add a new employee data\n\
4. Modify some employee data\n5. delete some emoloyee data\n\
6. Exit\n");
        int choice = 0;
        fflush(stdin);
        scanf("%d", &choice);

        // execute the command
        switch (choice)
        {
        case DISPLAY_DATABASE:
            system("cls");
            LL_display(my_linked_list);
            break;
        case VIEW_EMPLOYEE:
            system("cls");
            view_employee(my_linked_list);
            break;
        case ADD_EMPLOYEE:
            system("cls");
            add_employee(my_linked_list);
            break;
        case MODIFY_EMPLOYEE:
            system("cls");
            modify_employee(my_linked_list);
            break;
        case DELETE_EMPLOYEE:
            system("cls");
            delete_employee(my_linked_list);
            break;
        case EXIT_PROGRAM:
            LL_free(my_linked_list);
            printf("exiting ...");
            exit(1);
            break;
        default:
            printf("Unexpected Error!");
            break;
        }
    }
    // free the data from the memory after finishing:
    LL_free(my_linked_list);
}