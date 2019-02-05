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
	all->len_cs = 0;
	all->len_gr = 0;
	all->l_n = 0;
	all->len_namef = 0;
	all->len_ves = 0;
}

void					insert_cmp(t_all *all, const struct s_file *temp)
{
	if (all->len_cs < ft_strlen(ft_itoa(temp->d_st.st_nlink)))
		all->len_cs = ft_strlen(ft_itoa(temp->d_st.st_nlink));
	if (all->l_n < ft_strlen(getpwuid(temp->d_st.st_uid)->pw_name))
		all->l_n = ft_strlen(getpwuid(temp->d_st.st_uid)->pw_name);
	if (all->len_ves < ft_strlen(ft_itoa(temp->d_st.st_size)))
		all->len_ves = ft_strlen(ft_itoa(temp->d_st.st_size));
	if (all->len_gr < ft_strlen(getgrgid(temp->d_st.st_gid)->gr_name))
		all->len_gr = ft_strlen(getgrgid(temp->d_st.st_gid)->gr_name);
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
	stat(ft_strjoin(ft_strjoin(full_name, "/"), name), &temp->d_st);
	insert_cmp(all, temp);
	if (temp->name[0] == '.' && !all->flags['a'])
		total = 0;
	else
		total = temp->d_st.st_blocks;
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
