/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:21:37 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 16:26:43 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_export(char **cmd)
{
    int j;
    
    j = 0;
    while(envp[j])
        j++;
    if(cmd[2])
    {
        envp[j] = ft_strdup(cmd[2]);
        j++;
        envp[j] = NULL; 
    }
    for(int i = 0; envp[i]; i++)
        printf("%s\n", envp[i]);
}