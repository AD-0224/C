# English

# C Programming Portfolio

A collection of C programming exercises and system-level projects focused on algorithms, data structures, memory management, and Unix/Linux programming.

This repository documents my progression in C programming, from fundamental concepts to advanced low-level projects.

---

## Skills & Concepts Covered

* C programming (C99/C11)
* Pointers and memory management
* Dynamic allocation (`malloc`, `free`)
* Structures and data organization
* Linked lists
* Algorithms and optimization
* String manipulation
* Data structures implementation
* File handling
* Unix processes
* Socket programming (TCP/IP)
* Makefile automation

---

## Repository Structure

```text
C/
├── C-Learning/
│   ├── Algorithms/              # Algorithms exercises
│   ├── Arrays/                  # Array manipulation
│   ├── Lists/                   # Linked lists
│   ├── Macros/                  # C preprocessor macros
│   ├── Maths/                   # Mathematical exercises
│   ├── Pointers/                # Pointer manipulation
│   ├── Strings/                 # String manipulation
│   ├── Structs/                 # Structures and data management
│   └── Utils/                   # Utility functions
│
└── C-Projects/
    ├── Hash_table_implementation/
    ├── Linked_list_manager/
    ├── Mini_shell_basic/
    ├── Mini_Shell_Advanced/
    ├── Multi_client_Echo_Server/
    ├── Parse_JSON/
    ├── Push_swap/
    ├── Custom_Memory_Allocator.c
    └── Http_Server_Basic.c
```

---

# Main Projects

## Mini Shell Advanced

A Unix shell implementation written in C.

Features:

* Command parsing
* Process creation
* Command execution
* Built-in commands
* Signal handling
* Environment management

Concepts:

* `fork()`
* `execve()`
* `wait()`
* Unix process management

---

## Multi Client TCP Server

A TCP server capable of handling multiple clients.

Features:

* Client/server communication
* Socket programming
* Multiple connections handling

Concepts:

* TCP/IP
* Sockets
* Network programming

---

## Hash Table Implementation

A complete hash table implementation using separate chaining.

Features:

* Collision handling
* Dynamic resizing
* Memory management
* djb2 hashing algorithm

Concepts:

* Data structures
* Linked lists
* Dynamic memory allocation

---

## Custom Memory Allocator

Implementation of a custom memory allocation system.

Concepts:

* Memory management
* Heap organization
* Low-level programming

---

## Compilation

Most projects include their own Makefile.

Example:

```bash
cd C-Projects/Mini_Shell_Advanced

make

./minishell
```

---

## Development Environment

* Linux / Unix
* GCC
* Make
* Visual Studio Code
* Git

---

## Future Improvements

* More system programming projects
* Advanced networking projects
* Memory debugging with Valgrind
* Improved test coverage

---

## License

MIT License — feel free to use, modify and share.

---

# Français

# Portfolio de programmation en C

Une collection d'exercices et de projets système réalisés en langage C autour des algorithmes, structures de données, gestion mémoire et programmation Unix/Linux.

Ce dépôt retrace ma progression en C, des notions fondamentales jusqu'aux projets bas niveau avancés.

---

## Compétences travaillées

* Programmation en C (C99/C11)
* Pointeurs et gestion mémoire
* Allocation dynamique (`malloc`, `free`)
* Structures de données
* Listes chaînées
* Algorithmes et optimisation
* Manipulation des chaînes de caractères
* Implémentation de structures complexes
* Gestion des fichiers
* Processus Unix
* Programmation réseau TCP/IP
* Automatisation avec Makefile

---

## Structure du dépôt

```text
C/
├── C-Learning/
│   ├── Algorithms/              # Exercices d'algorithmes
│   ├── Arrays/                  # Manipulation des tableaux
│   ├── Lists/                   # Listes chaînées
│   ├── Macros/                  # Préprocesseur C
│   ├── Maths/                   # Exercices mathématiques
│   ├── Pointers/                # Manipulation des pointeurs
│   ├── Strings/                 # Chaînes de caractères
│   ├── Structs/                 # Structures C
│   └── Utils/                   # Fonctions utilitaires
│
└── C-Projects/
    ├── Hash_table_implementation/
    ├── Linked_list_manager/
    ├── Mini_shell_basic/
    ├── Mini_Shell_Advanced/
    ├── Multi_client_Echo_Server/
    ├── Parse_JSON/
    ├── Push_swap/
    ├── Custom_Memory_Allocator.c
    └── Http_Server_Basic.c
```

---

# Projets principaux

## Mini Shell Advanced

Implémentation d'un shell Unix en langage C.

Fonctionnalités :

* Analyse des commandes
* Création de processus
* Exécution de programmes
* Commandes internes
* Gestion des signaux
* Gestion de l'environnement

Notions utilisées :

* `fork()`
* `execve()`
* `wait()`
* Gestion des processus Unix

---

## Serveur TCP Multi-clients

Serveur TCP capable de gérer plusieurs connexions clientes.

Fonctionnalités :

* Communication client/serveur
* Gestion des sockets
* Connexions multiples

Notions utilisées :

* TCP/IP
* Sockets
* Programmation réseau

---

## Implémentation d'une table de hachage

Implémentation complète d'une table de hachage avec chaînage séparé.

Fonctionnalités :

* Gestion des collisions
* Redimensionnement dynamique
* Gestion mémoire
* Algorithme de hachage djb2

Notions utilisées :

* Structures de données
* Listes chaînées
* Allocation dynamique

---

## Allocateur mémoire personnalisé

Création d'un système personnalisé de gestion mémoire.

Notions utilisées :

* Gestion du tas mémoire
* Organisation mémoire
* Programmation bas niveau

---

## Compilation

La majorité des projets possèdent leur propre Makefile.

Exemple :

```bash
cd C-Projects/Mini_Shell_Advanced

make

./minishell
```

---

## Environnement de développement

* Linux / Unix
* GCC
* Make
* Visual Studio Code
* Git

---

## Améliorations futures

* Ajouter plus de projets système
* Approfondir la programmation réseau
* Utiliser Valgrind pour l'analyse mémoire
* Ajouter davantage de tests

---

## Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.
