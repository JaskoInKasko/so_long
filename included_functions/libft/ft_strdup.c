/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:22:51 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/11 18:47:17 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*s1;

	i = 0;
	size = ft_strlen(s);
	if (s == 0)
		return (NULL);
	s1 = (char *)malloc((size + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (i < size)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[15] = "Jujutsu Kaisen";
	char	*m;
	m = ft_strdup(s);
	printf("%s\n", m);
	free(m);
	return (0);
}*/
