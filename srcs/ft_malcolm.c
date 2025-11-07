/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:12:03 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	main(int argc, char **argv)
{
	t_config			config;
	t_conf_cli_parser	parse_status;

	if (!checking_perm())
		return (NOT_ROOT_EXIT_CODE);
	parse_status = parse_cli_config(&config, argc, argv);
	if (parse_status != CONFIG_CLI_PARSER_SUCCESS)
	{
		print_cli_error_and_usage(parse_status);
		return (PARSING_CONFIG_EXIT_CODE);
	}
	// if (!checking_config(&config))
	// TODO: verify not same mac and ip and maybe other things
	//     return (INVALID_CONFIG_ERR_CODE);
	if (!listen_arp_request_and_reply(&config))
		return (SPOOFING_EXIT_CODE);
	return (SUCCESS_EXIT_CODE);
}
