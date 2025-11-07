/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:54:04 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 16:59:25 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_CONFIG_PARSER_H
# define CLI_CONFIG_PARSER_H

# include "domain/config.h"
# include "infrastructure/shared.h"
# include "libft.h"
# include <arpa/inet.h>
# include <stdbool.h>

typedef enum e_conf_cli_parser
{
	CONFIG_CLI_PARSER_SUCCESS = 0,
	CONFIG_CLI_INVALID_ARGS,
	CONFIG_CLI_INVALID_SRC_IP,
	CONFIG_CLI_INVALID_TGT_IP,
	CONFIG_CLI_INVALID_SRC_MAC,
	CONFIG_CLI_INVALID_TGT_MAC
}					t_conf_cli_parser;

t_conf_cli_parser	parse_cli_config(t_config *config, int argc, char **argv);
char				*parse_cli_config_strerror(t_conf_cli_parser err);

#endif
