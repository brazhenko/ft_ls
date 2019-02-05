/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:03:56 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 09:04:35 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					insert_file(t_all *all)
{
	all->len_count_sym = 0;
	all->len_gr = 0;
	all->len_name = 0;
	all->len_namef = 0;
	all->len_ves = 0;
}

void					insert_cmp(t_all *all, const struct s_file *temp)
{
	if (all->len_count_sym < ft_strlen(ft_itoa(temp->dir_stat.st_nlink)))
		all->len_count_sym = ft_strlen(ft_itoa(temp->dir_stat.st_nlink));
	if (all->len_name < ft_strlen(getpwuid(temp->dir_stat.st_uid)->pw_name))
		all->len_name = ft_strlen(getpwuid(temp->dir_stat.st_uid)->pw_name);
	if (all->len_ves < ft_strlen(ft_itoa(temp->dir_stat.st_size)))
		all->len_ves = ft_strlen(ft_itoa(temp->dir_stat.st_size));
	if (all->len_gr < ft_strlen(getgrgid(temp->dir_stat.st_gid)->gr_name))
		all->len_gr = ft_strlen(getgrgid(temp->dir_stat.st_gid)->gr_name);
	if (all->len_namef < ft_strlen(temp->name))
		all->len_namef = ft_strlen(temp->name);
}

int						insert(struct s_file **head, char *name,
								char *full_name, t_all *all)
{
	int				total;
	struct s_file	*temp;

	temp = (struct s_file *)malloc(sizeof(struct s_file));
	temp->next = NULL;
	temp->prev = NULL;
	temp->name = name;
	stat(ft_strjoin(ft_strjoin(full_name, "/"), name), &temp->dir_stat);
	insert_cmp(all, temp);
	if (temp->name[0] == '.' && !all->flags['a'])
		total = 0;
	else
		total = temp->dir_stat.st_blocks;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
	return (total);
}
