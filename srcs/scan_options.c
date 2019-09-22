/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:16 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/16 15:57:17 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int	scan_options(int max, char **flags)
{
	int i;
	int j;
	int check;

	i = 1;
	check = 0;
	while (i < max)
	{
		j = 0;
		if (flags[i][0] == '-')
		{
			if (flags[i][j + 1] != '\0')
				while (flags[i][j])
				{
					SET_BIT(check, COMP(flags[i][j]));
					j++;
				}
			else
			{
				ft_putendl("Invalid Flag Input '-'");
				return (-1);
			}
		}
		else
		{
			ft_putstr("ft_ls: "); 
			ft_putstr(flags[i]);
			ft_putendl(": No such file or directory");
			return (-1);
		}
		i++;
	}
	return (check);
}
/*
int	main(int argc, char **argv)
{
	int flags;

	ft_putnbr(flags = scan_options(argc, argv));
	ft_putchar('\n');
	if (argc > 1)
	{
		if (BIT_ACTIVE(-1, COMP('l')))
			ft_putendl("r is pressed");
		else
			ft_putendl("isbroken");
	}
	else
		ft_putendl("Invalid Input");
}*/
