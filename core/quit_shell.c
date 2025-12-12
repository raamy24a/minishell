/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:45 by acollon           #+#    #+#             */
/*   Updated: 2025/12/07 15:31:45 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    quit_shell(int exit_status, t_env *env)
{
        if (env)
                free_env(&env);
        rl_clear_history();
        exit(exit_status);
}
