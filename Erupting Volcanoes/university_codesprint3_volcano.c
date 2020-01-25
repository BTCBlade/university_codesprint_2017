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
void grid_add_volcano(int **grid, int size, int x, int y, int w)
{
    int w_step;
    int x_low;
    int x_high;
    int y_high;
    int y_low;
    int mod;

    mod = 1;
    w_step = w;
    grid[y][x] = grid[y][x] + w;

    while (mod < w)
    {
        x_low = x - mod;
        x_high = x + mod;
        y_low = y - mod;
        y_high = y + mod;

        while (x_low < x_high)
        {
            if (x_low >= 0 && x_low < size && y_low >= 0 && y_low < size)
                grid[y_low][x_low] = grid[y_low][x_low] + (w - mod);
            x_low++;
        }
        while (y_low < y_high)
        {
            if (y_low >= 0 && y_low < size && x_high < size && x_high >= 0)
                grid[y_low][x_high] = grid[y_low][x_high] + (w - mod);
            y_low++;
        }
        while (x_high > (x - mod))
        {
            if (x_high >= 0 && x_high < size && y_high >= 0 && y_high < size)
                grid[y_high][x_high] = grid[y_high][x_high] + (w - mod);
            x_high--;
        }
        while (y_high > (y - mod))
        {
            if (y_high >= 0 && y_high < size && (x - mod) >= 0 && (x - mod) < size)
                grid[y_high][x - mod] = grid[y_high][x - mod] + (w - mod);
            y_high--;
        }
        mod++;
    }
}

int grid_biggest_number(int **grid, int size)
{
    int y;
    int x;
    int ret;

    ret = 0;
    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            if (ret < grid[y][x])
                ret = grid[y][x];
            x++;
        }
        y++;
    }
    return (ret);
}

int main() {
    int n;
    scanf("%i", &n);
    int **grid;
    grid = grid_create(n);
    grid_init(grid, n);


    int m;
    scanf("%i", &m);

    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        int w;
        scanf("%i %i %i", &x, &y, &w);
        // Write Your Code Here
        grid_add_volcano(grid, n, x, y, w);
    }
    printf("%i", grid_biggest_number(grid, n));
    return 0;
}
