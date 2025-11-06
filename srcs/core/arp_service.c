/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:46 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 23:09:50 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_service.h"
#include "infrastructure/shared.h"

bool listen_arp_request_and_reply(t_config *config)
{
    t_iface *iface;
    t_iface_status iface_open_status = iface_open(&iface);
    (void)config;

    if (iface_open_status != IFACE_OPENING_SUCCESS)
        return (ft_error(iface_strerror(iface_open_status), false));
    iface_close(iface);
    __builtin_printf("iface close correctly\n");
    return true;
}