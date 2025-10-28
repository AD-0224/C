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
    printf("charlie: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "albert");
    printf("albert: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "daphne");
    printf("daphne: %s\n", result ? result : "NULL");

    result = hash_table_get(ht, "bernard");
    printf("bernard: %s\n", result ? result : "NULL");
    
    result = hash_table_get(ht, "inexistant");
    printf("inexistant: %s\n", result ? result : "NULL");
    
    // 4. Test the deletion
    hash_table_delete(ht, "bob");
    result = hash_table_get(ht, "bob");
    printf("bob après suppression: %s\n", result ? result : "NULL");
    
    // 5. Test the resizing
    printf("\nTesting resize...\n");
    hash_table_insert(ht, "test1", "value1");
    hash_table_insert(ht, "test2", "value2");
    hash_table_insert(ht, "test3", "value3");
    hash_table_insert(ht, "test4", "value4");
    hash_table_insert(ht, "test5", "value5");
    hash_table_insert(ht, "test6", "value6");
    hash_table_insert(ht, "test7", "value7");
    hash_table_insert(ht, "test8", "value8");
    hash_table_insert(ht, "test9", "value9");
    hash_table_insert(ht, "test10", "value10");
    hash_table_insert(ht, "test11", "value11");
    hash_table_insert(ht, "test12", "value12");
    hash_table_insert(ht, "test13", "value13");
    hash_table_insert(ht, "test14", "value14");
    hash_table_insert(ht, "test15", "value15");
    hash_table_insert(ht, "test16", "value16");
    hash_table_insert(ht, "test17", "value17");
    hash_table_insert(ht, "test18", "value18");
    hash_table_insert(ht, "test19", "value19");
    hash_table_insert(ht, "test20", "value20");

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