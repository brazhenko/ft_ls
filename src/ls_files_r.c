/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:25:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 04:51:23 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_files_r(char *full_name)
{
	DIR				*cur_dir;
	t_file			*cur_dir_lst;

	cur_dir = opendir(full_name);
	if (!cur_dir)
		return (0);
	cur_dir_lst = ls_dir(cur_dir, full_name);
	while (cur_dir_lst)
	{
		// if (cur_dir_lst->dir_dirent->d_type == 4 && cur_dir_lst->dir_dirent->d_name[0] != '.')
		if (ft_strcmp(cur_dir_lst->name, "..") && ft_strcmp(cur_dir_lst->name, "."))
		{
			ls_files_r(ft_strjoin(ft_strjoin(full_name, "/"), cur_dir_lst->name));
		}
		cur_dir_lst = cur_dir_lst->next;
	}
	return (1);
}
