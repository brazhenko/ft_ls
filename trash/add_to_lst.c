/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 05:01:10 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 13:03:53 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static t_file		*file_cpy_creator(t_file *file)
{
	t_file		*node;

	node = (t_file *)malloc(sizeof(t_file));
	node->name = file->name;
	node->is_dir = file->is_dir;
	node->next = NULL;
	node->permissions = file->permissions;
	node->links = file->links;
	node->owner = file->owner;
	node->year = file->year;
	node->size = file->size;
	node->date = file->date;
	node->time_in_seconds = file->time_in_seconds;
	node->is_handled = 1;
	return (node);
}

void				add_to_lst(t_file **lst, t_file *node)
{
	if (!(*lst))
		(*lst) = file_cpy_creator(node);
	else
	{
		node->previous = *lst;
		(*lst)->next = node;
		// (*lst)->next = file_cpy_creator(node);
		*lst = (*lst)->next;
	}
}
