#include "HASH_TABLE_IMPLEMENTATION.h"

int main()
{
    // 1. Create HT
    HashTable* ht = hash_table_create(7);
    
    // 2. Add items
    hash_table_insert(ht, "alice", "123");
    hash_table_insert(ht, "bob", "456");
    hash_table_insert(ht, "charlie", "789");
    hash_table_insert(ht, "albert", "012");
    hash_table_insert(ht, "daphne", "234");
    hash_table_insert(ht, "bernard", "567");
    
    printf("Load factor: %.2f\n", hash_table_load_factor(ht));
    
    // 3. Test the search
    char* result = hash_table_get(ht, "alice");
    printf("alice: %s\n", result ? result : "NULL");
    
    result = hash_table_get(ht, "bob");
    printf("bob: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "charlie");
    printf("bob: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "albert");
    printf("bob: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "daphne");
    printf("bob: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "bernard");
    printf("bob: %s\n", result ? result : "NULL");
    
    result = hash_table_get(ht, "inexistant");
    printf("inexistant: %s\n", result ? result : "NULL");
    
    // 4. Test the deletion
    hash_table_delete(ht, "bob");
    result = hash_table_get(ht, "bob");
    printf("bob après suppression: %s\n", result ? result : "NULL");
    
    // 5. Test the resizing
    printf("\nTesting resize...\n");
    for (int i = 0; i < 20; i++)
    {
        char key[10], data[10];
        snprintf(key, sizeof(key), "key%d", i);
        snprintf(data, sizeof(data), "data%d", i);
        hash_table_insert(ht, key, data);
    }
    
    printf("Load factor after adding 20 elements: %.2f\n", hash_table_load_factor(ht));
    printf("Capacity: %zu, Size: %zu\n", ht->capacity, ht->size);
    
    // 6. Test de mise à jour d'une clé existante
    hash_table_insert(ht, "alice", "new_value");
    result = hash_table_get(ht, "alice");
    printf("alice après mise à jour: %s\n", result ? result : "NULL");
    
    // 7. Nettoyer
    hash_table_destroy(ht);
    return 0;
}