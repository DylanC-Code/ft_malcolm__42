/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 11:33:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int main(int argc, char **argv)
{
    t_config config;
    // t_config *config = parse_cli_config(argc, argv);
    if (parse_cli_config(&config, argc, argv) == EXIT_FAILURE)
        return 1;

    // destroy_config(config);
    return 0;
}
