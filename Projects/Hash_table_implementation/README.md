════════════ ENGLISH ════════════

🧠 Hash Table Implementation in C

A robust hash table implementation in C with separate chaining for collision handling, automatic resizing, and full memory management.

---

✅ Features

- Separate chaining using linked lists
- Collision handling
- Dynamic resizing when load factor > 0.75
- djb2 hash function
- Full memory deallocation
- Update values on duplicate keys
- Clean and readable C99 code

---

📁 Structure
```
Hash_table_implementation/
├── include/
│   └── HASH_TABLE_IMPLEMENTATION.h
├── src/
│   └── Hash_table_implementation.c
├── main.c
├── Makefile
└── README.md
```

---

⚙️ Compilation & Execution
```bash
make
make run
```

---

🔍 Function Overview

| Function | Description |
|---|---|
| `create_node` | Allocates a new node with key/value |
| `insert` | Inserts or updates a key in a linked list |
| `search` | Retrieves value by key in linked list |
| `delete` | Removes a key from linked list |
| `djb2` | Hash function |
| `hash_index` | Computes index from key & capacity |
| `hash_table_create` | Allocates the hash table |
| `hash_table_insert` | Inserts/updates key-value in hash table |
| `hash_table_get` | Gets value from a key |
| `hash_table_delete` | Deletes a key-value from table |
| `hash_table_load_factor` | Calculates the current load factor |
| `hash_table_resize` | Doubles table capacity when threshold is exceeded |
| `hash_table_destroy` | Frees all memory |

---

🧪 Sample Output
```
Load factor: 0.86
alice: 123 | bob: 456 | charlie: 789
albert: 012 | daphne: 234 | bernard: 567
inexistant: NULL
bob après suppression: NULL

Testing resize...
Load factor after adding 20 elements: 0.45
Capacity: 56, Size: 25
alice après mise à jour: new_value
```

---

🛡️ License

MIT License — feel free to use, modify and share.

---

════════════ FRANÇAIS ════════════

🧠 Implémentation d'une table de hachage en C

Une implémentation robuste d'une table de hachage en C avec gestion des collisions par chaînage, redimensionnement automatique et gestion mémoire complète.

---

✅ Fonctionnalités

- Chaînage séparé via listes chaînées
- Gestion des collisions
- Redimensionnement dynamique si le taux de charge dépasse 0.75
- Fonction de hachage djb2
- Libération complète de la mémoire
- Mise à jour des valeurs sur clés dupliquées
- Code C99 propre et lisible

---

📁 Structure
```
Hash_table_implementation/
├── include/
│   └── HASH_TABLE_IMPLEMENTATION.h
├── src/
│   └── Hash_table_implementation.c
├── main.c
├── Makefile
└── README.md
```

---

⚙️ Compilation & Exécution
```bash
make
make run
```

---

🔍 Présentation des fonctions

| Fonction | Description |
|---|---|
| `create_node` | Alloue un nouveau nœud avec une clé et une valeur |
| `insert` | Insère ou met à jour une clé dans une liste chaînée |
| `search` | Cherche une clé dans la liste chaînée |
| `delete` | Supprime une clé de la liste chaînée |
| `djb2` | Fonction de hachage utilisée |
| `hash_index` | Calcule l'index pour une clé dans la table |
| `hash_table_create` | Crée et initialise la table de hachage |
| `hash_table_insert` | Insère ou met à jour une paire clé/valeur |
| `hash_table_get` | Récupère la valeur associée à une clé |
| `hash_table_delete` | Supprime une entrée de la table |
| `hash_table_load_factor` | Calcule le taux d'occupation de la table |
| `hash_table_resize` | Redimensionne la table quand elle est trop pleine |
| `hash_table_destroy` | Libère toute la mémoire utilisée |

---

🧪 Exemple de sortie
```
Load factor: 0.86
alice: 123 | bob: 456 | charlie: 789
albert: 012 | daphne: 234 | bernard: 567
inexistant: NULL
bob après suppression: NULL

Testing resize...
Load factor after adding 20 elements: 0.45
Capacity: 56, Size: 25
alice après mise à jour: new_value
```

---

🛡️ Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.