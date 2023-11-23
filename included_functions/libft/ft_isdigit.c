/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:42:11 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/04 18:14:08 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	unsigned char	a;

	a = '0';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", isdigit(a));
	return (0);
}*/	
