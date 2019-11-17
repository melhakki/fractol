/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:43:17 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/19 23:20:37 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		maillon->content = (NULL);
		maillon->content_size = 0;
	}
	else
	{
		if (!(maillon->content = malloc(ft_strlen(content))))
		{
			free(maillon);
			return (NULL);
		}
		ft_memcpy(maillon->content, content, ft_strlen(content) + 1);
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
