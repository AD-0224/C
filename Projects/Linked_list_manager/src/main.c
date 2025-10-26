#include "linked_list_manager.h"

int main()
{
    IntArray * arr = create_array(5);
    if (!arr) return EXIT_FAILURE;

    add_element(arr, 100);
    add_element(arr, 101);
    add_element(arr, 200);
    add_element(arr, 300);
    add_element(arr, 400);
    add_element(arr, 500);

    print_array(arr);

    remove_element(arr, 101);
    print_array(arr);

    free_array(arr);
    return EXIT_SUCCESS;
}