#ifndef UNDERGROUNG
#define UNDERGROUNG

// including libraaries ...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <assert.h>

typedef unsigned int id_t;

// to get interger
int get_integer();

// to get interger
float get_number();

// get a string with maximum specific length
char *get_limited_string(int max_len);

/* a helper function to get the id by which we search, view, modify, or delete some employee
we make it as it is reprating in the code */
id_t get_id();



// a function to draw the table header
void printTableHeader();

#endif