════════════ ENGLISH ════════════

🧠 Dynamic Integer Array Manager in C

A simple and efficient dynamic array implementation in C supporting automatic resizing, element addition, removal, and full memory management.

---

✅ Features

- Dynamic resizing (capacity doubles when full)
- Add elements efficiently
- Remove all occurrences of a value
- Print current content with size and capacity
- Proper memory management
- Clean and readable C99 code

---

📁 Structure
```
Dynamic_Array_Manager/
├── include/
│   └── linked_list_manager.h
├── src/
│   └── linked_list_manager.c
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
| `create_array` | Allocates and initializes a dynamic integer array |
| `add_element` | Adds an element, resizing if capacity is exceeded |
| `remove_element` | Removes all occurrences of a given element |
| `print_array` | Prints elements with size and capacity |
| `free_array` | Frees allocated memory |

---

🧪 Sample Output
```
Tableau(5/8) : 10 20 30 40 50
Tableau(4/8) : 20 30 40 50
```

---

🛡️ License

MIT License — feel free to use, modify and share.



════════════ FRANÇAIS ════════════

🧠 Gestionnaire de tableau dynamique d'entiers en C

Une implémentation simple et efficace d'un tableau dynamique en C avec redimensionnement automatique, ajout et suppression d'éléments, et gestion complète de la mémoire.

---

✅ Fonctionnalités

- Redimensionnement automatique (double la capacité quand c'est plein)
- Ajout d'éléments efficace
- Suppression de toutes les occurrences d'une valeur
- Affichage du contenu, taille et capacité
- Gestion correcte de la mémoire
- Code propre et lisible en C99

---

📁 Structure
```
Dynamic_Array_Manager/
├── include/
│   └── linked_list_manager.h
├── src/
│   └── linked_list_manager.c
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
| `create_array` | Alloue et initialise un tableau dynamique d'entiers |
| `add_element` | Ajoute un élément et redimensionne si nécessaire |
| `remove_element` | Supprime toutes les occurrences d'un élément donné |
| `print_array` | Affiche les éléments avec la taille et capacité |
| `free_array` | Libère la mémoire allouée |

---

🧪 Exemple de sortie
```
Tableau(5/8) : 10 20 30 40 50
Tableau(4/8) : 20 30 40 50
```

---

🛡️ Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.