/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:26:10 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 17:38:56 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big != '\0' && i < len)
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
		{
			if (i + ft_strlen(little) > len)
				return (NULL);
			return ((char *)big);
		}
		i++;
		big++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    char    big[50] = "Jujutsu Kaisen Episode Kaisen 8";
    char    little[20] = "Kai";
    char 	*m;
    m = ft_strnstr(big, little, 11);
    if (m != NULL)
    	printf("%s\n", m);
    else if (m == NULL)
    	printf("null");
    return (0);
}*/
