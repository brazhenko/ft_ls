/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/06 03:34:18 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define printf ft_printf

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

typedef struct		s_all
{
	char					*flags;
	int						len_cs;
	int						l_n;
	int						len_gr;
	int						len_ves;
	int						len_namef;
}					t_all;

typedef struct		s_file
{
	struct s_file	*next;
	struct s_file	*prev;

	char			*name;
	int				data;
	int				is_handled;
	DIR				*dir_struct;
	struct dirent	*dir_dirent;
	struct stat		d_st;
	int				blocks_a;
	int				blocks;
	int				is_exist;
}					t_file;

int					ls_files_r(char *name, t_all *all);
t_file				*ls_dir(DIR *cur_dir, char *name, t_all *all);
t_file				*t_file_new(struct dirent *file, char *name,
					char *full_name);
char				*parse_flags(int argc, char **argv, int *last_flag);
int					file_name_cmp(t_file *left, t_file *right);
void				add_to_lst(t_file **lst, t_file *node);
t_file				*to_list(struct dirent *file, char *name,
					char *full_name, t_file *list);
void				print_mode(int mode);
struct s_file		*merge_sort(struct s_file *head,
								int (*f)(t_file *, t_file *));
int					insert(struct s_file **head, char *name,
										char *full_name, t_all *all);
int					comparator_classic(t_file *left, t_file *right);
void				t_file_del(t_file *node);
t_file				*config_compare(t_file	*file_lst, t_all *all);
void				ls_only_file(t_file *file_lst, t_all *all);
void				printf_len_hu_num(unsigned short int num, int n);
void				prt_st(char *str, int n);
void				printf_len_llnum(long long int num, int n);
char				*cut_time(char *str);
void				printf_len_post_str(char *str, int n);
int					insert(struct s_file **head, char *name,
									char *full_name, t_all *all);
void				insert_file(t_all *all);
int					comparator_classic(t_file *left, t_file *right);
int					comparator_r(t_file *left, t_file *right);
int					comparator_tu(t_file *left, t_file *right);
int					comparator_t(t_file *left, t_file *right);
int					comparator_f(t_file *left, t_file *right);
void				prt_st(char *str, int n);
void				printf_len_post_str(char *str, int n);
void				printf_len_llnum(long long int num, int n);
void				printf_len_hu_num(unsigned short int num, int n);
void				insert_file(t_all *all);
void				insert_cmp(t_all *all, const struct s_file *temp);
int					insert(struct s_file **head, char *name,
								char *full_name, t_all *all);
t_file				*to_first(t_file *node);
void				arg_parse(t_file *args, t_all *all, t_file *args_cpy);
void				print_args(t_file *args, t_all *all, t_file *args_cpy);
t_file				*parse_args(int c, char *const *v,
							int last_flag, t_file *args);
void				cont_stat(t_file *file, t_all *all);
void				ls_error(char *file_name, int n);
void				ls_only_file(t_file *file_lst, t_all *all);

#endif
