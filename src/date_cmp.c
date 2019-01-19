/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 04:08:09 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/29 04:19:24 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				date_cmp(t_file *first, t_file *second)
{
	if (!first)
		return (1);
	return(first->time_in_seconds - second->time_in_seconds);
}
