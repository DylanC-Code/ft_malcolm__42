/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:02:36 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:52:29 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/config_validator.h"
#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/log/logger.h"
#include <unistd.h>

void	parsing_error_and_usage(t_conf_cli_parser_status err)
{
	char	*usage;

	usage = "Usage: ./ft_malcolm <src_ip|hostname_src> <src_mac> <tgt_ip|hostname_tgt> <tgt_mac> [--verbose]\n";
	log_error(cli_config_strerror(err));
	log_debug(usage);
}
