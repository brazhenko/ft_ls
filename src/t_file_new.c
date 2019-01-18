/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:19:18 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/18 22:37:46 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file  *t_file_new(char *name, char *full_name)
{
    t_file *new;

    new = (t_file *)malloc(sizeof(t_file));
    new->name = name;
    new->prev = NULL;
    new->next = NULL;
    stat(full_name, new->dir_stat);

    return (new);
}