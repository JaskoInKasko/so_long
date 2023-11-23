/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:34:58 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 11:38:47 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			c;
	char			d;
	char			*e;

	e = (char *)s;
	d = '\0';
	c = 0;
	while (c < n)
	{
		while (c <= n - 1)
		{
			e[c] = d;
			c++;
		}
		c++;
	}
}
/*#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	a[] = "ABCD EFGH";
	int	b;
	printf("%s\n", a);
	bzero(a, 4);
	//ft_bzero(a, 4);
	b = 0;
	while(b < 6)
	{
		printf("%d ", a[b]);
		b++;
	}
	printf("\n");
	return (0);
}*/
