/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:01:48 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/16 15:57:48 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LS_H
# define LIB_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>

# define BIT_ACTIVE(FLAGS, BIT) ((FLAGS >> BIT) & 1)
# define SET_BIT(FLAGS, BIT) (FLAGS |= (1 << BIT))
# define COMP(CHAR) ((CHAR < 97) ? (CHAR - 'P') : (CHAR - 'a'))

typedef struct		s_link{
	char			*data;
	struct s_link	*next;
}					t_link;

char				*path_join(char *str, char *str2);
int					scan_options(int max, char **flags);
int					sort_time(char *file, char *file2);
int				 	check_file_exists(char *filename);
void				error_check(int max, char **flags);
void				putperms(struct stat fileperms);
void				putblocks(t_link *lst, int flags);
void				putmodes(char *path);
void				indent_print(int indent);
void				st_lst(t_link *lst);
void				r_st_lst(t_link **lst);
void				t_st_lst(t_link *lst);
void				print_files(DIR *dir, t_link *store, struct dirent *entry, int flags);
void				rec_flag(char *folder, int indent, int flags);
void				no_flags(DIR *dir, t_link *store, struct dirent *entry);
void				a_flag_print(t_link *result, int flags);
// void				l_flag_print(char *path, t_link *result, int flags);
void				l_flag_print(t_link *result, int flags);
void				no_flag_print(t_link *result);
void				add_empty_list(t_link *lst);
t_link				*arg_store(DIR *dir, t_link *store, struct dirent *entry);
void				add_at_end(char *path, t_link *store);
void				no_file_error(char *s);
void				unrecognized_option_error(char c);

#endif
