#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct
{
    char **data;        
    size_t size;       
    size_t capacity;  
} StringArray;

StringArray *create_string_array(size_t initial_capacity)
{
    StringArray *arr = malloc(sizeof(StringArray));
    if (!arr)
    {
        printf("Allocation error\n");
        return (NULL);
        //pas de free puisqu'on pointe sur aucune zone de memoire
    }
    arr->data = malloc(sizeof(char*) * initial_capacity);
    if (!arr->data)
    {
        printf("Allocation error\n");
        free(arr);
        return(NULL);
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

// Ajoute une chaîne au tableau (fait une copie de la chaîne)
void add_string(StringArray *arr, const char *str)
{
char *new_str = strdup(str);
if (!new_str)
{
    printf("Error");
    return;
}
if (arr->size >= arr->capacity)
{
    size_t new_capacity = arr->capacity * 2;
    char **temp = realloc(arr->data, new_capacity * sizeof(char*));
    if (!temp)
    {
        printf("Allocation error\n");
        return;
    }
    arr->data = temp;
    arr->capacity = new_capacity;
}
arr->data[arr->size++] = new_str;

}

// Supprime la première occurrence d'une chaîne
void remove_string(StringArray *arr, const char *str)
{
  size_t i = 0;
  while (i < arr->size)
  {
    if (strcmp(arr->data[i], str) == 0)
    {
        free(arr->data[i]);
        for (size_t j = i; j < arr->size - 1; j++)
        {
            arr->data[j] = arr->data[j+1];
        }
        arr->size --;
    }
    else 
        {
            i++;
        }
  }
}

// Affiche le contenu du tableau
void print_string_array(const StringArray *arr)
{
    printf("Tableau (%zu/%zu) : ", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%s ", arr->data[i]);
    }
    printf("\n");
}

// Libère toute la mémoire
void free_string_array(StringArray *arr)
{
   if (arr)
   {
       for (size_t i = 0; i < arr->size; i++)
       {
           free(arr->data[i]);  // Libère chaque chaîne
       }
       free(arr->data);  // Libère le tableau de pointeurs
       free(arr);        // Libère la structure
   }
}

// Fonction de test
int main()
{
    StringArray *arr = create_string_array(2);
    if (!arr) return EXIT_FAILURE;
    
    add_string(arr, "Hello");
    add_string(arr, "World");
    add_string(arr, "C");
    add_string(arr, "Programming");
    
    print_string_array(arr);
    
    remove_string(arr, "World");
    print_string_array(arr);
    
    free_string_array(arr);
    return EXIT_SUCCESS;
}

// Résultat attendu :
// Array(4/4): [Hello] [World] [C] [Programming]
// Array(3/4): [Hello] [C] [Programming]