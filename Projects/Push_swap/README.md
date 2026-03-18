════════════ ENGLISH ════════════

🧠 Push Swap in C

A C program that sorts a stack of integers using a limited set of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`).

---

✅ Features

- Sorts a stack of integers with a minimal number of operations
- Supports both small and large stacks
- Implements Radix Sort for large stacks
- Handles invalid input (duplicates, non-integer values)
- Clean and readable C99 code

---

📁 Structure

    Push_swap/
    ├── include/
    │   └── PUSH_SWAP.h
    ├── src/
    │   ├── main.c
    │   ├── push_swap.c
    │   ├── operations.c
    │   └── utils.c
    ├── build/
    ├── bin/
    ├── Makefile
    └── README.md

---

⚙️ Compilation & Execution

    make        # compile the push_swap program
    make run    # run push_swap
    make re     # clean and rebuild
    make debug  # compile with debug symbols and launch GDB

Run directly:

    ./bin/push_swap_app 3 2 5 1 4

---

🔍 Function Overview

| Function | Description |
|---|---|
| `create_stack` | Initializes a stack |
| `push` | Pushes element to a stack |
| `pop` | Removes element from a stack |
| `swap` | Swaps the first two elements |
| `rotate` | Rotates stack upwards |
| `reverse_rotate` | Rotates stack downwards |
| `radix_sort` | Sorts the stack using Radix Sort |
| `is_sorted` | Checks if the stack is sorted |
| `execute_operation` | Executes a single instruction (`sa`, `pb`, etc.) |

---

🧪 Sample Output

    ./bin/push_swap_app 3 2 5 1 4
    ra
    ra
    ra
    pb
    ra
    ra
    pb
    ra
    sa
    pa
    pa

Each line represents an operation to sort the stack.

---

🧪 Testing & Debugging

**Debugging with Makefile**

    make debug

- Adds debug symbols (`-g`)
- Cleans and recompiles
- Launches GDB for step-by-step debugging

Example GDB commands:

    run                 # Start program
    break main          # Breakpoint at main
    next                # Step to next line
    print stack_a       # Inspect stack contents
    continue            # Continue execution
    quit                # Exit GDB

**Memory checking with Valgrind**

    valgrind --leak-check=full ./bin/push_swap_app 3 2 5 1 4

- Detects memory leaks and invalid accesses
- Ensures the program exits cleanly → Valgrind should report 0 leaks

---

⚡ Limitations & Future Improvements

- Optimizations could further reduce the number of instructions for large stacks
- No visual output of stack state (could add a graphical display)
- Currently supports only integers

---

🛡️ License

MIT License — feel free to use, modify, and share.



════════════ FRANÇAIS ════════════

🧠 Tri optimisé de piles en C

Un programme en C qui trie une pile d'entiers en utilisant un nombre limité d'opérations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`).

---

✅ Fonctionnalités

- Trie une pile d'entiers avec un nombre minimal d'opérations
- Supporte les petites et les grandes piles
- Implémente le Radix Sort pour les grandes piles
- Gère les entrées invalides (doublons, valeurs non entières)
- Code propre et lisible en C99

---

📁 Structure

    Push_swap/
    ├── include/
    │   └── PUSH_SWAP.h
    ├── src/
    │   ├── main.c
    │   ├── push_swap.c
    │   ├── operations.c
    │   └── utils.c
    ├── build/
    ├── bin/
    ├── Makefile
    └── README.md

---

⚙️ Compilation & Exécution

    make        # compile le programme
    make run    # lance push_swap
    make re     # nettoie et recompile
    make debug  # compile avec symboles de débogage et lance GDB

Exécution directe :

    ./bin/push_swap_app 3 2 5 1 4

---

🔍 Présentation des fonctions

| Fonction | Description |
|---|---|
| `create_stack` | Initialise une pile |
| `push` | Ajoute un élément à la pile |
| `pop` | Supprime un élément de la pile |
| `swap` | Échange les deux premiers éléments |
| `rotate` | Fait tourner la pile vers le haut |
| `reverse_rotate` | Fait tourner la pile vers le bas |
| `radix_sort` | Trie la pile avec Radix Sort |
| `is_sorted` | Vérifie si la pile est triée |
| `execute_operation` | Exécute une instruction sur la pile (`sa`, `pb`, etc.) |

---

🧪 Exemple de sortie

    ./bin/push_swap_app 3 2 5 1 4
    ra
    ra
    ra
    pb
    ra
    ra
    pb
    ra
    sa
    pa
    pa

Chaque ligne correspond à une opération pour trier la pile.

---

🧪 Tests & Débogage

**Débogage avec Makefile**

    make debug

- Ajoute les symboles de débogage (`-g`)
- Nettoie et recompile
- Lance GDB pour un débogage pas à pas

Commandes GDB utiles :

    run                 # Lancer le programme
    break main          # Point d'arrêt au main
    next                # Passer à la ligne suivante
    print stack_a       # Inspecter le contenu de la pile
    continue            # Continuer l'exécution
    quit                # Quitter GDB

**Vérification mémoire avec Valgrind**

    valgrind --leak-check=full ./bin/push_swap_app 3 2 5 1 4

- Détecte les fuites mémoire et les accès invalides
- Le programme doit se terminer proprement → Valgrind doit reporter 0 fuite

---

⚡ Limitations & Améliorations futures

- Des optimisations pourraient réduire davantage le nombre d'instructions pour les grandes piles
- Pas d'affichage visuel de l'état de la pile (ajout possible d'une interface graphique)
- Supporte uniquement les entiers pour l'instant

---

🛡️ Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.