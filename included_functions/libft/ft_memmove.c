/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:40:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/12 11:18:47 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*d;
	unsigned char	*s;

	d = (char *)dest;
	s = (unsigned char *)src;
	i = n;
	if (dest > src)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[100] = "JujutsuKaisen";
	char	b[100] = "JujutsuKeisenEpisode9";
	char	a1[100] = "JujutsuKaisen";
	char	b1[100] = "JujutsuKeisenEpisode9";

	ft_memmove(a+7, b+3, 28);
	printf("%s\n", a);
	memmove(a1+7, b1+3, 28);
	printf("%s\n", a1);
	return (0);
}*/
