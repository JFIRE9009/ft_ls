/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:02:15 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/06 17:04:49 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_ls.h"

void	print_files(DIR	*dir, t_path *store, struct dirent *entry, int flags)
{
	store = arg_store(dir, store, entry);
	add_empty_list(store);
	if (BIT_ACTIVE(flags, COMP('r')))
		r_st_lst(store, ft_strcmp);
	else
		st_lst(store, ft_strcmp);
	if (flags == 100 || BIT_ACTIVE(flags, COMP('r')))
		no_flag_print(store);
	else if (BIT_ACTIVE(flags, COMP('l')))
		l_flag_print(store);
	else if (BIT_ACTIVE(flags, COMP('a')))
		a_flag_print(store);
}
