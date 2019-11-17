/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:41:46 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:55:44 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	s;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (i - 1 > j)
	{
		s = str[i - 1];
		str[i - 1] = str[j];
		str[j] = s;
		i--;
		j++;
	}
	return (str);
}