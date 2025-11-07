/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:46 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 12:30:01 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_service.h"
#include "infrastructure/shared.h"
#include <unistd.h>

bool listen_arp_request_and_reply(t_config *config)
{
    t_iface *iface;
    t_iface_status iface_status = iface_open(&iface);
    unsigned char buffer[65536];
    ssize_t bytes_read = 0;

    if (iface_status != IFACE_OPENING_SUCCESS)
        return (ft_error(iface_strerror(iface_status), false));
    while (!config->once)
    {
        sleep(1);
        iface_status = iface_recv(iface, buffer, sizeof(buffer), &bytes_read);
        if (iface_status != IFACE_RECV_SUCCESS)
            ft_error(iface_strerror(iface_status), 0);
    }
    iface_close(iface);
    __builtin_printf("iface close correctly\n");
    return true;
}