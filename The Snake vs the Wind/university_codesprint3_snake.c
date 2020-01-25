#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int     **grid_create(int size)
{
    int i;
    int **grid;

    i = 0;
    grid = (int **)malloc(sizeof(int *) * size);
    while (i < size)
    {
        grid[i] = (int *)malloc(sizeof(int) * size);
        i++;
    }
    return (grid);
}
void     grid_init(int **grid, int size)
{
    int y;
    int x;

    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            grid[y][x] = 0;
            x++;
        }
        y++;
    }
}

void grid_print(int **grid, int size)
{
    int     y;
    int     x;

    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            printf("%i", grid[y][x]);
            if (x + 1 != size)
            {
                printf(" ");
            }
            x++;
        }
        printf("\n");
        y++;
    }
}

void n_snake(int **grid, int size, int x, int y)
{
    int step;
    int copy_x = x;
    int copy_y = y;

    step = 1;
    grid[y][x] = step;
    step++;
    while (step <= (size * size))
    {
        if (copy_y - 1 >= 0 && grid[copy_y - 1][copy_x] == 0)
        {
            grid[copy_y - 1][copy_x] = step;
            copy_y--;
            step++;
        }
        else if (copy_x - 1 >= 0 && grid[copy_y][copy_x - 1] == 0)
        {
            grid[copy_y][copy_x - 1] = step;
            copy_x--;
            step++;
        }
        else if (copy_x + 1 < size && grid[copy_y][copy_x + 1] == 0)
        {
            grid[copy_y][copy_x + 1] = step;
            copy_x++;
            step++;
        }
        else if (copy_y + 1 < size && grid[copy_y + 1][copy_x] == 0)
        {
            grid[copy_y + 1][copy_x] = step;
            copy_y++;
            step++;
        }
        else
        {
            step++;
        }
    }
}

void s_snake(int **grid, int size, int x, int y)
{
    int step;
    int copy_x = x;
    int copy_y = y;

    step = 1;
    grid[y][x] = step;
    step++;
    while (step <= (size * size))
    {
        if (copy_y + 1 < size && grid[copy_y + 1][copy_x] == 0)
        {
            grid[copy_y + 1][copy_x] = step;
            copy_y++;
            step++;
        }
        else if (copy_x - 1 >= 0 && grid[copy_y][copy_x - 1] == 0)
        {
            grid[copy_y][copy_x - 1] = step;
            copy_x--;
            step++;
        }
        else if (copy_x + 1 < size && grid[copy_y][copy_x + 1] == 0)
        {
            grid[copy_y][copy_x + 1] = step;
            copy_x++;
            step++;
        }
        else if (copy_y - 1 >= 0 && grid[copy_y - 1][copy_x] == 0)
        {
            grid[copy_y - 1][copy_x] = step;
            copy_y--;
            step++;
        }
        else
        {
            step++;
        }
    }
}

void w_snake(int **grid, int size, int x, int y)
{
    int step;
    int copy_x = x;
    int copy_y = y;

    step = 1;
    grid[y][x] = step;
    step++;
    while (step <= (size * size))
    {
        if (copy_x - 1 >= 0 && grid[copy_y][copy_x - 1] == 0)
        {
            grid[copy_y][copy_x - 1] = step;
            copy_x--;
            step++;
        }
        else if (copy_y - 1 >= 0 && grid[copy_y - 1][copy_x] == 0)
        {
            grid[copy_y - 1][copy_x] = step;
            copy_y--;
            step++;
        }
        else if (copy_y + 1 < size && grid[copy_y + 1][copy_x] == 0)
        {
            grid[copy_y + 1][copy_x] = step;
            copy_y++;
            step++;
        }
        else if (copy_x + 1 < size && grid[copy_y][copy_x + 1] == 0)
        {
            grid[copy_y][copy_x + 1] = step;
            copy_x++;
            step++;
        }
        else
        {
            step++;
        }
    }
}

void e_snake(int **grid, int size, int x, int y)
{
    int step;
    int copy_x = x;
    int copy_y = y;

    step = 1;
    grid[y][x] = step;
    step++;
    while (step <= (size * size))
    {
        if (copy_x + 1 < size && grid[copy_y][copy_x + 1] == 0)
        {
            grid[copy_y][copy_x + 1] = step;
            copy_x++;
            step++;
        }
        else if (copy_y - 1 >= 0 && grid[copy_y - 1][copy_x] == 0)
        {
            grid[copy_y - 1][copy_x] = step;
            copy_y--;
            step++;
        }
        else if (copy_y + 1 < size && grid[copy_y + 1][copy_x] == 0)
        {
            grid[copy_y + 1][copy_x] = step;
            copy_y++;
            step++;
        }
        else if (copy_x - 1 >= 0 && grid[copy_y][copy_x - 1] == 0)
        {
            grid[copy_y][copy_x - 1] = step;
            copy_x--;
            step++;
        }
        else
        {
            step++;
        }
    }
}

int main() {
    int n;
    scanf("%i", &n);
    char d;
    scanf(" %c", &d);
    int x;
    int y;
    scanf("%i %i", &x, &y);
    // Write Your Code Here

	int step;

	step = 1;

	//malloc for int grid of size n x n
	int **grid;
	grid = grid_create(n);
    grid_init(grid, n);

	//wind = n
    if (d == 'n')
    {
        n_snake(grid, n, y, x);
        grid_print(grid, n);
        return (1);
    }
    if (d == 's')
    {
        s_snake(grid, n, y, x);
        grid_print(grid, n);
        return (1);
    }
    if (d == 'w')
    {
        w_snake(grid, n, y, x);
        grid_print(grid, n);
        return (1);
    }
    if (d == 'e')
    {
        e_snake(grid, n, y, x);
        grid_print(grid, n);
        return (1);
    }

    return 0;
}
