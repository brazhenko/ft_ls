/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/06 02:48:48 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			print_mode(file_lst->d_st.st_mode);
			printf_len_hu_num(file_lst->d_st.st_nlink, all->len_cs);
			if (!(all->flags['g']))
				prt_st(getpwuid(file_lst->d_st.st_uid)->
						pw_name, all->l_n);
			prt_st(getgrgid(file_lst->d_st.st_gid)->
					gr_name, all->len_gr);
			printf_len_llnum(file_lst->d_st.st_size, all->len_ves);
			if (all->flags['u'])
				printf(" %s ", cut_time(ctime(&((file_lst->
							d_st).st_atimespec).tv_sec)));
			else
				printf(" %s ", cut_time(ctime(&((file_lst->
							d_st).st_ctimespec).tv_sec)));
			printf("%s\n", file_lst->name);
		}
		else
			printf_len_post_str(file_lst->name, all->len_namef);
	}
}

void				cont_stat(t_file *file, t_all *all)
{
	t_file *dump;

	insert_file(all);
	dump = file;
	while (file)
	{
		stat(file->name, &(file->d_st));
		if (all->len_cs < (int)ft_strlen(ft_itoa(file->d_st.st_nlink)))
			all->len_cs = (int)ft_strlen(ft_itoa(file->d_st.st_nlink));
		if (all->l_n < (int)ft_strlen(getpwuid(file->d_st.st_uid)->pw_name))
			all->l_n = (int)ft_strlen(getpwuid(file->d_st.st_uid)->pw_name);
		if (all->len_ves < (int)ft_strlen(ft_itoa(file->d_st.st_size)))
			all->len_ves = (int)ft_strlen(ft_itoa(file->d_st.st_size));
		if (all->len_gr < (int)ft_strlen(getgrgid(file->d_st.st_gid)->gr_name))
			all->len_gr = (int)ft_strlen(getgrgid(file->d_st.st_gid)->gr_name);
		if (all->len_namef < (int)ft_strlen(file->name))
			all->len_namef = (int)ft_strlen(file->name);
		file = file->next;
	}
	file = dump;
}

int					main(int c, char *v[])
{
	int				last_flag;
	char			*flags;
	t_file			*args;
	t_all			*all;
	t_file			*args_cpy;

	args_cpy = NULL;
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
		args = parse_args(c, v, last_flag, args);
		print_args(args, all, args_cpy);
	}
	return (0);
}
