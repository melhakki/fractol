/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:04:42 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/20 18:25:53 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elm))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next)
	{
		f(tmp);
		tmp = tmp->next;
	}
	f(tmp);
}
