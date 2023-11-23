/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:34:58 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/17 13:57:08 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			d;
	unsigned char	e;
	unsigned char	*f;

	f = (unsigned char *)s;
	e = (unsigned char)c;
	d = 0;
	while (d < n)
	{
		while (d <= n - 1)
		{
			f[d] = e;
			d++;
		}
		d++;
	}
	return (s);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char a [9] = "ABCD EFGH";
    ft_memset(a, 120, 10);
    printf("%s\n", a);
    //memset(a, 120, 10);
    printf("%s\n", a);
    return (0);
}*/
