# 🧠 Philosophers - Concurrent Programming and Synchronization

![C](https://img.shields.io/badge/Language-C-blue) ![POSIX](https://img.shields.io/badge/Library-POSIX-orange) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow) ![Multithreading](https://img.shields.io/badge/Feature-Multithreading-green)

The **Philosophers** project addresses the classic dining philosophers problem, providing a practical introduction to concurrent programming, thread synchronization, and deadlock prevention. This project helps develop skills to manage shared resources efficiently and safely in multithreaded applications.

---

## 📋 Project Objective

Create a solution for the dining philosophers problem, where:
- **Several philosophers share limited resources (the forks).**
- Each philosopher alternates between the states of **eating**, **thinking**, and **sleeping**.
- It is essential to prevent issues such as:
  - **Deadlocks**: when philosophers become stuck waiting for resources.  
  - **Starvation**: when one or more philosophers never get access to the resources.

The project uses **POSIX threads**, **mutexes**, and **semaphores** to synchronize the philosophers' actions and ensure the program's efficiency and safety.

---

## 📚 Fundamental Concepts

- **Concurrent Programming**: simultaneous execution of multiple threads.  
- **Synchronization**: controlling access to shared resources using mutexes and semaphores.  
- **Deadlock Prevention**: strategies to avoid th
