Hash Table Implementation in C | Implémentation d'une table de hachage en C
A robust hash table implementation in C with separate chaining for collision handling, automatic resizing, and full memory management.
Une implémentation robuste d'une table de hachage en C avec gestion des collisions par chaînage, redimensionnement automatique et gestion mémoire complète.

🧠 Features | Fonctionnalités
✅ Separate chaining using linked lists (chaînage séparé)

✅ Collision handling

✅ Dynamic resizing when load factor > 0.75

✅ djb2 hash function

✅ Full memory deallocation

✅ Update values on duplicate keys

✅ Clean and readable C99 code

📁 Structure
Hash_table_implementation/
├── include/
│ └── HASH_TABLE_IMPLEMENTATION.h
├── src/
│ └── Hash_table_implementation.c
├── main.c
├── Makefile
└── README.md

⚙️ Compilation & Execution
With Make
make
make run

🔍 Function Overview | Présentation des fonctions
| Function Name            | Description (EN)                                  | Description (FR)                                        |
| ------------------------ | ------------------------------------------------- | ------------------------------------------------------- |
| `create_node`            | Allocates a new node with key/value               | Alloue un nouveau nœud avec une clé et une valeur       |
| `insert`                 | Inserts or updates a key in a linked list         | Insère ou met à jour une clé dans une liste chaînée     |
| `search`                 | Retrieves value by key in linked list             | Cherche une clé dans la liste chaînée                   |
| `delete`                 | Removes a key from linked list                    | Supprime une clé de la liste chaînée                    |
| `djb2`                   | Hash function                                     | Fonction de hachage utilisée                            |
| `hash_index`             | Computes index from key & capacity                | Calcule l'index pour une clé dans la table              |
| `hash_table_create`      | Allocates the hash table                          | Crée et initialise la table de hachage                  |
| `hash_table_insert`      | Inserts/updates key-value in hash table           | Insère ou met à jour une paire clé/valeur dans la table |
| `hash_table_get`         | Gets value from a key                             | Récupère la valeur associée à une clé                   |
| `hash_table_delete`      | Deletes a key-value from table                    | Supprime une entrée de la table                         |
| `hash_table_load_factor` | Calculates the current load factor                | Calcule le taux d’occupation de la table                |
| `hash_table_resize`      | Doubles table capacity when threshold is exceeded | Redimensionne la table quand elle est trop pleine       |
| `hash_table_destroy`     | Frees all memory                                  | Libère toute la mémoire utilisée par la table           |

🧪 Sample Output | Exemple de sortie
Load factor: 0.86
alice: 123
bob: 456
charlie: 789
albert: 012
daphne: 234
bernard: 567
inexistant: NULL
bob après suppression: NULL

Testing resize...
Load factor after adding 20 elements: 0.45
Capacity: 56, Size: 25
alice après mise à jour: new_value

🛡️ License | Licence
This project is licensed under the MIT License — feel free to use, modify and share.
Ce projet est sous licence MIT — libre à vous de l’utiliser, le modifier et le partager.