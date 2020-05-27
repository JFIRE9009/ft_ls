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

void	print_files(DIR	*dir, t_link *store, struct dirent *entry, int flags)
{
	store = arg_store(dir, store, entry);
	st_lst(store);
	if (BIT_ACTIVE(flags, COMP('t')))
		t_st_lst(store);
	if (BIT_ACTIVE(flags, COMP('r')))
		r_st_lst(&store);
	l_flag_print(store, flags);
	// l_flag_print(NULL, store, flags);
}
