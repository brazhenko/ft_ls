/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:19:18 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 06:10:01 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file  *t_file_new(struct dirent *file, char *name, char *full_name)
{
    t_file *new;


    new = (t_file *)malloc(sizeof(t_file));
    new->name = name;
    new->prev = NULL;
    new->next = NULL;
    //printf("writing... %s   %s \n", full_name, name);
    stat(ft_strjoin(ft_strjoin(full_name, "/"), name), &new->dir_stat);
    new->dir_dirent = file;
    return (new);
}
