/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:59:24 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/06 09:36:38 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_ls.h"

void	indent_print(int indent)
{
	int i;
	
	if (indent == 6)
		i = 1;
	else
		i = 0;
	while (indent > i)
	{
		ft_putstr(" ");
		i++;
	}
}

void	 R_flag(DIR *dir,  struct dirent *entry, int indent)
{
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (ft_strcmp(entry->d_name, ".") != 0 || ft_strcmp(entry->d_name, "..") != 0)
				continue ;
			ft_putendl(entry->d_name);
			indent_print(indent);
			R_flag(dir, entry, indent + 2);
		}
	   	else
		{
			indent_print(indent);
			ft_putchar('-');
			ft_putendl(entry->d_name);
		}
	}
	closedir(dir);
}

int		main(void)
{
	struct dirent	*folder;
	DIR				*dir;

	folder = NULL;
	dir = opendir(".");
	R_flag(dir, folder, 0);
}
