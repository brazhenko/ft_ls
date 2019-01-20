/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/19 06:09:50 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*to_list(struct dirent *file, char *name, char *full_name, t_file *list)
{


	while (list && list->next)
		list = list->next;
	t_file *node = t_file_new(file, name, full_name);
	node->prev = list;
	if (list)
		list->next = node;
	return (node);
}

t_file			*ls_dir(DIR *cur_dir, char *full_name)
{
	struct dirent	*file;
	t_file			*file_lst = NULL;
	
	printf("! %s\n", full_name);
	while ((file = readdir(cur_dir)))
	{
		file_lst = to_list(file, file->d_name, full_name, file_lst);
		
		//printf("write.. %s\n", file_lst->name);
	}
	while (file_lst)
	{
		printf("%s        %s", file_lst->name , ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec));
		// ft_putendl(file_lst->name);
		if (!file_lst->prev)
			return (file_lst);
		file_lst = file_lst->prev;
	}
	printf("\n\n");
	return (file_lst);	
}
