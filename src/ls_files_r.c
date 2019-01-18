/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files_R.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:25:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/18 21:59:39 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_files_r(char *name)
{
	DIR				*cur_dir;
	t_file			*cur_dir_lst;

// 	printf("%s\n", ft_strjoin(ft_strjoin(name, "/"), );
	cur_dir = opendir(name);
	if (!cur_dir)
		return (0);
	cur_dir_lst = ls_dir(cur_dir);
	while (cur_dir_lst)
	{
		// if (cur_dir_lst->dir_dirent->d_type == 4 && cur_dir_lst->dir_dirent->d_name[0] != '.')
		if (cur_dir_lst->name[0] != '.')
		{
			ls_files_r(ft_strjoin(ft_strjoin(name, "/"), cur_dir_lst->name));
		}
		cur_dir_lst = cur_dir_lst->prev;
	}

	return (1);
}
