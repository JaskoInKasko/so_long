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

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	unsigned char	a;

	a = 'S';
	printf("%d\n", ft_isascii(a));
	printf("%d\n", isascii(a));
}*/	
