/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:25:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 03:33:46 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_dir(t_file *cur_dir)
{
	if (!cur_dir)
		return ;
	if (cur_dir->next && cur_dir->next->prev)
		cur_dir->next->prev = NULL;
// if (cur_dir->dir_struct)
		// closedir(cur_dir->dir_struct);
	free(cur_dir);
}

int		ls_files_r(char *full_name, t_all *all)
{
	DIR				*cur_dir;
	t_file			*cur_dir_lst;

	cur_dir = opendir(full_name);
	if (!cur_dir)
		return (0);
	cur_dir_lst = ls_dir(cur_dir, full_name, all);
	while (cur_dir_lst)
	{
		if (ft_strcmp(cur_dir_lst->name, "..") && ft_strcmp(cur_dir_lst->name, "."))
		{
			ls_files_r(ft_strjoin(ft_strjoin(full_name, "/"), cur_dir_lst->name), all);
		}
		cur_dir_lst = cur_dir_lst->next;
		if (cur_dir_lst)
			del_dir(cur_dir_lst->prev);
	}
	return (1);
}
