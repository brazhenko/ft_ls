/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:19:18 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 08:07:04 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			t_file_del(t_file *node)
{
	if (node)
	{
		if (node->next && node->prev)
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
		else if (node->next && !node->prev)
		{
			node->next->prev = NULL;
		}
		else if (!node->next && node->prev)
		{
			node->prev->next = NULL;
		}
	}
}

t_file			*t_file_new(struct dirent *file, char *name, char *full_name)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	new->name = name;
	new->prev = NULL;
	new->next = NULL;
	if ((stat(ft_strjoin(ft_strjoin(full_name, "/"), name),
									&new->dir_stat)) == -1)
	{
		new->is_exist = 0;
	}
	else
	{
		new->is_exist = 1;
	}
	new->dir_dirent = file;
	return (new);
}
