/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:29:56 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 09:31:07 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*to_first(t_file *node)
{
	while (node && node->prev)
	{
		node = node->prev;
	}
	return (node);
}

void				arg_parse(t_file *args, t_all *all, t_file *args_cpy)
{
	args = config_compare(args_cpy, all);
	args = to_first(args);
	args_cpy = args;
	cont_stat(args_cpy, all);
	while (args)
	{
		if (!(S_ISDIR(args->d_st.st_mode)))
			ls_only_file(args, all);
		args = args->next;
	}
	while (args_cpy)
	{
		if (S_ISDIR(args_cpy->d_st.st_mode))
		{
			printf("\n%s:\n", args_cpy->name);
			ls_dir(opendir(args_cpy->name), args_cpy->name, all);
		}
		args_cpy = args_cpy->next;
	}
}

void				print_args(t_file *args, t_all *all, t_file *args_cpy)
{
	args = merge_sort(to_first(args), &comparator_classic);
	args_cpy = args;
	while (args)
	{
		if (!args->is_exist)
		{
			t_file_del(args);
			ls_error(args->name, 1);
		}
		args = args->next;
	}
	arg_parse(args, all, args_cpy);
}

t_file				*parse_args(int c, char *const *v,
							int last_flag, t_file *args)
{
	while (last_flag < c)
	{
		args = to_list(NULL, v[last_flag], ".", args);
		last_flag++;
	}
	return (args);
}
