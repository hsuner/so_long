/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:50:50 by hsuner            #+#    #+#             */
/*   Updated: 2023/12/06 17:50:52 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize != 0)
	{
		while (src[++i] && i < dstsize - 1)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
