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

int		main(int argc, char **argv)
{
	struct dirent	*sd;
	struct s_link	*store;
	DIR				*dir;
	int				flags;
	int 			i;

	store = NULL;
	sd = NULL;
	dir = NULL;
	i = 1;

	if (argc > 1)
	{
		while (argv[i] != NULL)
		{
			if (!(dir = opendir(argv[i])))
			{
				if (check_file_exists(argv[i]) == 0)
				{
					if (argv[i][0] != '-')
						no_file_error(argv[i]);
					dir = opendir(".");
				}
				else
				{
					flags = scan_options(argc, argv);
					if (BIT_ACTIVE(flags, COMP('l')))
						putmodes(argv[i]);
					ft_putendl(argv[i]);
					exit(1);
				}
			}
			else
				dir = opendir(argv[i]);
			i++;
		}
	}
	else
		dir = opendir(".");
	flags = scan_options(argc, argv);
	if (!BIT_ACTIVE(flags, COMP('R')))
		print_files(dir, store, sd, flags);
	else
		rec_flag(".", 0, flags);
	closedir(dir);
	return (0);
}
