#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#ifndef LINKED_LIST_MANAGER_H
#define LINKED_LIST_MANAGER_H

typedef struct 
{
    int *data;
    size_t size;
    size_t capacity;
}IntArray;

IntArray *create_array(size_t initial_capacity);
void add_element(IntArray *arr, int value);
void remove_element(IntArray *arr, int value);
void print_array(const IntArray *arr);
void free_array(IntArray *arr);

#endif