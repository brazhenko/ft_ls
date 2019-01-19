/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:10:44 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 17:54:04 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				insert_to_lst(t_file **files, t_file *file)
{
	file->previous = (*files);
	file->next = (*files)->next;
	(*files)->next->previous = file;
	(*files)->next = file;
}
