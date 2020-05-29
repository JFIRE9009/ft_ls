/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:47 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/14 10:08:41 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void	indent_print(int indent)
{
	int i;

	i = 0;
	while (indent >= i)
	{
		ft_putstr(" ");
		i++;
	}
}
 
void	free_list(t_link *list)
{
	t_link *traverse;

	while(list)
	{
		traverse = list;
		list = list->next;
		free(traverse);
	}
}

void	add_empty_list(t_link *lst)
{
	t_link	*new;
	t_link	*tmp;

	new = (t_link *)malloc(sizeof(t_link));
	new->data = NULL;
	new->next = NULL;
	tmp = lst;
	if (lst->next == NULL)
		lst->next = new;
	else
	{
		while (1 == 1)
		{
			if (tmp->next == NULL)
			{
				tmp->next = new;
				break;
			}
			tmp = tmp->next;
		}
		tmp->next = NULL;
	}
}

char    *path_join(char *str, char *str2)
{
    str = ft_strjoin(str, "/");
    return(ft_strjoin(str, str2));
}

int 	check_file_exists(char *filename)
{
	DIR 			*dir;
	struct dirent 	*entry;

	dir = opendir(".");
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_strcmp(filename, entry->d_name) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}