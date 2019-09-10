/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:01:48 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/10 15:00:43 by jhouston         ###   ########.fr       */
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

typedef struct		s_link{
	char			*data;
	char			*buff;
	struct s_link	*next;
}					t_link;

int					scan_options(int max, char **flags);
int					conv_dec_to_oct(int decimalnumber);
int					*octarr(int oct);
void				putperms(int mode);
void				putmodes(char *path);
void				indent_print(int indent);
void				st_lst(t_link *lst, int (*cmp)(const char *, const char *));
void				r_st_lst(t_link *lst, int (*cmp)(const char *, const char *));
void				print_files(DIR *dir, t_link *store, struct dirent *entry, int flags);
void				rec_flag(DIR *dir, struct dirent *had, int indent);
void				no_flags(DIR *dir, t_link *store, struct dirent *entry);
void				a_flag_print(t_link *result, int flags);
void				l_flag_print(t_link *result, int flags);
void				no_flag_print(t_link *result);
void				add_empty_list(t_link *lst);
t_link				*arg_store(DIR *dir, t_link *store, struct dirent *entry);

#endif
