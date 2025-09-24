# Mini Shell Basic in C | Mini shell basique en C

A basic command-line shell in C supporting built-in commands (`cd`, `pwd`, `exit`) and external command execution via `fork()` and `execvp()`.  
Un shell en ligne de commande basique en C avec commandes internes (`cd`, `pwd`, `exit`) et exécution de commandes externes via `fork()` et `execvp()`.  

---

## 🧠 Features | Fonctionnalités

✅ Built-in commands: `cd`, `pwd`, `exit` (commandes internes)  
✅ Executes external programs (`fork()` + `execvp()`)  
✅ Command parsing using `strtok()`  
✅ Ignores empty input lines  
✅ Clean and readable C99 code  

---

## 📁 Structure

Mini_shell_basic/
├── include/
│   └── MINI_SHELL_BASIC.h
├── src/
│   ├── Mini_Shell_Basic.c
│   └── main.c
├── Makefile
└── README.md

---

## ⚙️ Compilation & Execution | Compilation & exécution

With Make:

```bash
make        # compile the shell
make run    # run the shell
make re     # clean and rebuild
make debug  # compile with debug symbols and launch GDB

Run directly
./bin/minishellbasic_app

---

🔍 Function Overview | Présentation des fonctions

| Function Name     | Description (EN)                        | Description (FR)                                     |
| ----------------- | --------------------------------------- | ---------------------------------------------------- |
| `parse_input`     | Splits input line into arguments        | Sépare la ligne d'entrée en arguments                |
| `is_builtin`      | Checks if command is built-in           | Vérifie si la commande est interne                   |
| `builtin_exit`    | Exits the shell                         | Quitte le shell                                      |
| `builtin_pwd`     | Prints the current working directory    | Affiche le répertoire courant                        |
| `builtin_cd`      | Changes current directory               | Change le répertoire courant                         |
| `execute_command` | Forks a process to run external command | Crée un processus pour exécuter une commande externe |

---

🧪 Sample Output | Exemple de sortie
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

---

🧪 Testing & Debugging | Tests et débogage
Debugging with Makefile | Débogage avec Makefile
make debug

Adds debug symbols (-g)
Cleans and recompiles
Launches GDB for step-by-step debugging

Example GDB commands:
run                 # Start shell
break main          # Breakpoint at main
next                # Step to next line
print parsed_args[0]# Inspect variables
continue            # Continue execution
quit                # Exit GDB

Memory checking with Valgrind | Vérification mémoire avec Valgrind
valgrind --leak-check=full ./bin/minishellbasic_app

Detects memory leaks and invalid accesses
Test with commands like pwd, cd, unknown commands
Ensure shell exits cleanly → Valgrind should report 0 leaks

---

⚡ Limitations / Future improvements | Limitations / Améliorations futures

No support for pipes (|) or redirection (>, <)
No command history
Limited error messages for invalid commands
Could add environment variable support

---

🛡️ License | Licence

This project is licensed under the MIT License — feel free to use, modify, and share.
Ce projet est sous licence MIT — libre à vous de l’utiliser, le modifier et le partager.