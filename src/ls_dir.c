/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/22 13:15:05 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



//static int		name_comparator(t_file *left, t_file *right)
//{
//	if (ft_strcmp(left->name, right->name) < 0)
//	{
//		// printf("1");
//		return (1);
//	}
//	// printf("0");
//	return (0);
//}

int		comparator(t_file *left, t_file *right)
{
	// if (left->dir_stat.st_ctimespec.tv_sec < right->dir_stat.st_ctimespec.tv_sec)
	// if (left->data > right->data)
	if (ft_strcmp(left->name, right->name) < 0)
	{
		// sprintf("1");
		return (1);
	}
	else
		return (0);
}



t_file			*ls_dir(DIR *cur_dir, char *full_name) {
	struct dirent *file;
	t_file *file_lst = NULL;

	printf("\n%s\n\n", full_name);
	while ((file = readdir(cur_dir)))
	{
		insert(&file_lst,5 ,file->d_name, full_name);
		// printf("write.. %s\n", file->d_name);
	}

	file_lst = mergeSort(file_lst, &comparator);
	t_file *cpy = file_lst;
	while (file_lst)
	{
		print_mode(file_lst->dir_stat.st_mode);
		printf(" %hu %s %lld  %s %lld %s ", file_lst->dir_stat.st_nlink, getpwuid(file_lst->dir_stat.st_uid)->pw_name,
			   file_lst->dir_stat.st_size, file_lst->name, file_lst->dir_stat.st_blocks, ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec));
		file_lst = file_lst->next;
	}
	return (cpy);
}
