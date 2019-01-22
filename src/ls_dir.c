/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/22 17:41:49 by bbaelor-         ###   ########.fr       */
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
	if (ft_strcmp(left->name, right->name) < 0)
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
		printf("%s", "-");
	printf(" %s", str);
}

void	printf_len_llnum(long long int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i--)
		printf("%s", " ");
	printf(" %lld", num);
}

void	printf_len_hu_num(unsigned short int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i--)
		printf("%s", " ");
	printf(" %hu", num);
}

// тут нет обработки ширины(((
char	*cut_time(char *str)
{
	int		i;
	int		j;
	char	*res;
	int		count;

	count = 0;
	res = (char *)malloc(sizeof(char) * 30);
	i = 0;
	j = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] && count != 2)
	{
		res[j] = str[i];
		if (str[i + 1] == ':')
			count++;
		i++;
		j++;
	}
	return (res);
}

t_file			*ls_dir(DIR *cur_dir, char *full_name, t_all *all) {
	struct dirent	*file;
	t_file			*file_lst = NULL;
	int				total = 0;
	
	all->len_count_sym = 0;
	all->len_name = 0;
	all->len_ves = 0;
	all->len_gr = 0;
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
		printf_len_str(getgrgid(file_lst->dir_stat.st_gid)->gr_name, all->len_gr);
		printf_len_llnum(file_lst->dir_stat.st_size, all->len_ves);
		printf(" %s %s\n", cut_time(ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec)), file_lst->name);
		//printf(" %s %lld %s", file_lst->name, file_lst->dir_stat.st_blocks, ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec));
		file_lst = file_lst->next;
	}
	return (cpy);
}
