/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:41:35 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/03 20:13:26 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **ft_split(char *str, char c)
{
    int x = -1;
    char **new;
    new = malloc(sizeof(char *) * 100);
    int i = 0;
    int j = 0;

    while(str[i])
    {
        if(str[i] && str[i] != c)
        {
            x++;
            j = 0;
            new[x] = malloc(sizeof(char) * 100);
            while(str[i] && str[i] != c)
            {
                new[x][j] = str[i];
                j++;
                i++;
            }
            new[x][j] = '\0';
        }
        i++;
    }
    new[x] = NULL;
    return(new);
}