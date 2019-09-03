/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/03 17:14:26 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int		main(int argc, char **argv)
{
	struct dirent	*dir;
	struct mine		pole;
	DIR				*folder;
	int				flags;

	pole.data = NULL;
	dir = NULL;
	folder = opendir(".");
	flags = scan_options(argc, argv);
	if (argv[1] == NULL)
		no_flags(folder, pole, dir);
	if (BIT_ACTIVE(flags, ('a' - 'a')))
			a_flag(folder, pole, dir);
	else if (BIT_ACTIVE(flags, ('l' - 'a')))
			l_flag(folder, pole, dir);
	else if (BIT_ACTIVE(flags, ('R' - 'A')))
			R_flag(folder, pole, dir, 0);
	closedir(folder);
	return (0);
}
