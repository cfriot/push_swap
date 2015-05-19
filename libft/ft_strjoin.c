/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:30:01 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/04 20:30:21 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = 0;
	dst = NULL;
	if (s1 && s2)
		dst = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (dst && s1 && s2)
	{
		while (s1[++i])
			dst[i] = s1[i];
		while (s2[j])
		{
			dst[i] = s2[j];
			i++;
			j++;
		}
		dst[i] = 0;
		return (dst);
	}
	return (0);
}
