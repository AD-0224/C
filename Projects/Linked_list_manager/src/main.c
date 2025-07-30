#include "linked_list_manager.h"

int main()
{
    IntArray * arr = create_array(4);
    if (!arr) return EXIT_FAILURE;

    add_element(arr, 10);
    add_element(arr, 20);
    add_element(arr, 30);
    add_element(arr, 40);
    add_element(arr, 50);

    print_array(arr);

    remove_element(arr, 10);
    print_array(arr);

    free_array(arr);
    return EXIT_SUCCESS;
}