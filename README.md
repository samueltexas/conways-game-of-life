# Conway's Game of Life

A C implementation of Conway's Game of Life, originally developed as an academic project in 2021.

## About the project

This project was developed for the **Informatyka I** course.

The objective was to create a program that simulates Conway's Game of Life according to its classical rules and displays the population state at each time step using the **WinBGI** graphics library.

The original project was submitted on **January 15, 2021**.

## Versions

This repository contains two versions of the project:

### Original 2021 version

Located in:

`original-2021/game_of_life.c`

This is the original version of the program as it was developed and submitted in 2021.

### Refactored version

Located in:

`game_of_life_refactored.c`

This version keeps the original functionality while improving:

- Code structure
- Readability
- Separation of responsibilities
- Input validation
- Array boundary handling
- Use of constants
- Function organization

## Conway's Game of Life

The simulation is based on four simple rules:

1. A live cell with fewer than two live neighbours dies.
2. A live cell with two or three live neighbours survives.
3. A live cell with more than three live neighbours dies.
4. A dead cell with exactly three live neighbours becomes alive.

The simulation runs on a **100 × 50 grid**.

## Technologies

- C
- WinBGI
- Standard C Library
- Random number generation

## Project history

This repository preserves an academic programming project from 2021 and includes a later refactored version to demonstrate the evolution of the code and programming practices.

## Author

Samuel Texa
