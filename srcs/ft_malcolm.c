/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 14:05:32 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int main(int argc, char **argv)
{
    t_config config;
    if (parse_cli_config(&config, argc, argv) == EXIT_FAILURE)
        return 1;
    // print_mac(&config.src_mac);
    // __builtin_printf("\n");
    // print_mac(&config.tgt_mac);
    // __builtin_printf("\n");
    // destroy_config(config);
    return 0;
}
