# Parse JSON in C | Analyseur JSON en C

A simple JSON parser in C supporting **objects**, **arrays**, **strings**, **numbers**, **booleans**, and **null values**.  
Un analyseur JSON en C supportant **objets**, **tableaux**, **chaînes**, **nombres**, **booléens** et **valeurs null**.  

---

## 🧠 Features | Fonctionnalités

✅ Parses JSON objects (`{}`) and arrays (`[]`)  
✅ Supports JSON values: strings, numbers, booleans, null, nested arrays and objects  
✅ Dynamic memory allocation for JSON structures (`malloc`, `realloc`)  
✅ Prints JSON in **compact or indented format**  
✅ Clean and readable C99 code  
✅ Escape sequences handling | Gestion des échappements

\" → "
\n → newline
\t → tab
\\ → \
\r, \b, \f, \/

---

## 📁 Structure

Parse_JSON/
├── include/  
│   └── parse_json.h  
├── src/  
│   ├── Parse_JSON.c  
│   └── main.c  
├── Makefile  
└── README.md  

---

## ⚙️ Compilation & Execution | Compilation & exécution

With Make:

```bash
make        # compile the parser
make run    # run the parser
make re     # clean and rebuild
make debug  # compile with debug symbols and launch GDB

./bin/parsejson_app

---

🔍 Function Overview | Présentation des fonctions
Function Name	Description (EN)	Description (FR)
parse_value	Parses any JSON value (string, number, object, array, etc.)	Analyse une valeur JSON (chaîne, nombre, objet, tableau, etc.)
parse_object	Parses a JSON object ({})	Analyse un objet JSON ({})
parse_array	Parses a JSON array ([])	Analyse un tableau JSON ([])
parse_string	Parses a JSON string	Analyse une chaîne JSON
parse_number	Parses a JSON number	Analyse un nombre JSON
parse_boolean	Parses true or false	Analyse true ou false
parse_null	Parses null	Analyse null
skip_whitespace	Skips spaces, tabs, newlines	Ignore les espaces, tabulations et retours à la ligne
free_value	Frees memory allocated for a JSONValue recursively	Libère la mémoire allouée pour une JSONValue récursive
print_value	Prints a JSONValue in compact or pretty format	Affiche une JSONValue en format compact ou indenté

---

🧪 Sample Output | Exemple de sortie

Input: {"nom":"Eren","age":21,"actif":true,"notes":[12,15.5,19],"amis":[{"nom":"Armin"},{"nom":"Mikasa"}],"adresse":null}


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

🧪 Testing & Debugging | Tests et débogage
Debugging with Makefile | Débogage avec Makefile

make debug
Adds debug symbols (-g)
Cleans and recompiles

Launches GDB for step-by-step debugging
Example GDB commands:
run                  # Start program
break main           # Breakpoint at main
next                 # Step to next line
print root           # Inspect root JSONValue
continue             # Continue execution
quit                 # Exit GDB

Memory checking with Valgrind | Vérification mémoire avec Valgrind
valgrind --leak-check=full ./bin/parsejson_app

Detects memory leaks and invalid accesses
Test with nested objects and arrays
Ensure parser frees all memory → Valgrind should report 0 leaks

---

⚡ Limitations / Future improvements | Limitations / Améliorations futures

No support for JSON comments (non-standard)
Limited error reporting for malformed JSON
Could add JSON pretty-printing options
Could add streaming parsing for very large files

---

🛡️ License | Licence

This project is licensed under the MIT License — feel free to use, modify, and share.
Ce projet est sous licence MIT — libre à vous de l’utiliser, le modifier et le partager.
