/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:49:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/13 17:54:06 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void no_file_error(char *s)
{
    ft_putstr("ft_ls: cannot access '"); 
    ft_putstr(s);
    ft_putendl("' : No such file or directory");
    exit (-1);
}

void unrecognized_option_error(char c)
{
    ft_putstr("ft_ls: unrecognized option '");
    ft_putchar(c);
    ft_putendl("' \nAvailable options: '-a' '-l' '-r' '-R' '-t'");
    exit (-1);
}

DIR    *error_check(int max, char **args)
{
    DIR *dir;
    int i;
    
    i = 1;
    while (args[i] != NULL)
    {
        if (!(dir = opendir(args[i])))
        {
            if (check_file_exists(args[i]) == 0)
            {
                if (args[i][0] != '-')
                {
                    closedir(dir);
                    no_file_error(args[i]);
                }
                dir = opendir(".");
            }
            else
            {
                closedir(dir);
                print_option(max, args, i);
            }
        }
        else
        {
            closedir(dir);
            dir = opendir(args[i]);
        }
        i++;
    }
    return (dir);
}

void        print_option(int max, char **args, int index)
{
    int flags;

    flags = scan_options(max, args);
    if (BIT_ACTIVE(flags, COMP('l')))
        putmodes(args[index]);
    ft_putendl(args[index]);
    exit(1);
}