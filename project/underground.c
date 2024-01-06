#include "underground.h"

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

// a function to limit the string length input
char *get_limited_string(int max_len)
{
    char *string;
    while (1)
    {
        fflush(stdin);
        gets(string);
        if (strlen(string) <= max_len)
        {
            return string;
        }
        else
        {
            printf("too long! lenght should not exceed %d chars!\n Please try again: ", max_len);
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

// a function to draw the table header
void printTableHeader()
{
    printf("| %-3s | %-30s | %-5s | %-30s | %-10s | \n", "id", "Name", "Age", "Title", "Salary");
    printf("|-----|--------------------------------|-------|--------------------------------|------------\n");
}
