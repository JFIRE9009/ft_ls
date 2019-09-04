/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:01:48 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/04 17:06:31 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LS_H
# define LIB_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>

# define BIT_ACTIVE(FLAGS, BIT) ((FLAGS >> BIT) & 1)
# define SET_BIT(FLAGS, BIT) (FLAGS |= (1 << BIT))
# define COMP(CHAR) ((CHAR < 97) ? (CHAR - 'A') : (CHAR - 'a'))

typedef struct		c_list {
	char			*data;
	struct c_list	*next;
}					l_path;

int					cDtO(int decimalNumber);
int					*octarr(int oct);
void				putperms(int mode);
void				putmodes(char *path);
void				indent_print(int indent);
l_path				*l_flag(DIR *dir, l_path *store, struct dirent *had);
void				R_flag(DIR *dir, struct dirent *had, int indent);
void				a_flag(DIR *dir, struct c_list loop, struct dirent *had);
void				no_flags(DIR *dir, struct c_list loop, struct dirent *had);
int					scan_options(int max, char **flags);

#endif
