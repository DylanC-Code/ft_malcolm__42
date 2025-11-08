/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:02:36 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 23:21:30 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/log/logger.h"
#include <unistd.h>

void	print_cli_error_and_usage(t_conf_cli_parser err)
{
	char	*usage;

	usage = "Usage: ./ft_malcolm <src_ip> <src_mac> <tgt_ip> <tgt_mac>\n";
	log_error(parse_cli_config_strerror(err));
	log_debug(usage);
}
