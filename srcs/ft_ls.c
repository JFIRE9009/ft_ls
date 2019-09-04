/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/04 13:59:20 by jhouston         ###   ########.fr       */
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
	if (BIT_ACTIVE(flags, COMP('a')))
		a_flag(folder, pole, dir);
	else if (BIT_ACTIVE(flags, COMP('l')))
		l_flag(folder, pole, dir);
	else if (BIT_ACTIVE(flags, COMP('R')))
		R_flag(folder, pole, dir, 0);
	closedir(folder);
	return (0);
}
