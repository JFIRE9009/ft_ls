/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 06:35:52 by jhouston          #+#    #+#             */
/*   Updated: 2019/08/27 07:34:35 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void indent_print(int indent)
{
	int i;

	i = 0;
	while (indent >= i)
	{
		ft_putstr(" ");
		i++;
	}
}

void listdir(const char *name, int indent)
{
	int i;
	DIR *dir;
	struct dirent *entry;

	if (!(dir = opendir(name)))
		return ;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			char *path;
			i = 0;
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			path = entry->d_name;
//			ft_putstr(name);
//			ft_putstr(entry->d_name);
//			snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
			indent_print(indent);
			ft_putendl(entry->d_name);
//			printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(path, indent + 2);
		} else {
			printf("%*s%s\t", indent, "", entry->d_name);
		}
	}
	closedir(dir);
}

int main(void) {
	listdir(".", 0);
	return 0;
}
