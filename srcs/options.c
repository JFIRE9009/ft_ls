/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/04 17:44:14 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

l_path	*l_flag(DIR *dir, l_path *store, struct dirent *had)
{
	l_path	*temp;

	store = (l_path *)malloc(sizeof(l_path));
	temp = store;
	while ((had = readdir(dir)) != NULL)
	{
		if (had->d_name[0] == '.')
			continue;
		store->data = had->d_name;
		store->next = (l_path *)malloc(sizeof(l_path));
		store = store->next;
	}
	store->next = NULL;
	store = temp;
	return (store);
}
/*
void R_flag(DIR *dir, struct dirent *entry, int indent)
{
	while ((entry = readdir(dir)) != NULL) 
	{
		if (entry->d_type == DT_DIR) 
		{
			if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
				continue;
			ft_putendl(entry->d_name);
			indent_print(indent);
            R_flag(dir, loop, entry, indent + 2);
		}
	   	else 
		{
			indent_print(indent);
			ft_putendl(entry->d_name);
		}
	}
	closedir(dir);
}

void	no_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
			ft_putendl(loop.data);
		no_flags(dir, loop, had);
	}
}

void	a_flag(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		ft_putendl(loop.data);
		a_flag(dir, loop, had);
	}
}*/

void	sort_list(l_path* lst, int (*cmp)(const char *, const char *))
{
	char	*store;
	l_path	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) > 0)
		{
			store = lst->data;
			lst->data = lst->next->data;
			lst->next->data = store;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
//	return (lst);
}

int	main(void)
{/*
	l_path	*test;
	l_path	*test1;
	l_path	*test2;
	l_path	*test3;
	l_path	*test4;
	l_path	*test5;

	test = (l_path *)malloc(sizeof(l_path));
	test1 = (l_path *)malloc(sizeof(l_path));
	test2 = (l_path *)malloc(sizeof(l_path));
	test3 = (l_path *)malloc(sizeof(l_path));
	test4 = (l_path *)malloc(sizeof(l_path));
	test5 = (l_path *)malloc(sizeof(l_path));

	test->data = "Ay";
	test->next = test1;
	test1->data = "Bee";
	test1->next = test2;
	test2->data = "Gee";
	test2->next = test3;
	test3->data = "Dee";
	test3->next = test4;
	test4->data = "Feff";
	test4->next = test5;
	test5->data = "Cee";
	test5->next = NULL;

	sort_list(test, ft_strcmp);

	while (test->next != NULL)
	{
		printf("%s", test->data);
		test = test->next;
	}
	*/
	struct dirent	*entry;
	l_path			*store;
	l_path			*result;
	DIR				*dir;

	dir = opendir(".");
	entry = NULL;
	store = NULL;
	result = l_flag(dir, store, entry);
	sort_list(result, ft_strcmp);
	while (result->next != NULL)
	{
		ft_putendl(result->data);
		result = result->next;
	}	
}
