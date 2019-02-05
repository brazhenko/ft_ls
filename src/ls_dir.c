/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:40:28 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/05 08:39:41 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*cut_time(char *str)
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

t_file			*config_compare(t_file *file_lst, t_all *all)
{
	if (all->flags['r'])
		return (merge_sort(file_lst, &comparator_r));
	else if (all->flags['f'])
		return (merge_sort(file_lst, &comparator_f));
	else if (all->flags['t'])
	{
		if (all->flags['u'])
			return (merge_sort(file_lst, &comparator_tu));
		else
			return (merge_sort(file_lst, &comparator_t));
	}
	else
		return (merge_sort(file_lst, &comparator_classic));
}

void			print_file(const t_all *all, t_file *file_lst)
{
	while (file_lst)
	{
		if (all->flags['a'] || (!all->flags['a'] && file_lst->name[0] != '.'))
		{
			if (all->flags['l'])
			{
				print_mode(file_lst->d_st.st_mode);
				printf_len_hu_num(file_lst->d_st.st_nlink, all->len_cs);
				if (!(all->flags['g']))
					prt_st(getpwuid(file_lst->d_st.st_uid)->pw_name, all->l_n);
				prt_st(getgrgid(file_lst->d_st.st_gid)->gr_name, all->len_gr);
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
		file_lst = file_lst->next;
	}
}

t_file			*ls_dir(DIR *cur_dir, char *full_name, t_all *all)
{
	struct dirent	*file;
	t_file			*file_lst;
	int				total;
	t_file			*cpy;

	total = 0;
	file_lst = NULL;
	all->len_cs = 0;
	all->l_n = 0;
	all->len_ves = 0;
	all->len_gr = 0;
	while ((file = readdir(cur_dir)))
		total += insert(&file_lst, file->d_name, full_name, all);
	if (all->flags['l'])
	{
		if (all->flags['R'])
			printf("\n%s\nTotal: %d\n", full_name, total);
		else
			printf("Total: %d\n", total);
	}
	file_lst = config_compare(file_lst, all);
	cpy = file_lst;
	print_file(all, file_lst);
	return (cpy);
}
