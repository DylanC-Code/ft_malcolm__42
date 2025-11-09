/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:31 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 19:10:23 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/net/mac_parser.h"

char	*cli_config_strerror(t_conf_cli_parser_status err)
{
	if (err == CONFIG_CLI_PARSER_SUCCESS)
		return ("Configuration ok");
	else if (err == CONFIG_CLI_INVALID_ARGS_NUMBER)
		return ("Invalid number of arguments!");
	else if (err == CONFIG_CLI_INVALID_ARGS)
		return ("Invalid arguments!");
	else if (err == CONFIG_CLI_INVALID_SRC_IP)
		return ("Invalid source IP address!");
	else if (err == CONFIG_CLI_INVALID_TGT_IP)
		return ("Invalid target IP address!");
	else if (err == CONFIG_CLI_INVALID_SRC_MAC)
		return ("Invalid source MAC address!");
	else if (err == CONFIG_CLI_INVALID_TGT_MAC)
		return ("Invalid target MAC address!");
	else
		return ("Unknown configuration error!");
}

static t_conf_cli_parser_status	four_params_strategy(t_config *config,
		char **argv)
{
	if (inet_pton(AF_INET, argv[1], &config->src_ip) != 1)
		return (CONFIG_CLI_INVALID_SRC_IP);
	else if (inet_pton(AF_INET, argv[3], &config->tgt_ip) != 1)
		return (CONFIG_CLI_INVALID_TGT_IP);
	else if (!parse_str_mac_address(argv[2], &config->src_mac))
		return (CONFIG_CLI_INVALID_SRC_MAC);
	else if (!parse_str_mac_address(argv[4], &config->tgt_mac))
		return (CONFIG_CLI_INVALID_TGT_MAC);
	return (CONFIG_CLI_PARSER_SUCCESS);
}

static t_conf_cli_parser_status	five_params_strategy(t_config *config,
		char **argv)
{
	t_conf_cli_parser_status	base_status;

	base_status = four_params_strategy(config, argv);
	if (base_status != CONFIG_CLI_PARSER_SUCCESS)
		return (base_status);
	if (ft_strcmp(argv[5], "--verbose") != 0)
		return (CONFIG_CLI_INVALID_ARGS);
	config->verbose = true;
	return (CONFIG_CLI_PARSER_SUCCESS);
}

/// @brief Parses CLI arguments into a config struct
/// @param config Pointer to the config struct to populate
/// @param argc Number of CLI arguments
/// @param argv Array of CLI argument strings
/// @return
t_conf_cli_parser_status	parse_cli_config(t_config *config, int argc,
		char **argv)
{
	ft_memset(config, 0, sizeof(t_config));
	if (argc == 5)
		return (four_params_strategy(config, argv));
	else if (argc == 6)
		return (five_params_strategy(config, argv));
	return (CONFIG_CLI_INVALID_ARGS_NUMBER);
}
