#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include <string.h>
#include <unistd.h>
// it will segfault with this printing 
// but... so useful

void	print_stacks(t_stock *stocka, t_stock *stockb)
{
	int	i;

	i = 0;
	printf("%15s   %15s\n", "Stack A", "Stack B");
	while (stocka->a[i] || stockb->a[i])
	{
		printf("%15d %17d\n", stocka->a[i], stockb->a[i]);
		i++;
	}
}

int		stack_order(t_stock *stock)
{
	int	i;
	int	ok;

	ok = 0;
	i = 0;
	while (stock->size > 1)
	{
		if (stock->a[i] > stock->a[i + 1])
			ok = 1;
		i++;
		stock->size--;
	}
	(ok == 1) ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	return (ok == 1) ? 1 : 0;
}

void	free_program(t_main *main)
{
	free(main->stocka.a);
	free(main->stockb.a);
}

int		main(int ac, char **av)
{
	t_main			main;

	(ac > 1) ? init_stock(&main.stocka, &main.stockb, &av[1], ac) : exit(1);
	read_instructions(&main.stocka, &main.stockb);
	free_program(&main);
	printf("END OF PROGRAM\n");
	return (0);
}
