/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/05 06:23:10 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		comparator_classic(t_file *left, t_file *right)
{
	if (ft_strcmp(left->name, right->name) < 0)
	{
		// sprintf("1");
		return (1);
	}
	else
		return (0);
}

int		comparator_r(t_file *left, t_file *right)
{
	if (ft_strcmp(left->name, right->name) > 0)
	{
		return (1);
	}
	else
		return (0);
}

int		comparator_tu(t_file *left, t_file *right)
{
	if (left->dir_stat.st_atimespec.tv_sec > right->dir_stat.st_atimespec.tv_sec)
		return (1);
	else
		return (0);
}

int		comparator_t(t_file *left, t_file *right)
{
	if (left->dir_stat.st_ctimespec.tv_sec > right->dir_stat.st_ctimespec.tv_sec)
		return (1);
	else
		return (0);
}

int		comparator_f(t_file *left, t_file *right)
{
	return (0);
}

void	printf_len_str(char *str, int n)
{
	int i;

	i = n - ft_strlen(str);
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %s", str);
}

void	printf_len_post_str(char *str, int n)
{
	int i;

	i = n - ft_strlen(str);
	printf("%s ", str);
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
}

void	printf_len_llnum(long long int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %lld", num);
}

void	printf_len_hu_num(unsigned short int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %hu", num);
}

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

t_file			*config_compare(t_file	*file_lst, t_all *all)
{
	if (all->flags['r'])
		return mergeSort(file_lst, &comparator_r);
	else if (all->flags['f'])
		return mergeSort(file_lst, &comparator_f);
	else if (all->flags['t'])
	{
		if (all->flags['u'])
			return mergeSort(file_lst, &comparator_tu);
		else
			return mergeSort(file_lst, &comparator_t);
	}
	else
		return mergeSort(file_lst, &comparator_classic);
}

t_file			*ls_dir(DIR *cur_dir, char *full_name, t_all *all) 
{
	struct dirent	*file;
	t_file			*file_lst = NULL;
	int				total = 0;
	
	all->len_count_sym = 0;
	all->len_name = 0;
	all->len_ves = 0;
	all->len_gr = 0;
	while ((file = readdir(cur_dir)))
	{
		total += insert(&file_lst, file->d_name, full_name, all);
	}
	if (all->flags['l'])
	{
		if (all->flags['R'])
			printf("\n%s\nTotal: %d\n", full_name, total);
		else
			printf("Total: %d\n", total);
	}
	file_lst = config_compare(file_lst, all);
	t_file *cpy = file_lst;
	while (file_lst)
	{
		if (all->flags['a'] || (!all->flags['a'] && file_lst->name[0] != '.'))
		{
			if (all->flags['l'])
			{
				print_mode(file_lst->dir_stat.st_mode);
				printf_len_hu_num(file_lst->dir_stat.st_nlink, all->len_count_sym);
				if (!(all->flags['g']))
					printf_len_str(getpwuid(file_lst->dir_stat.st_uid)->pw_name, all->len_name);
				printf_len_str(getgrgid(file_lst->dir_stat.st_gid)->gr_name, all->len_gr);
				printf_len_llnum(file_lst->dir_stat.st_size, all->len_ves);
				if (all->flags['u'])
					printf(" %s ", cut_time(ctime(&((file_lst->dir_stat).st_atimespec).tv_sec)));
				else
					printf(" %s ", cut_time(ctime(&((file_lst->dir_stat).st_ctimespec).tv_sec)));
				printf("%s\n", file_lst->name);
			}
			else
				printf_len_post_str(file_lst->name, all->len_namef);
		}
		file_lst = file_lst->next;
	}
	return (cpy);
}
