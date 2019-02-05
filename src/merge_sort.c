/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 07:54:26 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft_ls.h"

struct s_file			*merge(struct s_file *first,
			struct s_file *second, int (*f)(t_file *, t_file *))
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (f(first, second))
	{
		first->next = merge(first->next, second, f);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else
	{
		second->next = merge(first, second->next, f);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}

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

void					swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

struct s_file			*split(struct s_file *head)
{
	struct s_file *fast;
	struct s_file *slow;
	struct s_file *temp;

	fast = head;
	slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	slow->next = NULL;
	return (temp);
}

struct s_file			*merge_sort(struct s_file *head,
							int (*f)(t_file *, t_file *))
{
	struct s_file *second;

	if (!head || !head->next)
		return (head);
	second = split(head);
	head = merge_sort(head, f);
	second = merge_sort(second, f);
	return (merge(head, second, f));
}
