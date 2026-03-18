════════════ ENGLISH ════════════

🧠 Multi-Client TCP Server in C

A lightweight multi-client TCP chat server written in C, designed to demonstrate low-level networking, I/O multiplexing, and resource management using `select()`.

This project intentionally focuses on simplicity and clarity rather than production-scale complexity.

---

✅ Features

- TCP server using BSD sockets
- Concurrent client handling with `select()`
- Connection and disconnection detection
- Message broadcasting between clients
- Event logging with timestamps
- Deterministic resource cleanup
- Clean and readable C99 code

---

📁 Structure
```
Server/
├── include/
│   └── server.h
├── src/
│   ├── server.c
│   └── main.c
├── build/
│   └── *.o
├── bin/
│   └── server
├── Makefile
└── README.md
```

---

⚙️ Compilation & Execution
```
make
make run
make debug
make clean
```

---

🔍 Function Overview

| Function | Description |
|---|---|
| `log_event` | Writes timestamped server events to a log file |
| `broadcast_message` | Sends a message to all connected clients except the sender |
| `accept_new_client` | Accepts and registers a new client socket |
| `handle_client_data` | Handles reception, logging, and broadcasting of client data |
| `main` | Initializes the server and manages the event loop |

---

🚀 Design Choices

**Why `select()`?**
`select()` was chosen to explicitly demonstrate I/O multiplexing without threads. This makes client lifecycle management and file descriptor handling fully visible and deterministic.

**Why a fixed-size client array?**
Using a fixed-size array (`MAX_CLIENTS`) simplifies memory management and avoids dynamic allocation during runtime. This decision favors predictability over scalability.

**Why blocking sockets?**
Blocking sockets keep the control flow simple and readable. Handling partial reads/writes is intentionally left as a future improvement.

---

🧪 Sample Output
```
Le serveur écoute sur le port : 8080
Nouveau client connecté : fd = 5
Client fd = 5 dit : Bonjour
Client fd = 5 s'est déconnecté
```

---

⚡ Limitations

- `select()` scalability limitations
- Fixed maximum number of clients
- No application-level protocol
- Blocking I/O
- No authentication or encryption

These limitations are known and accepted by design.

---

📌 Possible Improvements

- Replace `select()` with `poll()` or `epoll()`
- Add non-blocking sockets
- Implement message framing
- Handle partial `send()` / `recv()`
- Graceful shutdown via signals

---

🛡️ License

MIT License — free to use, modify, and share.



════════════ FRANÇAIS ════════════

🧠 Serveur TCP multi-clients en C

Un serveur TCP multi-clients de type chat écrit en C, conçu pour démontrer la programmation réseau bas niveau, le multiplexage d'E/S et la gestion des ressources avec `select()`.

Ce projet privilégie volontairement la simplicité et la clarté plutôt qu'une complexité de niveau production.

---

✅ Fonctionnalités

- Serveur TCP avec sockets BSD
- Gestion concurrente des clients avec `select()`
- Détection des connexions et déconnexions
- Diffusion des messages entre clients
- Journalisation des événements avec horodatage
- Libération déterministe des ressources
- Code propre et lisible en C99

---

📁 Structure
```
Server/
├── include/
│   └── server.h
├── src/
│   ├── server.c
│   └── main.c
├── build/
│   └── *.o
├── bin/
│   └── server
├── Makefile
└── README.md
```

---

⚙️ Compilation & Exécution
```
make
make run
make debug
make clean
```

---

🔍 Présentation des fonctions

| Fonction | Description |
|---|---|
| `log_event` | Écrit les événements serveur horodatés dans un fichier |
| `broadcast_message` | Envoie un message à tous les clients sauf l'expéditeur |
| `accept_new_client` | Accepte et enregistre un nouveau socket client |
| `handle_client_data` | Gère la réception, la journalisation et la diffusion |
| `main` | Initialise le serveur et gère la boucle principale |

---

🚀 Choix de conception

**Pourquoi `select()` ?**
`select()` a été choisi pour illustrer clairement le multiplexage d'E/S sans threads, rendant la gestion du cycle de vie des clients explicite et contrôlable.

**Pourquoi un tableau client de taille fixe ?**
L'utilisation d'un tableau de taille fixe (`MAX_CLIENTS`) simplifie la gestion mémoire et évite les allocations dynamiques à l'exécution. Cette décision privilégie la prévisibilité à l'évolutivité.

**Pourquoi des sockets bloquantes ?**
Les sockets bloquantes permettent de garder un flux de contrôle clair et pédagogique. La gestion des lectures/écritures partielles est laissée comme amélioration future.

---

🧪 Exemple de sortie
```
Le serveur écoute sur le port : 8080
Nouveau client connecté : fd = 5
Client fd = 5 dit : Bonjour
Client fd = 5 s'est déconnecté
```

---

⚡ Limitations

- Limitations de scalabilité de `select()`
- Nombre maximum de clients fixé
- Pas de protocole applicatif
- Entrées/sorties bloquantes
- Pas d'authentification ni de chiffrement

Ces limitations sont connues et acceptées par conception.

---

📌 Améliorations possibles

- Remplacer `select()` par `poll()` ou `epoll()`
- Ajouter des sockets non bloquantes
- Implémenter le découpage des messages
- Gérer les `send()` / `recv()` partiels
- Arrêt gracieux via les signaux

---

🛡️ Licence

Licence MIT — libre d'utilisation, modification et diffusion.