/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_ls3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 06:26:52 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/14 10:17:34 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_ls.h"

t_link	*add_at_head(char *file)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	new->data = file;
	new->next = NULL;
	return (new);
}

void	add_at_end(char *file, t_link *head)
{
	t_link	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = (t_link *)malloc(sizeof(t_link));
	temp->next->data = ft_strdup(file);
	temp->next->next = NULL;
}

t_link	*list_alloc(char *file, t_link *head)
{
	t_link	*temp;

	temp = head;
	if (head == NULL)
	{
		head = add_at_head(file);
		temp = head;
	}
	else
	{
		add_at_end(file, temp);
		head = temp;
	}
	return (head);
}

void	print_list(t_link *lst)
{
	t_link	*temp;

	temp = lst;
	while (lst->next != NULL)
	{
		ft_putendl(lst->data);
		lst = lst->next;
	}
	lst = temp;
}

void	R_flag_store(char *name, struct dirent *entry)
{
	struct stat	buff;
	DIR			*dir;
	t_link		*s_file;
	t_link		*s_dir;
	t_link		*temp_store;

	temp_store = (t_link *)malloc(sizeof(t_link));
	if(!(dir = opendir(name)))
		return ;
	s_file = NULL;
	s_dir = NULL;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue ;
		temp_store->data = ft_strjoin(name, "/");
		temp_store->data = ft_strjoin(temp_store->data, entry->d_name);
		s_dir = list_alloc(temp_store->data, s_dir);
		s_file = list_alloc(entry->d_name, s_file);
	}
	st_lst(s_file);
	st_lst(s_dir);
	print_list(s_file);
	closedir(dir);
	while (s_dir != NULL)
	{
		stat(s_dir->data, &buff);
		if (S_ISDIR(buff.st_mode))
		{
			ft_putchar('\n');
			ft_putstr(s_dir->data);
			ft_putendl(":");
			R_flag_store(s_dir->data, entry);
		}
		s_dir = s_dir->next;
	}
}
/*
int	main(void)
{
	//struct s_link	*store;
	char			*name;
	struct dirent	*folder;

	name = ".";
	folder = NULL;
	R_flag_store(name, folder);
}*/
