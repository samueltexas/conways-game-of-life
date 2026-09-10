#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "winbgi2.h"

#define WIDTH 100
#define HEIGHT 50
#define CELL_SIZE 10
#define WINDOW_WIDTH (WIDTH * CELL_SIZE)
#define WINDOW_HEIGHT (HEIGHT * CELL_SIZE)

void clearBoard(int board[WIDTH][HEIGHT])
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            board[x][y] = 0;
        }
    }
}

void initializeBoard(int board[WIDTH][HEIGHT])
{
    clearBoard(board);

    /*
     * Generate the initial population inside
     * a smaller area of the board.
     */
    for (int x = 10; x < 90; x++)
    {
        for (int y = 5; y < 45; y++)
        {
            board[x][y] = rand() % 2;
        }
    }
}

void drawGrid(void)
{
    for (int i = 0; i <= WINDOW_HEIGHT; i += CELL_SIZE)
    {
        line(i, 0, i, WINDOW_HEIGHT);
        line(i + WINDOW_HEIGHT, 0,
             i + WINDOW_HEIGHT, WINDOW_HEIGHT);
        line(0, i, WINDOW_WIDTH, i);
    }
}

void drawBoard(int board[WIDTH][HEIGHT])
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            if (board[x][y] == 1)
            {
                floodfill(
                    CELL_SIZE * x + CELL_SIZE / 2,
                    CELL_SIZE * y + CELL_SIZE / 2,
                    WHITE
                );
            }
        }
    }
}

int countNeighbors(int board[WIDTH][HEIGHT], int x, int y)
{
    int neighbors = 0;

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }

            int neighborX = x + dx;
            int neighborY = y + dy;

            /*
             * Cells outside the board are considered dead.
             */
            if (neighborX >= 0 && neighborX < WIDTH &&
                neighborY >= 0 && neighborY < HEIGHT)
            {
                neighbors += board[neighborX][neighborY];
            }
        }
    }

    return neighbors;
}

void updateBoard(int board[WIDTH][HEIGHT])
{
    int nextBoard[WIDTH][HEIGHT];

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            int neighbors = countNeighbors(board, x, y);

            /*
             * Conway's Game of Life rules:
             *
             * 1. A live cell survives with 2 or 3 neighbors.
             * 2. A dead cell becomes alive with exactly 3 neighbors.
             * 3. Otherwise the cell dies/remains dead.
             */
            if (board[x][y] == 1 &&
                (neighbors == 2 || neighbors == 3))
            {
                nextBoard[x][y] = 1;
            }
            else if (board[x][y] == 0 && neighbors == 3)
            {
                nextBoard[x][y] = 1;
            }
            else
            {
                nextBoard[x][y] = 0;
            }
        }
    }

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            board[x][y] = nextBoard[x][y];
        }
    }
}

int countPopulation(int board[WIDTH][HEIGHT])
{
    int population = 0;

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            population += board[x][y];
        }
    }

    return population;
}

int main(void)
{
    int board[WIDTH][HEIGHT];
    int frequency;
    int generation = 0;

    printf("Gra w zycie\n\n");
    printf("Plansza ma rozmiar %d x %d kratek.\n", WIDTH, HEIGHT);

    printf("Jaka czestotliwosc krokow [Hz] (liczba calkowita): ");

    if (scanf("%d", &frequency) != 1 || frequency <= 0)
    {
        printf("Nieprawidlowa czestotliwosc.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    printf("Losowanie polozen zywych komorek...\n");

    initializeBoard(board);

    graphics(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (generation < 1000)
    {
        drawGrid();
        drawBoard(board);

        printf("Generacja: %d | Populacja: %d\n",
               generation,
               countPopulation(board));

        animate(frequency);

        updateBoard(board);

        cleardevice();

        generation++;
    }

    wait();

    return 0;
}
