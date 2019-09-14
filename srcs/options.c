/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:03 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/14 10:16:44 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void rec_flag(DIR *dir, struct dirent *entry, int indent)
{
	while ((entry = readdir(dir)) != NULL) 
	{
		if (entry->d_type == DT_DIR) 
		{
			if (ft_strcmp(entry->d_name, ".") == 0 ||\
				   	ft_strcmp(entry->d_name, "..") == 0)
				continue;
			ft_putendl(entry->d_name);
			indent_print(indent);
            rec_flag(dir, entry, indent + 2);
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
