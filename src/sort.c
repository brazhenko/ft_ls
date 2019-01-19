/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 03:38:48 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/19 03:46:46 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		files_count(t_file *begin)
{
	int		len;

	len = 0;
	while (begin)
	{
		begin = begin->next;
		len++;
	}
	return (len);
}

t_file			*insert_sort(t_file **begin, int (*cmp)(t_file *, t_file *))
{
	t_file		*sorted;
	int			len;
	t_file		*current_min;
	t_file		*begin_cpy;
	t_file		*sorted_to_return;

	sorted = NULL;
	sorted_to_return = NULL;
	current_min = NULL;
	begin_cpy = *begin;
	len = files_count(*begin);
	while (len)
	{
		while (begin_cpy)
		{
			if (cmp(current_min, begin_cpy) > 0 && begin_cpy->is_handled != 1)
				current_min = begin_cpy;
			begin_cpy = begin_cpy->next;
		}
		current_min->is_handled = 1;
		add_to_lst(&sorted, current_min);
		if (!sorted_to_return)
			sorted_to_return = sorted;
		current_min = NULL;
		begin_cpy = *begin;
		len--;
	}
	return (sorted_to_return);
}
 
// int				main(void)																		
// {
// 	t_file *begin = file_creator("FIRST", 1);
// 	begin->next = file_creator("SECOND", 3);
// 	begin->next->next = file_creator("THIRD", 2);
// 	begin->next->next->next = file_creator("FORTH", 0);
// 
// 
// 	printf("%s  %d\n", begin->name, begin->time_in_seconds);
// 	printf("%s  %d\n", begin->next->name, begin->next->time_in_seconds);
// 	printf("%s  %d\n", begin->next->next->name, begin->next->next->time_in_seconds);
// 	printf("%s  %d\n", begin->next->next->next->name, begin->next->next->next->time_in_seconds);
// 	
// 	printf("\n");
// 	t_file *new = insert_sort(&begin, &date_cmp);
// 	printf("\n");
// 	while (new)
// 	{
// 		printf("%s  %d\n", new->name, new->time_in_seconds);
// 		new = new->next;
// 	}
// 	return (0);
// }
