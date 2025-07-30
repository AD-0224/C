Dynamic Integer Array Manager in C | Gestionnaire de tableau dynamique d'entiers en C  
A simple and efficient dynamic array implementation in C supporting automatic resizing, element addition, removal, and full memory management.  
Une implémentation simple et efficace d’un tableau dynamique en C avec redimensionnement automatique, ajout et suppression d’éléments, et gestion complète de la mémoire.

🧠 Features | Fonctionnalités  
✅ Dynamic resizing (capacity doubles when full) — redimensionnement automatique (double la capacité quand c’est plein)  
✅ Add elements efficiently — ajout d’éléments efficace  
✅ Remove all occurrences of a value — suppression de toutes les occurrences d’une valeur  
✅ Print current content with size and capacity — affichage du contenu, taille et capacité  
✅ Proper memory management — gestion correcte de la mémoire  
✅ Clean and readable C99 code — code propre et lisible en C99  

📁 Structure  
Dynamic_Array_Manager/  
├── include/  
│   └── linked_list_manager.h  
├── src/  
│   └── linked_list_manager.c  
├── main.c  
├── Makefile  
└── README.md  

⚙️ Compilation & Execution  
With Make  
make
make run

🔍 Function Overview | Présentation des fonctions  

| Function Name       | Description (EN)                                     | Description (FR)                                   |  
|---------------------|------------------------------------------------------|----------------------------------------------------|  
| `create_array`      | Allocates and initializes a dynamic integer array    | Alloue et initialise un tableau dynamique d’entiers|  
| `add_element`       | Adds an element, resizing if capacity is exceeded    | Ajoute un élément et redimensionne si nécessaire   |  
| `remove_element`    | Removes all occurrences of a given element           | Supprime toutes les occurrences d’un élément donné |  
| `print_array`       | Prints elements with size and capacity               | Affiche les éléments avec la taille et capacité    |  
| `free_array`        | Frees allocated memory                               | Libère la mémoire allouée                          |  

🧪 Sample Output | Exemple de sortie  
Tableau(5/8) : 10 20 30 40 50
Tableau(4/8) : 20 30 40 50

🛡️ License | Licence  
This project is licensed under the MIT License — feel free to use, modify and share.  
Ce projet est sous licence MIT — libre à vous de l’utiliser, le modifier et le partager.  