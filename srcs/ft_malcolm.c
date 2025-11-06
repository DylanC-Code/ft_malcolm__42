/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 21:38:31 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int main(int argc, char **argv)
{
    t_config config;

    if (!checking_perm())
        return NOT_ROOT_ERR_CODE;
    if (!parse_cli_config(&config, argc, argv))
        return PARSING_CONFIG_ERR_CODE;
    // if (!checking_config(&config)) //TODO: verify not same mac and ip and maybe other things
    //     return INVALID_CONFIG_ERR_CODE;
    if (!listen_arp_request_and_reply(&config))
        return SPOOFING_ERR_CODE;
    return SUCCESS_CODE;
}
