/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:00 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:44:36 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/config_manager.h"
#include "core/config_validator.h"
#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/cli/cli_usage.h"
#include "infrastructure/log/logger.h"

bool	load_and_validate_config(int argc, char **restrict argv,
		t_config *restrict cfg)
{
	t_conf_cli_parser_status	parsing_status;
	t_check_config_status		checking_status;

	parsing_status = parse_cli_config(cfg, argc, argv);
	if (parsing_status != CONFIG_CLI_PARSER_SUCCESS)
	{
		parsing_error_and_usage(parsing_status);
		return (false);
	}
	checking_status = check_config(cfg);
	if (checking_status != CHECK_CONFIG_SUCCESS)
	{
		log_error(config_validation_strerror(checking_status));
		return (false);
	}
	return (true);
}
