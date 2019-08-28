/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:04:35 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/15 13:37:24 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list		*newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		if (!(newlst->content = malloc(size)))
			return (NULL);
		ft_memcpy(newlst->content, content, size);
		newlst->content_size = size;
	}
	newlst->next = NULL;
	return (newlst);
}
