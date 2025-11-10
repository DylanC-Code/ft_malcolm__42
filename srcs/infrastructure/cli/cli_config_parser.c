/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:31 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:49:04 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/log/logger.h"
#include "infrastructure/net/ip_parser.h"
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

static t_conf_cli_parser_status	parsing_ips(t_config *config, char **argv)
{
	if (config->verbose)
		log_debug("Parsing source IP/Hostname: '%s'", argv[1]);
	if (!parse_str_ip_address(argv[1], &config->src_ip))
		return (CONFIG_CLI_INVALID_SRC_IP);
	if (config->verbose)
		log_debug("Parsing target IP/Hostname: '%s'", argv[3]);
	if (!parse_str_ip_address(argv[3], &config->tgt_ip))
		return (CONFIG_CLI_INVALID_TGT_IP);
	return (CONFIG_CLI_PARSER_SUCCESS);
}

static t_conf_cli_parser_status	four_params_strategy(t_config *config,
		char **argv)
{
	t_conf_cli_parser_status	ip_parsing_status;

	ip_parsing_status = parsing_ips(config, argv);
	if (ip_parsing_status != CONFIG_CLI_PARSER_SUCCESS)
		return (ip_parsing_status);
	if (!parse_str_mac_address(argv[2], &config->src_mac))
		return (CONFIG_CLI_INVALID_SRC_MAC);
	else if (!parse_str_mac_address(argv[4], &config->tgt_mac))
		return (CONFIG_CLI_INVALID_TGT_MAC);
	return (CONFIG_CLI_PARSER_SUCCESS);
}

static t_conf_cli_parser_status	five_params_strategy(t_config *config,
		char **argv)
{
	t_conf_cli_parser_status	base_status;

	if (ft_strcmp(argv[5], "--verbose") != 0)
		return (CONFIG_CLI_INVALID_ARGS);
	config->verbose = true;
	base_status = four_params_strategy(config, argv);
	if (base_status != CONFIG_CLI_PARSER_SUCCESS)
		return (base_status);
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
