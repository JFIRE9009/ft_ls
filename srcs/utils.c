/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:47 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/10 16:20:10 by jhouston         ###   ########.fr       */
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

void	r_st_lst(t_link *lst, int (*cmp)(const char *, const char *))
{
	char	*store;
	t_link	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->next->data, lst->data)) > 0)
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

void	st_lst(t_link *lst, int (*cmp)(const char *, const char *))
{
	char	*store;
	t_link	*tmp;

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

t_link	*arg_store(DIR *dir, t_link *store, struct dirent *entry)
{
	t_link	*temp;

	store = (t_link *)malloc(sizeof(t_link));
	temp = store;
	while ((entry = readdir(dir)) != NULL)
	{
		store->data = entry->d_name;
		store->next = (t_link *)malloc(sizeof(t_link));
		store = store->next;
	}
	store->next = NULL;
	store = temp;
	return (store);
}
