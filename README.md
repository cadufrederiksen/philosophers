# 🧠 Philosophers - Programação Concorrente e Sincronização

![C](https://img.shields.io/badge/Language-C-blue) ![POSIX](https://img.shields.io/badge/Library-POSIX-orange) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow) ![Multithreading](https://img.shields.io/badge/Feature-Multithreading-green)

O projeto **Philosophers** aborda o clássico problema dos filósofos comensais, oferecendo uma introdução prática à programação concorrente, sincronização de threads e prevenção de deadlocks. Este projeto ajuda a desenvolver habilidades para gerenciar recursos compartilhados de maneira eficiente e segura em aplicações multithread.

---

## 📋 Objetivo do Projeto

Criar uma solução para o problema dos filósofos comensais, em que:
- **Vários filósofos compartilham recursos limitados (os garfos).**
- Cada filósofo alterna entre os estados de **comer**, **pensar** e **dormir**.
- É necessário evitar problemas como:
  - **Deadlocks**: quando os filósofos ficam bloqueados esperando por recursos.  
  - **Inanição**: quando um ou mais filósofos nunca conseguem acessar os recursos.

O projeto utiliza **POSIX threads**, **mutexes** e **semáforos** para sincronizar as ações dos filósofos e garantir a eficiência e a segurança do programa.

---

## 📚 Conceitos Fundamentais

- **Programação Concorrente**: execução simultânea de múltiplas threads.  
- **Sincronização**: controle de acesso a recursos compartilhados utilizando mutexes e semáforos.  
- **Prevenção de Deadlocks**: estratégias para evitar que threads fiquem bloqueadas.  
- **PThreads (POSIX Threads)**: biblioteca para criar e gerenciar threads em sistemas Unix.  
- **Semáforos**: ferramentas para gerenciar múltiplos acessos a um recurso compartilhado.  

---

## ✨ Funcionalidades Implementadas

### 🧩 Lógica do Problema
1. Cada filósofo tem acesso a:
   - **Garfos (recursos compartilhados)**.
   - Tempo de vida limitado sem comer (simulação de fome).  
2. A simulação deve seguir as regras:
   - Um filósofo só pode comer se tiver dois garfos disponíveis.  
   - Após comer, o filósofo deve dormir e, em seguida, pensar.  
   - A simulação termina se qualquer filósofo morrer de fome.

### 🔧 Recursos Técnicos
- **Criação de Threads**: cada filósofo é representado por uma thread.  
- **Uso de Mutexes**:
  - Garantem o acesso exclusivo aos garfos compartilhados.  
- **Semáforos**:
  - Controlam a quantidade de recursos disponíveis.  
- **Sincronização**:
  - Evita condições de corrida e garante que as threads sigam as regras.  
- **Detecção de Fome/Morte**:
  - Monitoramento contínuo para encerrar a simulação caso um filósofo não consiga comer a tempo.  

### ⚙️ Configurações da Simulação
- **Número de Filósofos**: definido pelo usuário.  
- **Tempo de Simulação**: 
  - Tempo para comer, dormir e pensar.  
  - Tempo máximo que um filósofo pode passar sem comer.  

---

## 📊 Estratégias de Prevenção de Deadlocks

Para garantir que os filósofos possam coexistir sem bloqueios, foram implementadas as seguintes estratégias:

### 🥢 Recurso Compartilhado Limitado
- Apenas **n-1 filósofos** podem tentar pegar garfos simultaneamente.  
- Essa limitação é gerenciada utilizando **semáforos**, prevenindo situações em que todos os filósofos bloqueiem esperando por recursos.

### 🔄 Ordem de Pegar os Garfos
- Cada filósofo sempre pega o **garfo mais próximo** primeiro.  
- Essa abordagem garante **consistência na sincronização** e evita condições de corrida.

### ⏱️ Monitoramento Contínuo
- O sistema monitora continuamente o **tempo desde a última refeição de cada filósofo**.  
- Essa verificação previne **mortes inesperadas** ao assegurar que nenhum filósofo fique sem comer por tempo excessivo.

Essas estratégias são fundamentais para evitar **deadlocks**, **inanição** e outros problemas comuns em sistemas de concorrência.

---

## 🛠️ Ferramentas e Padrões

| Ferramenta/Padrão      | Descrição                                               |
|-------------------------|-------------------------------------------------------|
| **PThreads**           | Biblioteca POSIX para criar e gerenciar threads.      |
| **Mutexes**            | Controle de acesso exclusivo a recursos compartilhados. |
| **Semáforos**          | Sincronização de múltiplos acessos simultâneos.       |
| **Makefile**           | Automação da compilação e geração do executável.      |
| **Norminette**         | Garantia de conformidade com os padrões de estilo da 42. |

---

