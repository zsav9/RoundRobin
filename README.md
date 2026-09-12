# Round Robin scheduler
C implementation of the **Round Robin** scheduling algorithm, one of the classic process scheduling methods in Operating Systems. The output is in Portuguese.

## Program description

The program simulates the execution of 8 processes with different execution times, using a fixed time slice (a quantum) to alternate between them until all are finished.

## How it works

Each process is represented by a struct (`processo_t`) containing:
  - `id`: process identifier.
  - `tempo_execucao`: remaining CPU time needed.
  - `finalizado`: indicates whether the process has already finished.

- The algorithm cyclically goes through the process queue, running each one for up to `quantum` time units at a time, until its execution time reaches zero.

## Technologies

- C
- Standard library (`stdio.h`, `stdbool.h`)

## Context

Project developed for the OS course.
