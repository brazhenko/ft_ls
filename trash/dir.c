/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 07:08:18 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/29 07:12:24 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>

int main (int c, char *v[]) {
	int len;
	struct dirent *pDirent;
	DIR *pDir;

	if (c < 2)
	{
		printf ("./ft_ls [-l][-a][-R] file\n");
		return 1;
	}
	pDir = opendir (v[1]);
	if (pDir == NULL) {
		printf ("Cannot open directory '%s'\n", v[1]);
		return 1;
	}
	while ((pDirent = readdir(pDir)) != NULL) {
		printf ("%s\n", pDirent->d_name);
	 }
	closedir (pDir);
	return 0;
}
