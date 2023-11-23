/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:33:49 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 11:48:58 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	s[15] = "Jujutsu Kaisen";
	char	c;
	char	*m;
	
	c = 't';
	m = ft_memchr(s, c, 5);
	printf("%s\n%s\n", s, m);
}*/
