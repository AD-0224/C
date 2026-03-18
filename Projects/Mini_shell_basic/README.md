════════════ ENGLISH ════════════

🧠 Mini Shell Basic in C

A basic command-line shell in C supporting built-in commands (`cd`, `pwd`, `exit`) and external command execution via `fork()` and `execvp()`.

---

✅ Features

- Built-in commands: `cd`, `pwd`, `exit`
- Executes external programs (`fork()` + `execvp()`)
- Command parsing using `strtok()`
- Ignores empty input lines
- Clean and readable C99 code

---

📁 Structure
```
Mini_shell_basic/
├── include/
│   └── MINI_SHELL_BASIC.h
├── src/
│   ├── Mini_Shell_Basic.c
│   └── main.c
├── Makefile
└── README.md
```

---

⚙️ Compilation & Execution
```
make        # compile the shell
make run    # run the shell
make re     # clean and rebuild
make debug  # compile with debug symbols and launch GDB
```

Run directly:
```
./bin/minishellbasic_app
```

---

🔍 Function Overview

| Function | Description |
|---|---|
| `parse_input` | Splits input line into arguments |
| `is_builtin` | Checks if command is built-in |
| `builtin_exit` | Exits the shell |
| `builtin_pwd` | Prints the current working directory |
| `builtin_cd` | Changes current directory |
| `execute_command` | Forks a process to run external command |

---

🧪 Sample Output
```
=====minishell$=====
pwd
/mnt/c/Users/Documents/Dev/GitHub/C/Projects/Mini_shell_basic
=====minishell$=====
cd include
=====minishell$=====
pwd
/mnt/c/Users/Documents/Dev/GitHub/C/Projects/Mini_shell_basic/include
=====minishell$=====
exit
Goodbye !
```

---

🧪 Testing & Debugging

**Debugging with Makefile**
```
make debug
```
- Adds debug symbols (`-g`)
- Cleans and recompiles
- Launches GDB for step-by-step debugging

Example GDB commands:
```
run                     # Start shell
break main              # Breakpoint at main
next                    # Step to next line
print parsed_args[0]    # Inspect variables
continue                # Continue execution
quit                    # Exit GDB
```

**Memory checking with Valgrind**
```
valgrind --leak-check=full ./bin/minishellbasic_app
```
- Detects memory leaks and invalid accesses
- Test with commands like `pwd`, `cd`, unknown commands
- Ensure shell exits cleanly → Valgrind should report 0 leaks

---

⚡ Limitations & Future Improvements

- No support for pipes (`|`) or redirection (`>`, `<`)
- No command history
- Limited error messages for invalid commands
- Could add environment variable support

---

🛡️ License

MIT License — feel free to use, modify and share.



════════════ FRANÇAIS ════════════

🧠 Mini Shell Basique en C

Un shell en ligne de commande basique en C avec commandes internes (`cd`, `pwd`, `exit`) et exécution de commandes externes via `fork()` et `execvp()`.

---

✅ Fonctionnalités

- Commandes internes : `cd`, `pwd`, `exit`
- Exécution de programmes externes (`fork()` + `execvp()`)
- Parsing des commandes avec `strtok()`
- Ignore les lignes vides
- Code propre et lisible en C99

---

📁 Structure
```
Mini_shell_basic/
├── include/
│   └── MINI_SHELL_BASIC.h
├── src/
│   ├── Mini_Shell_Basic.c
│   └── main.c
├── Makefile
└── README.md
```

---

⚙️ Compilation & Exécution
```
make        # compile le shell
make run    # lance le shell
make re     # nettoie et recompile
make debug  # compile avec symboles de débogage et lance GDB
```

Exécution directe :
```
./bin/minishellbasic_app
```

---

🔍 Présentation des fonctions

| Fonction | Description |
|---|---|
| `parse_input` | Sépare la ligne d'entrée en arguments |
| `is_builtin` | Vérifie si la commande est interne |
| `builtin_exit` | Quitte le shell |
| `builtin_pwd` | Affiche le répertoire courant |
| `builtin_cd` | Change le répertoire courant |
| `execute_command` | Crée un processus pour exécuter une commande externe |

---

🧪 Exemple de sortie
```
=====minishell$=====
pwd
/mnt/c/Users/Documents/Dev/GitHub/C/Projects/Mini_shell_basic
=====minishell$=====
cd include
=====minishell$=====
pwd
/mnt/c/Users/Documents/Dev/GitHub/C/Projects/Mini_shell_basic/include
=====minishell$=====
exit
Goodbye !
```

---

🧪 Tests & Débogage

**Débogage avec Makefile**
```
make debug
```
- Ajoute les symboles de débogage (`-g`)
- Nettoie et recompile
- Lance GDB pour un débogage pas à pas

Commandes GDB utiles :
```
run                     # Lancer le shell
break main              # Point d'arrêt au main
next                    # Passer à la ligne suivante
print parsed_args[0]    # Inspecter les variables
continue                # Continuer l'exécution
quit                    # Quitter GDB
```

**Vérification mémoire avec Valgrind**
```
valgrind --leak-check=full ./bin/minishellbasic_app
```
- Détecte les fuites mémoire et les accès invalides
- Tester avec des commandes comme `pwd`, `cd`, commandes inconnues
- Le shell doit se terminer proprement → Valgrind doit reporter 0 fuite

---

⚡ Limitations & Améliorations futures

- Pas de support pour les pipes (`|`) ou redirections (`>`, `<`)
- Pas d'historique des commandes
- Messages d'erreur limités pour les commandes invalides
- Ajout possible du support des variables d'environnement

---

🛡️ Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.