/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:25:30 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/06 02:46:49 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				comparator_classic(t_file *left, t_file *right)
{
	if (ft_strcmp(left->name, right->name) < 0)
	{
		return (1);
	}
	else
		return (0);
}

int				comparator_r(t_file *left, t_file *right)
{
	if (ft_strcmp(left->name, right->name) > 0)
	{
		return (1);
	}
	else
		return (0);
}

int				comparator_tu(t_file *left, t_file *right)
{
	if (left->d_st.st_atimespec.tv_sec >
		right->d_st.st_atimespec.tv_sec)
		return (1);
	else
		return (0);
}

int				comparator_t(t_file *left, t_file *right)
{
	if (left->d_st.st_ctimespec.tv_sec >
		right->d_st.st_ctimespec.tv_sec)
		return (1);
	else
		return (0);
}

int				comparator_f(t_file *left, t_file *right)
{
	if (left && right)
		return (0);
	return (0);
}
