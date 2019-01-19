#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>

static char				get_last_char(const char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (len > 0)
	{
		return (str[len - 1]);
	}
	return (*str);
}

static char				*normalize_path(const char *path) //TODO: протестировать, добавить нормализацию начала пути.
{
	if (get_last_char(path) != '/')
	{
		return (ft_strjoin(path, "/"));
	}
	return (ft_strdup(path));
}

static char				*path_join(const char *basedir, const char *file)
{
	char *full_path;
	char *normed_basedir;

	normed_basedir = normalize_path(basedir);
	full_path = ft_strjoin(basedir, file);
	free(normed_basedir);
	return (full_path);
}

static void				print_file_info(const char *path, const char *filename)
{
	struct stat a;
	char *full_path;

	printf("%s\n", filename);
	full_path = path_join(path, filename);
	if (full_path)
	{
		if (!stat(full_path, &a))
		{
			printf("Size of the file is: \t\t%ld\n", a.st_size);
			printf("Time of the file is: \t\t%ld\n", a.st_ctime);
			printf("                     \t\t%s\n", 
					ctime(&a.st_ctime)
			);
			printf("Link count of the file is:\t%ld\n", a.st_nlink);
		}
		else
			printf("ERROR in call `stat(2)` to %s\n", full_path);
		printf("---------\n");
		free(full_path);
	}
}

int						ls_readdir(const char *path)
{
	struct dirent *dir_piece;
	DIR *dir_instance;

	dir_instance = opendir(path);
	if (!dir_instance)
		return (0);
	while ((dir_piece = readdir(dir_instance)) != NULL)
		print_file_info(path, dir_piece->d_name);
	closedir(dir_instance);
	return (1);
}
