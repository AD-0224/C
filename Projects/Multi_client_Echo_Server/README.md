# Multi-Client TCP Server in C  
## Serveur TCP multi-clients en C

A lightweight multi-client TCP chat server written in C, designed to demonstrate low-level networking, I/O multiplexing, and resource management using 'select()'.  
Un serveur TCP multi-clients de type chat écrit en C, conçu pour démontrer la programmation réseau bas niveau, le multiplexage d’E/S et la gestion des ressources avec 'select()'.

This project intentionally focuses on simplicity and clarity rather than production-scale complexity.  
Ce projet privilégie volontairement la simplicité et la clarté plutôt qu’une complexité de niveau production.

---

## 🧠 Features | Fonctionnalités

✅ TCP server using BSD sockets — serveur TCP avec sockets BSD  
✅ Concurrent client handling with 'select()' — gestion concurrente avec 'select()'
✅ Connection and disconnection detection — détection des connexions/déconnexions  
✅ Message broadcasting between clients — diffusion des messages entre clients  
✅ Event logging with timestamps — journalisation avec horodatage  
✅ Deterministic resource cleanup — libération déterministe des ressources  
✅ Clean and readable C99 code — code propre et lisible en C99  

---

## 📁 Project Structure | Structure du projet

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

## ⚙️ Compilation & Execution | Compilation et exécution

```bash
make
make run
make debug
make clean

---

🔍 Function Overview | Présentation des fonctions
Function Name	Description (EN)	Description (FR)
log_event	Writes timestamped server events to a log file	Écrit les événements serveur horodatés dans un fichier
broadcast_message	Sends a message to all connected clients except the sender	Envoie un message à tous les clients sauf l’expéditeur
accept_new_client	Accepts and registers a new client socket	Accepte et enregistre un nouveau socket client
handle_client_data	Handles reception, logging, and broadcasting of client data	Gère la réception, la journalisation et la diffusion
main	Initializes the server and manages the event loop	Initialise le serveur et gère la boucle principale

---

🔧 Design Choices | Choix de conception
Why select()?

select() was chosen to explicitly demonstrate I/O multiplexing without threads.
This makes client lifecycle management and file descriptor handling fully visible and deterministic.

select() a été choisi pour illustrer clairement le multiplexage d’E/S sans threads,
rendant la gestion du cycle de vie des clients explicite et contrôlable.

Why a fixed-size client array?

Using a fixed-size array (MAX_CLIENTS) simplifies memory management and avoids dynamic allocation during runtime.
This decision favors predictability over scalability.

L’utilisation d’un tableau de taille fixe simplifie la gestion mémoire et évite les allocations dynamiques à l’exécution.

Why blocking sockets?

Blocking sockets keep the control flow simple and readable.
Handling partial reads/writes is intentionally left as a future improvement.

Les sockets bloquantes permettent de garder un flux de contrôle clair et pédagogique.

---

🧪 Example Output | Exemple de sortie
Le serveur écoute sur le port : 8080
Nouveau client connecté : fd = 5
Client fd = 5 dit : Bonjour
Client fd = 5 s'est déconnecté

---

⚠️ Limitations | Limitations
select() scalability limitations
Fixed maximum number of clients
No application-level protocol
Blocking I/O
No authentication or encryption

---

These limitations are known and accepted by design.
🚧 Possible Improvements | Améliorations possibles
Replace select() with poll() or epoll()
Add non-blocking sockets
Implement message framing
Handle partial send() / recv()
Graceful shutdown via signals

---

🛡️ License | Licence
MIT License — free to use, modify, and share.
Licence MIT — libre d’utilisation, modification et diffusion.