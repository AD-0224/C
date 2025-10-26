#include "linked_list_manager.h"

IntArray *create_array(size_t initial_capacity)
{
    IntArray *arr = malloc(sizeof(IntArray));
    if (!arr)
    {
        printf("Allocation error\n");
        return (NULL);
    }
    arr->data = malloc(sizeof(int) * initial_capacity);
    if (!arr->data)
    {
        printf("Allocation error\n");
        free(arr);
        return (NULL);
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    return (arr);
}

void add_element(IntArray *arr, int value)
{
    if (!arr) return;
    if (arr->size >= arr->capacity)
    {
        size_t new_capacity = arr->capacity * 2;
        int *temp = realloc(arr->data, new_capacity * sizeof(int));
        if (!temp)
        {
            printf("Allocation error\n");
            return;
        }
        arr->data = temp;
        arr->capacity = new_capacity;
    }
    arr->data[arr->size++] = value;
}

void remove_element(IntArray *arr, int value)
{
    if (!arr) return;
    size_t i = 0;
    while(i < arr->size)
    {
        if (arr->data[i] == value)
        {
            for (size_t j = i; j < arr-> size - 1; j++)
            {
                arr->data[j] = arr->data[j + 1];
            }
            arr->size--;
        }
        else
        {
            i++;
        }
    }
}

void print_array(const IntArray *arr)
{
    if (!arr)
    {
        printf("Array is NULL\n");
        return;
    }
    printf("Array(%zu/%zu): ", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void free_array(IntArray *arr)
{
    if (arr)
    {
        free(arr->data);
        free (arr);
    }
}
