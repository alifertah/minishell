/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:57:51 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/16 22:57:14 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*one_character(char c)
{
	char	*return_val;

	return_val = (char *) malloc(2 * sizeof(char));
	if (!return_val)
		return (NULL);
	return_val[0] = c;
	return_val[1] = 0;
	return (return_val);
}

char	*ft_charjoin(char *s1, char c)
{
	unsigned int	i;
	char			*return_val;

	if (!s1)
		return (one_character(c));
	i = 0;
	return_val = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!return_val)
		return (NULL);
	while (s1[i])
	{
		return_val[i] = s1[i];
		i++;
	}
	return_val[i++] = c;
	return_val[i] = '\0';
	free(s1);
	s1 = NULL;
	return (return_val);
}
