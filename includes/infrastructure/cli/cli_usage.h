/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_usage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:03:22 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:43:50 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_USAGE_H
# define CLI_USAGE_H

# include "infrastructure/cli/cli_config_parser.h"

void	parsing_error_and_usage(t_conf_cli_parser_status err);

#endif
