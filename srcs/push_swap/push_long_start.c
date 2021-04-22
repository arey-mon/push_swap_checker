/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_long_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:46:11 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 16:34:57 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_long_start(t_stock *stocka, int div, t_main *main)
{
	if (div == 1 && *stocka->a >= stocka->first_long && *stocka->a <=
			stocka->second_long)
		push_second_long(main);
	else if (div == 2 && *stocka->a >= stocka->second_long && *stocka->a <=
			stocka->third_long)
		push_third_long(main);
	else if (div == 3 && *stocka->a >= stocka->third_long && *stocka->a <=
			stocka->fourth_long)
		push_fourth_long(main);
	else if (div == 4 && *stocka->a >= stocka->fourth_long && *stocka->a <=
			stocka->median_long)
		push_median_long(main);
	else if (div == 5 && *stocka->a >= stocka->median_long && *stocka->a <=
			stocka->six_long)
		push_six_long(main);
	else if (div == 6 && *stocka->a >= stocka->six_long && *stocka->a <=
			stocka->seven_long)
		push_seven_long(main);
	else if (div == 7 && *stocka->a >= stocka->seven_long && *stocka->a <=
			stocka->eight_long)
		push_eight_long(main);
	else if (div == 8 && *stocka->a >= stocka->eight_long && *stocka->a <=
			stocka->nine_long && *stocka->a != stocka->big)
		push_nine_long(main);
}

void	push_long(t_main *main, t_stock *stocka, int div, int last_a)
{
	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
		if (div == 0 && *stocka->a <= stocka->first_long)
			push_first_long(main);
		else if ((div == 1 && *stocka->a >= stocka->first_long && *stocka->a <=
					stocka->second_long) || (div == 2 && *stocka->a >=
					stocka->second_long && *stocka->a <= stocka->third_long) ||
				(div == 3 && *stocka->a >= stocka->third_long && *stocka->a <=
					stocka->fourth_long) || (div == 4 && *stocka->a >=
					stocka->fourth_long && *stocka->a <= stocka->median_long) ||
				(div == 5 && *stocka->a >= stocka->median_long && *stocka->a <=
					stocka->six_long) || (div == 6 && *stocka->a >=
					stocka->six_long && *stocka->a <= stocka->seven_long) ||
				(div == 7 && *stocka->a >= stocka->seven_long && *stocka->a <=
					stocka->eight_long) || (div == 8 && *stocka->a >=
					stocka->eight_long && *stocka->a <= stocka->nine_long &&
					*stocka->a != stocka->big))
			push_long_start(stocka, div, main);
		else
			rotate(stocka, "ra\n");
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &main->stockb);
}
