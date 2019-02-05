SRC			= src
INCLUDE 	= inc

all:
	@gcc -g -Werror -pedantic \
			$(SRC)/ft_ls.c \
			$(SRC)/ls_files_r.c \
			$(SRC)/t_file_new.c \
			$(SRC)/ls_dir.c \
			$(SRC)/parse_flags.c \
			$(SRC)/to_list.c \
			$(SRC)/print_mode.c \
			$(SRC)/merge_sort.c \
			$(SRC)/comparators.c \
			$(SRC)/printfc.c \
			$(SRC)/inserts.c \
			$(SRC)/handle_argv.c \
			libft.a \
			printf/libftprintf.a \
			-I $(INCLUDE) \
			-o ft_ls
	@echo COMPILED!

clean:
	@rm -f ft_ls

fclean: clean

re: fclean all
