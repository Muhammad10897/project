#include "app.h"




// filling database with the initial data ...
void initializing_data(SingleLinkedList_t *my_sll)
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

    // Adding initial data ...
    SLL_append_node(my_sll, &emp1);
    SLL_append_node(my_sll, &emp2);
    SLL_append_node(my_sll, &emp3);
    SLL_append_node(my_sll, &emp4);
    SLL_append_node(my_sll, &emp5);
    SLL_append_node(my_sll, &emp6);
    SLL_append_node(my_sll, &emp7);
    SLL_append_node(my_sll, &emp8);
    SLL_append_node(my_sll, &emp9);
    SLL_append_node(my_sll, &emp10);
}

// program runing
void run()
{
    // Linked list Making ...
    SingleLinkedList_t *my_sll = SLL_create_sll();
    initializing_data(my_sll);

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
            SLL_display(my_sll);
            break;
        case VIEW_EMPLOYEE:
            system("cls");
            SLL_view_employee(my_sll);
            break;
        case ADD_EMPLOYEE:
            system("cls");
            SLL_add_employee(my_sll);
            break;
        case MODIFY_EMPLOYEE:
            system("cls");
            SLL_modify_by_id(my_sll);
            break;
        case DELETE_EMPLOYEE:
            system("cls");
            SLL_delete_employee(my_sll);
            break;
        case EXIT_PROGRAM:
            SLL_free(my_sll);
            printf("exiting ...");
            exit(1);
            break;
        default:
            printf("Unexpected Error!");
            break;
        }
    }
    // free the data from the memory after finishing:
    SLL_free(my_sll);
}