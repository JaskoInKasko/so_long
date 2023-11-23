/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:40:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 11:40:17 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*c;
	char			*d;
	unsigned int	e;

	if (dest == NULL && src == NULL)
		return (NULL);
	c = (char *)dest;
	d = (char *)src;
	e = 0;
	while (e < n)
	{
		c[e] = d[e];
		e++;
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[100] = "JujutsuKaisen";
	const char	b[100] = "JujutsuKeisenEpisode9";
	char	a1[100] = "JujutsuKaisen";
	const char	b1[100] = "JujutsuKeisenEpisode9";

	ft_memcpy(a+7, b+3, 58);
	puts(a);
	memcpy(a1+7, b1+3, 28);
	puts(a1);
	return (0);
}*/
