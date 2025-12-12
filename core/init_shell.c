/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:28 by acollon           #+#    #+#             */
/*   Updated: 2025/12/07 15:31:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env   *init_shell(char **envp)
{
        t_env   *env;

        env = init_env(envp);
        if (!env)
                ft_putendl_fd("minishell: failed to initialize environment", STDERR_FILENO);
        return (env);
}
