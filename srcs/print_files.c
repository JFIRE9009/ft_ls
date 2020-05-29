/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:02:15 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/16 15:44:44 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_ls.h"

size_t  array_length(char **array)
{
    size_t size;

    size = 0;
    while (array[size] != NULL)
        size++;
    return (size);
}

void    free_array(char **array)
{
    size_t count;

    count = 0;
    while (array[count])
    {
        free(array[count]);
        count++;
    }
    free(array);
}

char    **push_string(char **target, char *str)
{
    char    **array;
    size_t  count;

    if (target == NULL)
    {
        array = (char **)malloc(sizeof(char *) * 2);
        array[0] = ft_strdup(str);
        array[1] = NULL;        
    }
    else
    {
        count = 0;
        array = (char **)malloc(sizeof(char *) * (array_length(target) + 2));
        while (target[count])
        {
            array[count] = ft_strdup(target[count]);
            count++;
        }
        array[count++] = ft_strdup(str);
        array[count] = NULL;
        free_array(target);
    }
    return (array);
}

void    print_reverse(t_link *head, int flags)
{
    t_link *trav;
    char **toprint;
    int end;

    toprint = NULL;
    trav = head;
    while (trav->next)
    {
        toprint = push_string(toprint, trav->data);
        trav = trav->next;
    }
    end = array_length(toprint) - 1;
    while (end > -1)
    {
		if (toprint[end][0] == '.' && !BIT_ACTIVE(flags, COMP('a')))
		{
			end--;
			continue ;
		}
		if (BIT_ACTIVE(flags, COMP('l')))
			putmodes(toprint[end]);
		ft_putendl(toprint[end]);
        end--;
    }
    free_array(toprint);
}

void	print_files(DIR	*dir, t_link *store, struct dirent *entry, int flags)
{
	store = arg_store(dir, store, entry);
	st_lst(store);
	if (BIT_ACTIVE(flags, COMP('t')))
		t_st_lst(store);
	if (BIT_ACTIVE(flags, COMP('r')))
		print_reverse(store, flags);
	if (!BIT_ACTIVE(flags, COMP('r')))
		l_flag_print(store, flags);
	free_list(store);
}
