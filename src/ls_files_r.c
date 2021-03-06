/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:25:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/06 04:32:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_dir(t_file *cur_dir)
{
	if (!cur_dir)
		return ;
	if (cur_dir->next && cur_dir->next->prev)
		cur_dir->next->prev = NULL;
	free(cur_dir);
}

int		if_hidden(char *name)
{
	int i;

	i = (int)ft_strlen(name);
	while (--i >= 0)
	{
		if (name[i] == '/')
			return (0);
		if (name[i] == '.')
			return (1);
	}
	return (0);
}

int		ls_files_r(char *full_name, t_all *all)
{
	DIR				*cur_dir;
	t_file			*cur_dir_lst;

	cur_dir = opendir(full_name);
	if (!cur_dir || full_name[ft_strlen(full_name) - 1] == '/')
		return (0);
	if (!all->first)
		printf("\n");
	all->first = 0;
	cur_dir_lst = ls_dir(cur_dir, full_name, all);
	while (cur_dir_lst)
	{
		if (ft_strcmp(cur_dir_lst->name, "..") &&
				ft_strcmp(cur_dir_lst->name, ".") && (all->flags['a'] ||
							!if_hidden(cur_dir_lst->name)))
				ls_files_r(ft_strjoin(ft_strjoin(full_name, "/"),
					cur_dir_lst->name), all);
		cur_dir_lst = cur_dir_lst->next;
		if (cur_dir_lst)
			del_dir(cur_dir_lst->prev);
	}
	return (1);
}
