════════════ ENGLISH ════════════

🧠 Parse JSON in C

A simple JSON parser in C supporting objects, arrays, strings, numbers, booleans, and null values.

---

✅ Features

- Parses JSON objects (`{}`) and arrays (`[]`)
- Supports JSON values: strings, numbers, booleans, null, nested arrays and objects
- Dynamic memory allocation for JSON structures (`malloc`, `realloc`)
- Prints JSON in compact or indented format
- Clean and readable C99 code
- Escape sequences handling: `\"` `\n` `\t` `\\` `\r` `\b` `\f` `/`

---

📁 Structure

    Parse_JSON/
    ├── include/
    │   └── parse_json.h
    ├── src/
    │   ├── Parse_JSON.c
    │   └── main.c
    ├── Makefile
    └── README.md

---

⚙️ Compilation & Execution

    make        # compile the parser
    make run    # run the parser
    make re     # clean and rebuild
    make debug  # compile with debug symbols and launch GDB

Run directly:

    ./bin/parsejson_app

---

🔍 Function Overview

| Function | Description |
|---|---|
| `parse_value` | Parses any JSON value (string, number, object, array, etc.) |
| `parse_object` | Parses a JSON object (`{}`) |
| `parse_array` | Parses a JSON array (`[]`) |
| `parse_string` | Parses a JSON string |
| `parse_number` | Parses a JSON number |
| `parse_boolean` | Parses `true` or `false` |
| `parse_null` | Parses `null` |
| `skip_whitespace` | Skips spaces, tabs, newlines |
| `free_value` | Frees memory allocated for a JSONValue recursively |
| `print_value` | Prints a JSONValue in compact or pretty format |

---

🧪 Sample Output

Input:

    {"nom":"Eren","age":21,"actif":true,"notes":[12,15.5,19],"amis":[{"nom":"Armin"},{"nom":"Mikasa"}],"adresse":null}

Parsed output (pretty):

    {
      "nom": "Eren",
      "age": 21,
      "actif": true,
      "notes": [12, 15.5, 19],
      "amis": [{"nom":"Armin"}, {"nom":"Mikasa"}],
      "adresse": null
    }

Parsed output (compact):

    {"nom":"Eren","age":21,"actif":true,"notes":[12,15.5,19],"amis":[{"nom":"Armin"},{"nom":"Mikasa"}],"adresse":null}

---

🧪 Testing & Debugging

**Debugging with Makefile**

    make debug

- Adds debug symbols (`-g`)
- Cleans and recompiles
- Launches GDB for step-by-step debugging

Example GDB commands:

    run                  # Start program
    break main           # Breakpoint at main
    next                 # Step to next line
    print root           # Inspect root JSONValue
    continue             # Continue execution
    quit                 # Exit GDB

**Memory checking with Valgrind**

    valgrind --leak-check=full ./bin/parsejson_app

- Detects memory leaks and invalid accesses
- Test with nested objects and arrays
- Ensure parser frees all memory → Valgrind should report 0 leaks

---

⚡ Limitations & Future Improvements

- No support for JSON comments (non-standard)
- Limited error reporting for malformed JSON
- Could add JSON pretty-printing options
- Could add streaming parsing for very large files

---

🛡️ License

MIT License — feel free to use, modify, and share.



════════════ FRANÇAIS ════════════

🧠 Analyseur JSON en C

Un analyseur JSON en C supportant objets, tableaux, chaînes, nombres, booléens et valeurs null.

---

✅ Fonctionnalités

- Analyse les objets JSON (`{}`) et les tableaux (`[]`)
- Supporte les valeurs JSON : chaînes, nombres, booléens, null, tableaux et objets imbriqués
- Allocation dynamique de mémoire pour les structures JSON (`malloc`, `realloc`)
- Affichage en format compact ou indenté
- Code propre et lisible en C99
- Gestion des séquences d'échappement : `\"` `\n` `\t` `\\` `\r` `\b` `\f` `/`

---

📁 Structure

    Parse_JSON/
    ├── include/
    │   └── parse_json.h
    ├── src/
    │   ├── Parse_JSON.c
    │   └── main.c
    ├── Makefile
    └── README.md

---

⚙️ Compilation & Exécution

    make        # compile l'analyseur
    make run    # lance l'analyseur
    make re     # nettoie et recompile
    make debug  # compile avec symboles de débogage et lance GDB

Exécution directe :

    ./bin/parsejson_app

---

🔍 Présentation des fonctions

| Fonction | Description |
|---|---|
| `parse_value` | Analyse une valeur JSON (chaîne, nombre, objet, tableau, etc.) |
| `parse_object` | Analyse un objet JSON (`{}`) |
| `parse_array` | Analyse un tableau JSON (`[]`) |
| `parse_string` | Analyse une chaîne JSON |
| `parse_number` | Analyse un nombre JSON |
| `parse_boolean` | Analyse `true` ou `false` |
| `parse_null` | Analyse `null` |
| `skip_whitespace` | Ignore les espaces, tabulations et retours à la ligne |
| `free_value` | Libère la mémoire allouée pour une JSONValue récursivement |
| `print_value` | Affiche une JSONValue en format compact ou indenté |

---

🧪 Exemple de sortie

Entrée :

    {"nom":"Eren","age":21,"actif":true,"notes":[12,15.5,19],"amis":[{"nom":"Armin"},{"nom":"Mikasa"}],"adresse":null}

Sortie formatée (pretty) :

    {
      "nom": "Eren",
      "age": 21,
      "actif": true,
      "notes": [12, 15.5, 19],
      "amis": [{"nom":"Armin"}, {"nom":"Mikasa"}],
      "adresse": null
    }

Sortie compacte :

    {"nom":"Eren","age":21,"actif":true,"notes":[12,15.5,19],"amis":[{"nom":"Armin"},{"nom":"Mikasa"}],"adresse":null}

---

🧪 Tests & Débogage

**Débogage avec Makefile**

    make debug

- Ajoute les symboles de débogage (`-g`)
- Nettoie et recompile
- Lance GDB pour un débogage pas à pas

Commandes GDB utiles :

    run                  # Lancer le programme
    break main           # Point d'arrêt au main
    next                 # Passer à la ligne suivante
    print root           # Inspecter la JSONValue racine
    continue             # Continuer l'exécution
    quit                 # Quitter GDB

**Vérification mémoire avec Valgrind**

    valgrind --leak-check=full ./bin/parsejson_app

- Détecte les fuites mémoire et les accès invalides
- Tester avec des objets et tableaux imbriqués
- Le parser doit libérer toute la mémoire → Valgrind doit reporter 0 fuite

---

⚡ Limitations & Améliorations futures

- Pas de support pour les commentaires JSON (non standard)
- Rapport d'erreurs limité pour les JSON malformés
- Ajout possible d'options de pretty-printing
- Ajout possible du parsing en streaming pour les très grands fichiers

---

🛡️ Licence

Projet sous licence MIT — libre à vous de l'utiliser, le modifier et le partager.