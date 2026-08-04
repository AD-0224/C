#include "HASH_TABLE_IMPLEMENTATION.h"

Node* create_node(char* key, char* data)
{
    Node* c = malloc(sizeof(Node));
    if (!c)
    {
        printf("ALLOCATION ERROR\n");
        exit(EXIT_FAILURE);
    }
    c->key = strdup(key);
    c->data = strdup(data);
    c->next = NULL;

    if (!c->key || !c->data)
    {
        printf("ALLOCATION ERROR\n");
        free(c->key);
        free(c->data);
        free(c);
        exit(EXIT_FAILURE);
    }
    return c;
}

void insert(Node** head, char* key, char* data)
{
    Node* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->data);
            current->data = strdup(data);
            return;
        }
        current = current->next;
    }
    Node* new_node = create_node(key, data);
    if (!new_node)
    {
        printf("ALLOCATION ERROR");
        exit(EXIT_FAILURE);
    }
    new_node->next = *head;
    *head = new_node;
}

char* search(Node* head, char* key)
{
    Node* current = head;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0) 
            return current->data;
        current = current->next; 
    }
    return NULL;
}

void delete(Node** head, char* key)
{
    if (head == NULL || *head == NULL) 
        return;
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL && strcmp(current->key, key)!= 0) 
    {
       prev = current;
       current = current->next;
    }
    if (current == NULL) 
    {
        return;
    }
    if (prev == NULL)
    {
        *head = current->next;
    }
    else
        prev->next = current->next;
    free(current->key);
    free(current->data);
    free(current); 
}

// djb2 hash function by Dan Bernstein
 
// One of the most widely used string hash functions due to its excellent
// distribution properties and computational efficiency.
 
// Algorithm: hash = hash * 33 + character
// - Uses bit shifting for speed: (hash << 5) + hash equals hash * 33
// - Magic constant 5381: empirically chosen starting value
  
// @param str String to hash
// @return Hash value as unsigned long
// Complexity: O(n) where n is the string length

unsigned long djb2(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;    // hash * 33 + c
    }
    
    return hash;
}

// Creates and initializes a new hash table
 
// Allocates memory for the hash table structure and its bucket array.
// All buckets are initialized to NULL (empty linked lists). 
// @param capacity Initial number of buckets
// @return Pointer to the newly created hash table

// Complexity: O(capacity)
HashTable* hash_table_create(size_t capacity)
{
    HashTable* c = malloc(sizeof(HashTable));
    if (!c)
    {
        printf("Erreur d'allocation");
        exit (EXIT_FAILURE);
    }
    c->buckets = calloc(capacity, sizeof(Node*));
    if (!c->buckets)
    {
        printf("Erreur allocation");
        free (c);
        exit(EXIT_FAILURE);
    }
    c->size = 0;
    c->capacity = capacity;
    return c;
}

size_t hash_index(char* key, size_t capacity)
{
    return djb2((unsigned char*)key) % capacity;
}

// Inserts or updates a key-value pair in the hash table

// Behavior:
// If key exists: updates the value
// If key is new: creates new entry
// Auto-resizes when load factor > 0.75
 
// Complexity: O(1) average, O(n) worst case
void hash_table_insert(HashTable* ht, char* key, char* data)
{
    if (!ht || !key || !data) return;

    // Prevent performance degradation by maintaining low load factor
    if (hash_table_load_factor(ht) > 0.75)
    {
        hash_table_resize(ht);
    }
    size_t index = hash_index(key, ht->capacity);
    if (!search(ht->buckets[index], key))
    {
        ht->size++;
    }
    insert(&ht->buckets[index], key, data);
}

char* hash_table_get(HashTable* ht, char* key)
{
    size_t index = hash_index(key, ht->capacity);
    return search(ht->buckets[index], key);
}

void hash_table_delete(HashTable* ht, char* key)
{
    size_t index = hash_index(key, ht->capacity);
    if (search(ht->buckets[index], key))
    {
        delete(&ht->buckets[index], key);
        ht->size--;
    }
}

void hash_table_destroy(HashTable* ht)
{
    if (!ht) return;
    for (size_t i = 0; i < ht->capacity; i++) //free all nodes in all buckets
    {
        Node* current = ht->buckets[i];
        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;

            //free strings allocated by strdup
            free(temp->key);
            free(temp->data);

            //free node structure
            free(temp);
        }
    }
    //free bucket array
    free(ht->buckets);
    free(ht);
}

double hash_table_load_factor(HashTable* ht)
{
    return (double)ht->size / ht->capacity;
}

void hash_table_resize(HashTable* ht)
{
    Node** old_buckets = ht->buckets;
    size_t old_capacity = ht->capacity;

    ht->capacity *= 2;  // double the capacity (common strategy for amortized O(1))
    ht->buckets = calloc(ht->capacity, sizeof(Node*));
    if (!ht->buckets)
    {
        printf("Erreur allocation lors du redimensionnement\n");
        exit(EXIT_FAILURE);
    }
    ht->size = 0;   // Reset size: hash_table_insert will recalculate it
    for (size_t i = 0; i < old_capacity; i++)
    {
        Node* current = old_buckets[i];
        while (current)
        {
            Node* next = current->next;

            //reinsert with new capacity, potentially new bucket index
            hash_table_insert(ht, current->key, current->data);
            free(current->key);
            free(current->data);
            free(current);
            current = next;
        }
    }
    free(old_buckets);
}
