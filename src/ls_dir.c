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


//static void bin( int k )
//{
//	if (k >= 2)
//		bin(k / 2);
//	char n =  k % 2 + '0';
//	write(1, &n, 1);
//}

static int		name_comparator(t_file *left, t_file *right)
{
	if (ft_strcmp(left->name, right->name) > 0)
		return (1);
	return (0);
}

t_file			*ls_dir(DIR *cur_dir, char *full_name) {
	struct dirent *file;
	t_file *file_lst = NULL;

	printf("! %s\n", full_name);
	while ((file = readdir(cur_dir)))
	{
		file_lst = to_list(file, file->d_name, full_name, file_lst);
		//printf("write.. %s\n", file_lst->name);
	}
	while (file_lst && file_lst->prev)
	{
		file_lst = file_lst->prev;
	}
	mergeSort(file_lst, &name_comparator);
	while (file_lst)
	{
		// printf("   ");
		print_mode(file_lst->dir_stat.st_mode);
		// bin(file_lst->dir_stat.st_mode);
		printf(" %hu %s %lld  %s  %s", file_lst->dir_stat.st_nlink, getpwuid(file_lst->dir_stat.st_uid)->pw_name,
			   file_lst->dir_stat.st_size, file_lst->name, ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec));
		if (!file_lst->prev)
			return (file_lst);
		file_lst = file_lst->prev;
	}
	printf("\n\n");
	return (file_lst);
}
