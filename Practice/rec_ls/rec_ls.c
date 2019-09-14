/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:59:24 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/12 06:35:09 by jhouston         ###   ########.fr       */
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

void	 R_flag(DIR *dir, char *name,  struct dirent *entry, int indent)
{
	t_link	*store;

	store = (t_link *)malloc(sizeof(t_link));
	if(!(dir = opendir(name)))
		return ;
	store->data = name;
	store->data = ft_strjoin(name, "/");
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue ;
		if (entry->d_type == DT_DIR)
		{
			store->buff = ft_strnew(1024);
			if (ft_strcmp(entry->d_name, ".") == 0 && ft_strcmp(entry->d_name, "..") == 0)
				continue ;
			store->buff = ft_strjoin(store->data, entry->d_name);
			ft_putstr("\n./");
			ft_putstr(entry->d_name);
			ft_putstr(":\n");
			R_flag(dir, store->buff, entry, indent + 2);
		}
	   	else
		{
//			indent_print(indent);
			ft_putchar('-');
			ft_putendl(entry->d_name);
		}
	}
	closedir(dir);
}

t_link	*R_flag_store(DIR *dir, char *name, struct dirent *entry)
{
	t_link	*temp;
	t_link	*store;

	store  = (t_link *)malloc(sizeof(t_link));
	if(!(dir = opendir(name)))
		return (NULL);
	temp = store;
	store->data = name;
	store->data = ft_strjoin(name, "/");
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue ;
		if (entry->d_type == DT_DIR)
		{
			store->buff = ft_strnew(1024);
			if (ft_strcmp(entry->d_name, ".") == 0 && ft_strcmp(entry->d_name, "..") == 0)
				continue ;
			store->buff = ft_strjoin(store->data, entry->d_name);	
			store->buff = ft_strjoin(store->buff, "\n./");
			store->data = entry->d_name;
			store->buff = ft_strjoin(store->buff, ":\n");
			store->next = (t_link *)malloc(sizeof(t_link));
			store = store->next;
			R_flag_store(dir, store->data, entry);
		}
	   	else
		{
//			ft_putendl(entry->d_name);
			store->data = entry->d_name;
			store->next = (t_link *)malloc(sizeof(t_link));
			store = store->next;
		}
	}
	closedir(dir);
	store->next = NULL;
	store = temp;
	return (store);

}

int		main(void)
{
//	struct s_link	*store;
	char			*name;
	struct dirent	*folder;
	DIR				*dir;

	name = ".";
	folder = NULL;
	dir = NULL;
	R_flag(dir, name, folder, 0);
//	store = R_flag_store(dir, name, folder);

//	while (store->next != NULL)
//	{
//		ft_putendl(store->buff);
//		ft_putendl(store->data);
//		store = store->next;
//	}
}
