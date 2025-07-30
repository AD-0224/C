// #include <stdio.h>

// int main()
// {
//     int x = 42;
//     int* p1 = &x;

//     int y = x + 1;
//     int* p2 = &y;
    
//     printf("Valeur de x via le pointeur : %d\n", *p1);
//     printf("Valeur de y via le pointeur : %d\n", *p2);
//     printf("Adresse de x : %p\n", p1);
    
//     *p1 = 50;
//     printf("Nouvelle valeur de x : %d\n", x);
    
//     return 0;
// }
// TODO: Créer un pointeur vers x
    // TODO: Afficher la valeur de x via le pointeur
    // TODO: Modifier x via le pointeur
    // TODO: Afficher l'adresse de x

// #include <stdio.h>
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main()
// {
//     int a = 10, b = 20;
//     printf("Avant: a=%d, b=%d\n", a, b);
    
//     swap(&a, &b);
    
//     printf("Après: a=%d, b=%d\n", a, b);
//     return 0;
// }

// #include <stdio.h>

// // TODO: Fonction qui trouve le maximum dans un tableau
// int find_max(int *arr, int len)
// {
//     int max = arr[0];
//     if (len == 0)
//         return 0;
//     for (int i = 1; i < len; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// // TODO: Fonction qui affiche un tableau
// void print_array(int *arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d", arr[i++]);
//     }
//     printf("\n");
// }

// int main() {
//     int numbers[] = {5, 2, 8, 1, 9, 3};
//     int size = 6;
    
//     print_array(numbers, size);

//     int max = find_max(numbers, size);
//     printf("Maximum : %d\n", max);
    
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int n;
//     printf("Combien d'entiers ? ");
//     scanf("%d", &n);

//     int *arr = malloc(sizeof(int) * n);
//     if (!arr)
//     {
//         printf("Allocation error");
//         return 1;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = i * 2;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     free (arr);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *arr = malloc(3 * sizeof(int));
//     int size = 3;
    
//     // Remplir le tableau initial
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = i * 10;
//         printf("Tableau initial = %d ", arr[i]);
//     }
//     int new_size = size * 2;
//     int *temp = realloc (arr, new_size * sizeof(int));
//     if (!temp)
//     {
//         printf("Error");
//         return 1;
//     }else
//     {
//         arr = temp;
//         size = new_size;
//     }
//     int i;
//     for (i = 3; i < size; i++)
//     {
//         arr[i] = i * 10;
//     }
    
//     for (int i = 0; i < size; i++)
//     {
//         printf(" Nouveau tableau = %d ", arr[i]);
//     }
//     free (arr);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int* create_array(int size)
// {
//     int* arr = malloc(sizeof(int) * size);
//     if (!arr)
//     {
//         printf("Allocation error");
//         return NULL;
//     }
//     return arr;
//     // TODO: Allouer un tableau
//     // TODO: Vérifier l'allocation
//     // TODO: Retourner le tableau ou NULL
// }

// void fill_array(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = i + 1;
//     }
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     // TODO: Remplir avec des valeurs
// }

// int main()
// {
//     int *my_array = create_array(1000000000); // Très grand !
//     {
//         if (!my_array)
//         {
//             return EXIT_FAILURE;
//         }
//         else
//         {
//             fill_array(my_array, 1000000000);
//             free (my_array);
//             return EXIT_SUCCESS;
//         }
//     }    
//     // TODO: Vérifier si l'allocation a réussi
//     // TODO: Utiliser le tableau seulement si c'est OK
    
//     return 0;
// }