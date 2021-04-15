#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <string.h>

void	execute_instructions(char *line, t_stock *stocka, t_stock *stockb)
{
	printf("       >>>>> EXECUTE_INSTRUCTIONS\n");
	if (ft_strncmp("sa\n", line, 3) == 0 || !ft_strncmp("ss\n", line, 3))
		swap(stocka, "sa\n");
	if (ft_strncmp("sb\n", line, 3) == 0 || !ft_strncmp("ss\n", line, 3))
		swap(stockb, "sb\n");
	else if (ft_strncmp("pa\n", line, 3) == 0)
		push(stockb, stocka, "");
	else if (ft_strncmp("pb\n", line, 3) == 0)
		push(stocka, stockb, "");
	else if (ft_strncmp("ra\n", line, 3) == 0 || !ft_strncmp("rr\n", line, 3))
		rotate(stocka, "");
	if (ft_strncmp("rb\n", line, 3) == 0 || !ft_strncmp("rr\n", line, 3))
		rotate(stockb, "");
	if (ft_strncmp("rra\n", line, 3) == 0 || !ft_strncmp("rrr\n", line, 3))
		reverse_rotate(stocka, "");
	if (ft_strncmp("rrb\n", line, 3) == 0 || !ft_strncmp("rrr\n", line, 3))
		reverse_rotate(stockb, "");
	///// RESULT SHOW
	print_stacks(stocka, stockb);
}

int		check_instructions(char *line, t_stock *stocka, t_stock *stockb)
{
	const char	*instr[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", 0};
	int			k;
	int			i;
	int			ok;

	i = 0;
	ok = 1;
	while (instr[i])
	{
		k = 0;
		while (ft_isalpha(line[k]))
			k++;
		if (k < 4 && ft_strncmp(instr[i], line, 3) == 0)
			ok = 0;
		i++;
	}
	if (ok == 1)
	{
		write(1, "Error\n", 6);
		printf("not in instruction_set, line is [%s]\n", line);
		exit (1); /// to be changed
	}
	else
		execute_instructions(line, stocka, stockb);
	return (ok);
}

int	read_instructions2(t_stock *stocka, int ret)
{
	if (ret == 0)
		stack_order(stocka);
	else
	{
		write(1, "Error\n", 6);
		printf("ret error\n");
		return (1);
	}
	return (0);
}

int	read_instructions(t_stock *stocka, t_stock *stockb)
{
	int		ret;
	char	line[4];

	ft_bzero(line, 3);
	if ((ret = read(STDIN_FILENO, line, 4)) <= 0)
		read_instructions2(stocka, ret);
	else
	{
		check_instructions(&line[0], stocka, stockb);
		while ((ret = read(STDIN_FILENO, line, 5)) >= 0)
		{
			if (ret == 0)
			{
				stack_order(stocka);
				break ;
			}
			check_instructions(line, stocka, stockb);
		}
	}
	return (0);
}
