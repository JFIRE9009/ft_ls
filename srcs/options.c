/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:03 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/22 11:09:58 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void rec_flag(char *folder, int indent, int flags)
{
	DIR *dir;
	struct dirent *entry;
	char *path;

	if(!(dir = opendir(folder)))
		return ;
	while ((entry = readdir(dir)) != NULL) 
	{
		if (entry->d_type == DT_DIR) 
		{
            if (entry->d_name[0] == '.')
                continue;
			path = path_join(folder, entry->d_name);
			ft_putendl(ft_strjoin("./", entry->d_name));
			indent_print(indent);
            rec_flag(path, indent + 2, flags);
		}
	   	else 
		{
			indent_print(indent);
			ft_putendl(entry->d_name);
		}
	}
	closedir(dir);
}

void	l_flag_print(t_link *result, int flags)
{
	if (BIT_ACTIVE(flags, COMP('l')))
		putblocks(result, flags);
	while (result->next != NULL)
	{
		if (result->data[0] == '.' && !BIT_ACTIVE(flags, COMP('a')))
		{
			result = result->next;
			continue ;
		}
		if (BIT_ACTIVE(flags, COMP('l')))
			putmodes(result->data);
		ft_putendl(result->data);
		result = result->next;
	}
}
