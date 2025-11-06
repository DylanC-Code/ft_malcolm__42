/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_config_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:31 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 14:03:38 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/net/mac_parser.h"

bool parse_cli_config(t_config *config, int argc, char **argv)
{
    ft_memset(config, 0, sizeof(t_config));
    if (argc != 5)
        return ft_error("invalid arguments.\nUsage: ./ft_malcolm <src_ip> <src_mac> <tgt_ip> <tgt_mac>", EXIT_FAILURE);
    if (inet_pton(AF_INET, argv[1], &config->src_ip) != 1)
        return ft_error("invalid source ip.", EXIT_FAILURE);
    if (inet_pton(AF_INET, argv[3], &config->tgt_ip) != 1)
        return ft_error("invalid target ip.", EXIT_FAILURE);
    if (!parse_str_mac_address(argv[2], &config->src_mac))
        return EXIT_FAILURE;
    if (!parse_str_mac_address(argv[4], &config->tgt_mac))
        return EXIT_FAILURE;
    return (EXIT_SUCCESS);
}