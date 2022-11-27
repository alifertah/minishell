/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:41:26 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/27 19:08:54 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*output;
	int		i;

	if (!str)
		str = ft_strdup("");
	i = 0;
	output = malloc(ft_strlen(str) + 2);
	if (!output)
		return (NULL);
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i++] = c;
	output[i] = '\0';
	free(str);
	str = NULL;
	return (output);
}
