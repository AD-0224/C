Multi-Client TCP Server in C
Serveur TCP multi-clients en C
A lightweight multi-client TCP chat server written in C, designed to demonstrate low-level networking, I/O multiplexing, and resource management using select().
Un serveur TCP multi-clients de type chat écrit en C, conçu pour démontrer la programmation réseau bas niveau, le multiplexage d'E/S et la gestion des ressources avec select().
This project intentionally focuses on simplicity and clarity rather than production-scale complexity.
Ce projet privilégie volontairement la simplicité et la clarté plutôt qu'une complexité de niveau production.

---

Features | Fonctionnalités

TCP server using BSD sockets — serveur TCP avec sockets BSD
Concurrent client handling with select() — gestion concurrente avec select()
Connection and disconnection detection — détection des connexions/déconnexions
Message broadcasting between clients — diffusion des messages entre clients
Event logging with timestamps — journalisation avec horodatage
Deterministic resource cleanup — libération déterministe des ressources
Clean and readable C99 code — code propre et lisible en C99

---

Project Structure | Structure du projet

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

---

Compilation & Execution | Compilation et exécution

bashmake
make run
make debug
make clean

---

Function Overview | Présentation des fonctions

log_event

Writes timestamped server events to a log file
Écrit les événements serveur horodatés dans un fichier

broadcast_message

Sends a message to all connected clients except the sender
Envoie un message à tous les clients sauf l'expéditeur

accept_new_client

Accepts and registers a new client socket
Accepte et enregistre un nouveau socket client

handle_client_data

Handles reception, logging, and broadcasting of client data
Gère la réception, la journalisation et la diffusion

main

Initializes the server and manages the event loop
Initialise le serveur et gère la boucle principale

---

Design Choices | Choix de conception

Why select()? | Pourquoi select() ?
select() was chosen to explicitly demonstrate I/O multiplexing without threads. This makes client lifecycle management and file descriptor handling fully visible and deterministic.
select() a été choisi pour illustrer clairement le multiplexage d'E/S sans threads, rendant la gestion du cycle de vie des clients explicite et contrôlable.

Why a fixed-size client array? | Pourquoi un tableau client de taille fixe ?
Using a fixed-size array (MAX_CLIENTS) simplifies memory management and avoids dynamic allocation during runtime. This decision favors predictability over scalability.
L'utilisation d'un tableau de taille fixe (MAX_CLIENTS) simplifie la gestion mémoire et évite les allocations dynamiques à l'exécution. Cette décision privilégie la prévisibilité à l'évolutivité.

Why blocking sockets? | Pourquoi des sockets bloquantes ?
Blocking sockets keep the control flow simple and readable. Handling partial reads/writes is intentionally left as a future improvement.
Les sockets bloquantes permettent de garder un flux de contrôle clair et pédagogique. La gestion des lectures/écritures partielles est laissée comme amélioration future.

---

Example Output | Exemple de sortie
Le serveur écoute sur le port : 8080
Nouveau client connecté : fd = 5
Client fd = 5 dit : Bonjour
Client fd = 5 s'est déconnecté

---

Limitations

select() scalability limitations — Limitations de scalabilité de select()
Fixed maximum number of clients — Nombre maximum de clients fixé
No application-level protocol — Pas de protocole applicatif
Blocking I/O — Entrées/sorties bloquantes
No authentication or encryption — Pas d'authentification ni de chiffrement

These limitations are known and accepted by design.
Ces limitations sont connues et acceptées par conception.

---

Possible Improvements | Améliorations possibles

Replace select() with poll() or epoll() — Remplacer select() par poll() ou epoll()
Add non-blocking sockets — Ajouter des sockets non bloquantes
Implement message framing — Implémenter le découpage des messages
Handle partial send() / recv() — Gérer les send() / recv() partiels
Graceful shutdown via signals — Arrêt gracieux via les signaux

---

License | Licence
MIT License — free to use, modify, and share.
Licence MIT — libre d'utilisation, modification et diffusion.