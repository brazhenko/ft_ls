/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/22 16:38:04 by bbaelor-         ###   ########.fr       */
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
	//if (left->dir_stat.st_atimespec.tv_sec < right->dir_stat.st_atimespec.tv_sec)
	// if (left->data > right->data)
	if (ft_strcmp(left->name, right->name) > 0)
	{
		// sprintf("1");
		return (1);
	}
	else
		return (0);
}

void	printf_len_str(char *str, int n)
{
	int i;

	i = n - ft_strlen(str);
	while (i--)
		write(1, " ", 1);
	printf(" %s", str);
}

void	printf_len_num(long long int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i--)
		write(1, " ", 1);
	printf(" %lld", num);
}

void	printf_len_hu_num(unsigned short int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i--)
		write(1, " ", 1);
	printf(" %hu", num);
}

t_file			*ls_dir(DIR *cur_dir, char *full_name, t_all *all) {
	struct dirent	*file;
	t_file			*file_lst = NULL;
	int				total = 0;
	
	all->len_count_sym = 0;
	all->len_name = 0;
	while ((file = readdir(cur_dir)))
	{
		total += insert(&file_lst,file->d_name, full_name, all);
		// printf("write.. %s\n", file->d_name);
	}
	printf("Total: %d\n", total);
	file_lst = mergeSort(file_lst, &comparator);
	t_file *cpy = file_lst;
	while (file_lst)
	{
		print_mode(file_lst->dir_stat.st_mode);
		printf_len_hu_num(file_lst->dir_stat.st_nlink, all->len_count_sym);
		printf_len_str(getpwuid(file_lst->dir_stat.st_uid)->pw_name, all->len_name);
		printf(" %lld  %s %lld %s", file_lst->dir_stat.st_size, file_lst->name, file_lst->dir_stat.st_blocks, ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec));
		file_lst = file_lst->next;
	}
	return (cpy);
}
