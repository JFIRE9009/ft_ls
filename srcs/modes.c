/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:09:13 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/13 18:10:22 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void	put_id(struct stat buff)
{
	register struct group	*group;
	register struct passwd	*pwd;

	pwd = getpwuid(buff.st_uid);
	group = getgrgid(buff.st_gid);
	ft_putstr_s(pwd->pw_name);
	ft_putstr_s(group->gr_name);
}

void	put_time(struct stat buff)
{
	char			*time;

	time = ctime(&buff.st_mtime) + 4;
	time[12] = '\0';
	ft_putstr_s(time);
}

void	putmodes(char *path)
{
	// register mode_t			mode;
	struct stat				buff;
	int						links;
	int						size;

	lstat(path, &buff);
	// mode = buff.st_mode;
	links = buff.st_nlink;
	size = buff.st_size;
	putperms(buff);
	ft_putnbr_t(links);
	put_id(buff);
	ft_putnbr_t(size);
	put_time(buff);
}

void putblocks(t_link *lst, int flags)
{
	t_link			*tmp;
	struct stat 	buff;
	int 			blocks;

	tmp = lst;
	blocks = 0;
	while(tmp->next != NULL)
	{
		if (tmp->data[0] == '.' && !BIT_ACTIVE(flags, COMP('a')))
		{
			tmp = tmp->next;
			continue ;
		}
		lstat(tmp->data, &buff);
		blocks = blocks + (buff.st_blocks / 2);
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putendl(" ");
}

void	putperms(struct stat fileperms)
{
	S_ISDIR(fileperms.st_mode) ? ft_putchar('d') : ft_putchar('-');
	fileperms.st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	fileperms.st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	fileperms.st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	fileperms.st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	fileperms.st_mode & S_IXOTH ? ft_putchar_s('x') : ft_putchar_s('-');
}
