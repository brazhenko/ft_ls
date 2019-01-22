/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 06:09:42 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <fcntl.h>

typedef struct				s_file
{
	struct s_file	*next;
	struct s_file	*prev;

	char			*name;
	int 			data;
	int				is_handled;
	DIR				*dir_struct;
	struct dirent	*dir_dirent;
	struct stat		dir_stat;
}							t_file;



int					ls_files_r(char *name);
t_file				*ls_dir(DIR *cur_dir, char *name);
t_file              *t_file_new(struct dirent *file, char *name, \
                                                    char *full_name);
// int					parser(int argc, char **argv, t_flags *flags);
char				*parse_flags(int argc, char **argv, int *last_flag);
int					file_name_cmp(t_file *left, t_file *right);
void				add_to_lst(t_file **lst, t_file *node);
t_file				*to_list(struct dirent *file, char *name, \
                                        char *full_name, t_file *list);
void 				print_mode(int mode);
struct				s_file *mergeSort(struct s_file *head, int (*f)(t_file *, t_file *));

#endif
