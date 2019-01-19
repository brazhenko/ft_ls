/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_lst_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:05:12 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 13:09:22 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			files_lst_printer(t_file *node)
{
	while (node->previous)
	{
		node = node->previous;
	}
	while (node)
	{
		printf("PRINTER: %s\n", node->name);
		node = node->next;
	}
}
