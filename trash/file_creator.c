/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:13:00 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 13:04:13 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_file				*file_creator(char *name, int time)
{
	t_file				*F;
	struct stat			*temp;
	
	if ((F = (t_file *)malloc(sizeof(t_file))))
		printf("done!\n");
	F->name = name;
	F->is_dir = 0;
	F->next = NULL;
	F->previous = NULL;
	F->permissions = NULL;
	F->links = NULL;
	F->owner = NULL;
	F->year = NULL;
	F->size = 0;
	F->date = NULL;
	F->time_in_seconds = time;
	F->is_handled = 0;
	
	return (F);
}
