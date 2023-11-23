/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:42:11 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 11:31:11 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	unsigned char	a;

	a = 127;
	printf("%d\n", ft_isprint(a));
	printf("%d\n", isprint(a));
}*/
