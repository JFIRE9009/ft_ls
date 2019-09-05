/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:47 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/05 14:58:29 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int conv_dec_to_oct(int decimalnumber)
{
    int octalnumber;
	int	i;

	i = 1;
	octalnumber = 0;
    while (decimalnumber != 0)
    {
        octalnumber += (decimalnumber % 8) * i;
        decimalnumber /= 8;
        i *= 10;
    }
    return (octalnumber);
}

int	*octarr(int oct)
{
	int *retarr;
	int i;

	i = ft_intlen(conv_dec_to_oct(oct));
	retarr = (int *)malloc(sizeof(int) * i);
	while (oct >= 1)
	{
		retarr[i] = (oct % 10);
		i--;
		oct /= 10;
	}
	return (retarr);
}

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

void	add_empty_list(t_path *lst)
{
	t_path	*new;
	t_path	*tmp;

	new = (t_path *)malloc(sizeof(t_path));
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

void	st_lst(t_path *lst, int (*cmp)(const char *, const char *))
{
	char	*store;
	t_path	*tmp;

	tmp = lst;
	while (lst->next)
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
	lst->next = NULL;
	lst = tmp;
}

t_path	*arg_store(DIR *dir, t_path *store, struct dirent *entry)
{
	t_path	*temp;

	store = (t_path *)malloc(sizeof(t_path));
	temp = store;
	while ((entry = readdir(dir)) != NULL)
	{
		store->data = entry->d_name;
		store->next = (t_path *)malloc(sizeof(t_path));
		store = store->next;
	}
	store->next = NULL;
	store = temp;
	return (store);
}
