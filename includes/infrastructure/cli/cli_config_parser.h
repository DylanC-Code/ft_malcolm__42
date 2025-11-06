/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:54:04 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 11:30:15 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLI_CONFIG_PARSER_H__
#define __CLI_CONFIG_PARSER_H__

#include <stdbool.h>
#include "domain/config.h"
#include "infrastructure/shared.h"
#include "libft.h"
#include <arpa/inet.h>

bool parse_cli_config(t_config *config, int argc, char **argv);

#endif