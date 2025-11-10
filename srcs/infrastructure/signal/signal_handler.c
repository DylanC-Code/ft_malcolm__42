/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:56:52 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:58:28 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/log/logger.h"
#include "infrastructure/shared.h"
#include "infrastructure/signal/signal_handler.h"
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

bool		g_exiting = false;

static void	handle_sigint(int signum)
{
	(void)signum;
	g_exiting = true;
}

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
}
