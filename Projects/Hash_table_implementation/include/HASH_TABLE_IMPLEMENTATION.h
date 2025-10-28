#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASH_TABLE_IMPLEMENTATION_H
#define HASH_TABLE_IMPLEMENTATION_H

typedef struct Node
{
    char *key;
    char *data;
    struct Node *next;
} Node;

typedef struct HashTable
{   
    Node **buckets; //array of linked list
    size_t size;    //nbr of entries
    size_t capacity;//nrb of buckets
} HashTable;


Node* create_node(char* key, char* data);
void insert(Node** head, char* key, char* data);
char* search(Node* head, char* key);
void delete(Node** head, char* key);
unsigned long djb2(unsigned char *str);
HashTable* hash_table_create(size_t capacity);
size_t hash_index(char* key, size_t capacity);
double hash_table_load_factor(HashTable* ht);
void hash_table_resize(HashTable* ht);
void hash_table_insert(HashTable* ht, char* key, char* data);
char* hash_table_get(HashTable* ht, char* key);
void hash_table_delete(HashTable* ht, char* key);
void hash_table_destroy(HashTable* ht);

#endif 