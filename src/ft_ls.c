/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 07:09:37 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*to_first(t_file *node)
{
	while (node && node->prev)
	{
		node = node->prev;
	}
	return (node);
}

void				ls_error(char *file_name, int n)
{
	if (n == 1)
		printf("ft_ls: %s: No such file or directory\n", file_name);
}

void				ls_only_file(t_file *file_lst, t_all *all)
{
	if (!file_lst->is_exist)
		return ;
	if (all->flags['a'] || (!all->flags['a'] && file_lst->name[0] != '.'))
	{
		if (all->flags['l'])
		{
			print_mode(file_lst->dir_stat.st_mode);
			printf_len_hu_num(file_lst->dir_stat.st_nlink, all->len_count_sym);
			if (!(all->flags['g']))
				printf_len_str(getpwuid(file_lst->dir_stat.st_uid)->
												pw_name, all->len_name);
			printf_len_str(getgrgid(file_lst->dir_stat.st_gid)->
													gr_name, all->len_gr);
			printf_len_llnum(file_lst->dir_stat.st_size, all->len_ves);
			if (all->flags['u'])
				printf(" %s ", cut_time(ctime(&((file_lst->
							dir_stat).st_atimespec).tv_sec)));
			else
				printf(" %s ", cut_time(ctime(&((file_lst->
							dir_stat).st_ctimespec).tv_sec)));
			printf("%s\n", file_lst->name);
		}
		else
			printf_len_post_str(file_lst->name, all->len_namef);
	}
}

static void			print_flags(char *flags)
{
	int		i;

	i = 'a';
	while (i < 128)
	{
		if (flags[i])
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}

void				cont_stat(t_file *file, t_all *all)
{
	t_file *dump;

	insert_file(all);
	dump = file;
	while (file)
	{
		stat(file->name, &(file->dir_stat));
		if (all->len_count_sym < ft_strlen(ft_itoa(file->dir_stat.st_nlink)))
			all->len_count_sym = ft_strlen(ft_itoa(file->dir_stat.st_nlink));
		if (all->len_name < ft_strlen(getpwuid(file->dir_stat.st_uid)->pw_name))
			all->len_name = ft_strlen(getpwuid(file->dir_stat.st_uid)->pw_name);
		if (all->len_ves < ft_strlen(ft_itoa(file->dir_stat.st_size)))
			all->len_ves = ft_strlen(ft_itoa(file->dir_stat.st_size));
		if (all->len_gr < ft_strlen(getgrgid(file->dir_stat.st_gid)->gr_name))
			all->len_gr = ft_strlen(getgrgid(file->dir_stat.st_gid)->gr_name);
		if (all->len_namef < ft_strlen(file->name))
			all->len_namef = ft_strlen(file->name);
		file = file->next;
	}
	file = dump;
}

void arg_parse(t_file *args, t_all *all, t_file *args_cpy)
{
	args = config_compare(args_cpy, all);
	args = to_first(args);
	args_cpy = args;
	cont_stat(args_cpy, all);
	while (args)
		{
			if (!(S_ISDIR(args->dir_stat.st_mode)))
				ls_only_file(args, all);
			args = args->next;
		}
	while (args_cpy)
		{
			if (S_ISDIR(args_cpy->dir_stat.st_mode))
			{
				printf("\n%s:\n", args_cpy->name);
				ls_dir(opendir(args_cpy->name), args_cpy->name, all);
			}
			args_cpy = args_cpy->next;
		}
}

int					main(int c, char *v[])
{
	int				last_flag;
	char			*flags;
	t_file			*args;
	t_all			*all;
	t_file			*args_cpy;

	all = malloc(sizeof(t_all*));
	args = NULL;
	flags = parse_flags(c, v, &last_flag);
	all->flags = flags;
	if (c == last_flag + 1)
	{
		if (flags['R'])
			ls_files_r(".", all);
		else
			ls_dir(opendir("."), ".", all);
	}
	else
	{
		last_flag++;
		while (last_flag < c)
		{
			args = to_list(NULL, v[last_flag], ".", args);
			last_flag++;
		}
		args = merge_sort(to_first(args), &comparator_classic);
		args_cpy = args;
		while (args)
		{
			if (!args->is_exist)
			{
				t_file_del(args);
				ls_error(args->name, 1);
			}
			args = args->next;
		}
		arg_parse(args, all, args_cpy);
	}
	return (0);
}
