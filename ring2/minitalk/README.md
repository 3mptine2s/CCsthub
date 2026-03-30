*This project has been created as part of the 42 curriculum by chutterm*

### Description
Minitalk is a system-level programming project designed to explore Inter-Process Communication (IPC) in UNIX environments. The goal of the project is to create a communication program in C, consisting of a Client and a Server, that pass data to each other using strictly UNIX signals.

Because you cannot send strings or integers directly between separate processes, this project requires you to break down data to its most fundamental level: binary.

### Instruction
Execute to create project
```
make
```
Open server to accept signal by execute:
```
./server
```
The server will return PID ID which we will use in client ID
Open another terminal then execute:
```
./client [Server PID ID] [String you want to send]
```

### Resources
42 Minitalk: Building a Simple Client-Server Communication Program in C by AbdulAzeez Shobajo on Medium

### AI Usage
This project use AI to clean code and check error.
