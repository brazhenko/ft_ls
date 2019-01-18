/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/18 21:28:00 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*ls_dir(DIR *cur_dir)
{
	struct dirent	*file;
	t_file			*file_lst = NULL;

	while ((file = readdir(cur_dir)))
	{
		t_file *node = t_file_new(file->d_name);
		node->prev = file_lst;
		if (file_lst)
			file_lst->next = node;
		file_lst = node;
		printf("write.. %s\n", file->d_name);
		
	}



	return (NULL);	
}
