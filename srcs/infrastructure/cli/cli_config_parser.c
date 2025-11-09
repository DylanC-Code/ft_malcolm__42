/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:31 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:39:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/net/mac_parser.h"

char	*cli_config_strerror(t_conf_cli_parser_status err)
{
	if (err == CONFIG_CLI_PARSER_SUCCESS)
		return ("Configuration ok");
	else if (err == CONFIG_CLI_INVALID_ARGS)
		return ("Invalid number of arguments!");
	else if (err == CONFIG_CLI_INVALID_SRC_IP)
		return ("Invalid source ip address!");
	else if (err == CONFIG_CLI_INVALID_TGT_IP)
		return ("Invalid target ip address!");
	else if (err == CONFIG_CLI_INVALID_SRC_MAC)
		return ("Invalid source mac address!");
	else if (err == CONFIG_CLI_INVALID_TGT_MAC)
		return ("Invalid target mac address!");
	else
		return ("Unknown configuration error!");
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
	if (argc != 5)
		return (CONFIG_CLI_INVALID_ARGS);
	else if (inet_pton(AF_INET, argv[1], &config->src_ip) != 1)
		return (CONFIG_CLI_INVALID_SRC_IP);
	else if (inet_pton(AF_INET, argv[3], &config->tgt_ip) != 1)
		return (CONFIG_CLI_INVALID_TGT_IP);
	else if (!parse_str_mac_address(argv[2], &config->src_mac))
		return (CONFIG_CLI_INVALID_SRC_MAC);
	else if (!parse_str_mac_address(argv[4], &config->tgt_mac))
		return (CONFIG_CLI_INVALID_TGT_MAC);
	return (CONFIG_CLI_PARSER_SUCCESS);
}
