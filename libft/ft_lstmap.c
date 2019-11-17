/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:45:07 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/20 18:24:42 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *alst;
	t_list *head;

	if (!lst)
		return (NULL);
	alst = f(lst);
	head = alst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(alst->next = f(lst)))
		{
			free(alst->next);
			return (NULL);
		}
		alst = alst->next;
	}
	return (head);
}
