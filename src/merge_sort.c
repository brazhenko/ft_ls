/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 09:04:13 by bbaelor-         ###   ########.fr       */
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
