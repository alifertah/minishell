/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:54:36 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/06 22:27:00 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*ptr;

	if (s1 && s2)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		i = -1;
		ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (ptr == NULL)
			return (NULL);
		while (s1[++i])
			ptr[i] = s1[i];
		i = 0;
		while (s2[i])
		{
			ptr[len1 + i] = s2[i];
			i++;
		}
		ptr[len1 + len2] = '\0';
		return (ptr);
	}
	return (NULL);
}