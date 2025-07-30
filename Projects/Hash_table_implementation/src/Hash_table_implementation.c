#include "HASH_TABLE_IMPLEMENTATION.h"

Node* create_node(char* key, char* data)
{
    Node* c = malloc(sizeof(Node));
    if (!c)
    {
        printf("ALLOCATION ERROR");
        exit(EXIT_FAILURE);
    }
    c->key = strdup(key);
    c->data = strdup(data);
    c->next = NULL;

    if (!c->key || !c->data)
    {
        printf("ALLOCATION ERROR");
        free(c->key);
        free(c->data);
        free(c);
        exit(EXIT_FAILURE);
    }
    return c;
}
void insert(Node** head, char* key, char* data)
{
    Node* current =*head; //si la clé existe déja
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0) //clé trouvée maj de la valeur
        {
            free(current->data); //libére l'ancienne valeur
            current->data = strdup(data); //nouvelle valeur
            return;
        }
        current = current->next;
    }
    Node* new_node = create_node(key, data); //si clé pas trouvé
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
unsigned long djb2(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash;
}

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
void hash_table_insert(HashTable* ht, char* key, char* data)
{
    if (!ht || !key || !data) return;
    if (hash_table_load_factor(ht) > 0.75)
    {
        hash_table_resize(ht);
    }
    size_t index = hash_index(key, ht->capacity);
    if (!search(ht->buckets[index], key))
    {
        ht->size++; //incrémenter si nouvelle clé
    }
    insert(&ht->buckets[index], key, data);
}
char* hash_table_get(HashTable* ht, char* key)
{
    size_t index = hash_index(key, ht->capacity);
    // search(ht->buckets[index], key);
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
    for (size_t i = 0; i < ht->capacity; i++)
    {
        Node* current = ht->buckets[i];
        
        // 2. Libérer tous les nœuds de ce bucket
        while (current != NULL)
        {
            Node* temp = current; // ← sauvegarde l'adresse
            current = current->next; // ← on avance AVANT de libérer
            
            // Libérer le nœud
            free(temp->key);
            free(temp->data);
            free(temp);
        }
    }
    // 3. Libérer le tableau buckets
    free(ht->buckets);
    
    // 4. Libérer la structure hashtable
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

    ht->capacity *= 2;
    ht->buckets = calloc(ht->capacity, sizeof(Node*));
    if (!ht->buckets)
    {
        printf("Erreur allocation lors du redimensionnement\n");
        exit(EXIT_FAILURE);
    }
    ht->size = 0; // ← On va tout réinsérer manuellement
    // 3. Réinsérer chaque élément
    for (size_t i = 0; i < old_capacity; i++)
    {
        Node* current = old_buckets[i];
        while (current)
        {
            Node* next = current->next;
            // Réinsérer dans la nouvelle table
            hash_table_insert(ht, current->key, current->data);
            // Libérer l'ancien nœud
            free(current->key);
            free(current->data);
            free(current);
            current = next;
        }
    }
    // 4. Libérer l'ancien tableau de buckets
    free(old_buckets);
}
