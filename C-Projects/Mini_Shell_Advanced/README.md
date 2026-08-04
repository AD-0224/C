## 🇬🇧 English

🧠 Mini Shell Advanced — a Unix shell written from scratch in C

A fully working Unix shell built from the ground up in C: custom
lexer/parser, real process execution (fork/execve), pipes,
redirections, builtins, environment variable expansion, signal
handling, and heredoc support — powered by GNU readline for a real
interactive experience.

```
minishell:~$ echo "build your own shell" | tr 'a-z' 'A-Z'
BUILD YOUR OWN SHELL
```

✅ Features
- Custom lexer & parser (pipelines, redirections, single/double quotes)
- Pipes of any length (`cmd1 | cmd2 | cmd3 | ...`)
- Redirections: `<`, `>`, `>>`, and `<<` (heredoc)
- Builtins: `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- Variable expansion: `$VAR`, `$?` (last exit status), `$$` (PID) —
  correctly skipped inside single quotes
- Signal handling: `Ctrl-C` returns a clean prompt, `Ctrl-D` exits,
  `Ctrl-\` is ignored at the prompt (matches real shell behavior)
- Line editing & history via GNU `readline`
- Colored prompt showing the current working directory
- Zero memory leaks (`valgrind --leak-check=full`)

📁 Structure
```
Mini_Shell_Advanced/
├── include/
│   └── shell.h
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── lexer.c
│   ├── parser.c
│   ├── expand.c
│   ├── exec.c
│   ├── builtins.c
│   ├── heredoc.c
│   ├── signals.c
│   ├── prompt.c
│   └── utils.c
├── Makefile
└── README.md
```

⚙️ Compilation & Execution
```sh
make
make run
```
Requires `libreadline-dev` (or equivalent) installed.

🔍 Function Overview
| File | Role |
|---|---|
| `lexer.c` | Splits a raw line into tokens (words, pipes, redirections) |
| `parser.c` | Turns tokens into a linked list of structured commands |
| `expand.c` | Expands `$VAR`, `$?`, `$$` before execution |
| `exec.c` | `fork`/`execve`/`pipe`/`dup2` — runs single commands & pipelines |
| `builtins.c` | Implements `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit` |
| `heredoc.c` | Reads `<<` input from the keyboard into a temp file |
| `signals.c` | Handles `SIGINT` / `SIGQUIT`, at the prompt and during heredocs |
| `prompt.c` | Builds the colored, dynamic prompt |

🧪 Sample Session
```
minishell:~$ ls -la | grep .c | wc -l
9
minishell:~$ echo hello > out.txt && cat out.txt
hello
minishell:~$ export NAME=world
minishell:~$ echo "hello $NAME"
hello world
minishell:~$ cat << EOF
> some text
> EOF
some text
```

🗺️ Roadmap
- [ ] Logical operators `&&`, `||`, `;`
- [ ] Wildcard expansion (`*.c`)
- [ ] `alias` support
- [ ] Job control (`&`, `fg`, `bg`)

🛡️ License
MIT License — feel free to use, modify and share.

## 🇫🇷 Français

🧠 Mini Shell Advanced — un shell Unix écrit de zéro en C

Un vrai shell Unix fonctionnel, entièrement codé à la main en C :
lexer/parser maison, exécution réelle de processus (fork/execve),
pipes, redirections, builtins, expansion de variables d'environnement,
gestion des signaux et support du heredoc — le tout appuyé sur GNU
readline pour une vraie expérience interactive.

```
minishell:~$ echo "mon propre shell" | tr 'a-z' 'A-Z'
MON PROPRE SHELL
```

✅ Fonctionnalités
- Lexer et parser maison (pipelines, redirections, guillemets simples/doubles)
- Pipes à volonté (`cmd1 | cmd2 | cmd3 | ...`)
- Redirections : `<`, `>`, `>>`, et `<<` (heredoc)
- Builtins : `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- Expansion de variables : `$VAR`, `$?` (dernier code de sortie), `$$`
  (PID) — correctement ignorée entre guillemets simples
- Gestion des signaux : `Ctrl-C` redonne un prompt propre, `Ctrl-D`
  quitte, `Ctrl-\` est ignoré au prompt (comme un vrai shell)
- Édition de ligne et historique via GNU `readline`
- Prompt coloré affichant le dossier courant
- Zéro fuite mémoire (`valgrind --leak-check=full`)

📁 Structure
```
Mini_Shell_Advanced/
├── include/
│   └── shell.h
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── lexer.c
│   ├── parser.c
│   ├── expand.c
│   ├── exec.c
│   ├── builtins.c
│   ├── heredoc.c
│   ├── signals.c
│   ├── prompt.c
│   └── utils.c
├── Makefile
└── README.md
```

⚙️ Compilation & Exécution
```sh
make
make run
```
Nécessite `libreadline-dev` (ou équivalent) installé.

🔍 Présentation des fichiers
| Fichier | Rôle |
|---|---|
| `lexer.c` | Découpe une ligne brute en tokens (mots, pipes, redirections) |
| `parser.c` | Transforme les tokens en liste chaînée de commandes structurées |
| `expand.c` | Développe `$VAR`, `$?`, `$$` avant l'exécution |
| `exec.c` | `fork`/`execve`/`pipe`/`dup2` — exécute commande simple et pipelines |
| `builtins.c` | Implémente `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit` |
| `heredoc.c` | Lit le contenu du `<<` au clavier dans un fichier temporaire |
| `signals.c` | Gère `SIGINT` / `SIGQUIT`, au prompt et pendant les heredocs |
| `prompt.c` | Construit le prompt coloré et dynamique |

🧪 Exemple de session
```
minishell:~$ ls -la | grep .c | wc -l
9
minishell:~$ echo hello > out.txt && cat out.txt
hello
minishell:~$ export NAME=world
minishell:~$ echo "hello $NAME"
hello world
minishell:~$ cat << EOF
> du texte
> EOF
du texte
```

🗺️ Roadmap
- [ ] Opérateurs logiques `&&`, `||`, `;`
- [ ] Expansion des wildcards (`*.c`)
- [ ] Support des `alias`
- [ ] Contrôle de jobs (`&`, `fg`, `bg`)

🛡️ Licence
Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.