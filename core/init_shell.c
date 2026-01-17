/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:28 by acollon           #+#    #+#             */
/*   Updated: 2026/01/17 05:20:14 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_shell(char **envp)
{
	t_env	*env;
	char	**command;
	char	*nbr;

	env = init_env(envp, 0);
	command = malloc (sizeof (char *) * 3);
	if (!command)
		return (env);
	if (!env)
		ft_putendl_fd("minishell: failed to initialize environment",
			STDERR_FILENO);
	command[0] = ft_strdup("export");
	nbr = ft_itoa (ft_atoi (get_value_of_key(env, "SHLVL"), 1, 0, 0) + 1);
	command[1] = ft_strjoin("SHLVL=", nbr);
	free(nbr);
	command[2] = NULL;
	export_with_args(env, command, 0, 0);
	free_split(command);
	return (env);
}
