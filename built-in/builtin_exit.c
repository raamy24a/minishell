/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:51 by radib             #+#    #+#             */
/*   Updated: 2026/01/15 16:30:05 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

t_long_long_verif	*atoll(const char *nptr, int sign, long long total, int i)
{
	t_long_long_verif	*nbr;

	nbr->status = 1;
	nbr = malloc(sizeof (t_long_long_verif));
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total *= 10;
		total += nptr[i] - '0';
		if ((total * sign > 0) && sign == -1)
			nbr->status = 0;
		if ((total < 0) && sign == 1)
			nbr->status = 0;
		i++;
	}
	nbr->nbr = total * sign;
	return (nbr);
}
int	exit_call(int x, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp->next)
	{
		temp = temp->next;
		free(env->key);
		free(env->value);
		free(env);
		env = temp;
	}
	free(env->key);
	free(env->value);
	free(env);
	rl_clear_history();
	x = x % 256;
	printf("exit\n");
	exit (x);
}
