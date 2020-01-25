#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct			s_list
{
	void				*content;
	int					content_size;

	struct s_list		*next_left;
    struct s_list       *next_up;
    struct s_list       *next_diagnal;
	struct s_list		*prev;

}                       t_board;

void		*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst_container;
	unsigned char	*src_container;
	int				i;

	dst_container = (unsigned char *)dst;
	src_container = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_container[i] = src_container[i];
		i++;
	}
	return (dst);
}

t_board		*ft_lstnew(void const *content, int content_size, t_board *prev)
{
	t_board *new;

	new = (t_board *)malloc(sizeof(t_board));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void*)malloc(content_size);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next_left = NULL;
    new->next_up = NULL;
    new->next_diagnal = NULL;
	new->prev = prev;
	return (new);
}

int can_K_move(char **board, int x, int y)
{
    if ((x - 1 < 0 && y == 0) || (y - 1 < 0 && x == 0))
        return (0);
    if (board[y][x -1] == 'X' && board[y - 1][x - 1] == 'X' && board[y - 1][x])
        return (0);
    return (1);
}

int check_move(char **board, int n)
{
    int x;
    int y;

    y = 0;
    while (y < n)
    {
        x = 0;
        while (x < n)
        {
            if(board[y][x] == 'K')
            {
                printf("%d", can_K_move(board, x, y));
            }
            x++;
        }
        y++;
    }
    return (0);
}

int num_of_kings(char **board, int n)
{
    int x;
    int y;
    int counter;

    counter = 0;
    y = 0;
    while (y < n)
    {
        x = 0;
        while (x < n)
        {
            if(board[y][x] == 'K')
            {
                counter++;
            }
            x++;
        }
        y++;
    }
    return (counter);
}


int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        int n;
        scanf("%i", &n);
        char* *board = malloc(sizeof(char*) * n);
        for (int board_i = 0; board_i < n; board_i++) {
           board[board_i] = (char *)malloc(10240 * sizeof(char));
           scanf("%s",board[board_i]);
        }
        // Write Your Code Here
        printf("%d", num_of_kings(board, n));
    }
    return 0;
}
