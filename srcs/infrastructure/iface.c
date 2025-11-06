/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iface.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:54:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 23:08:23 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux/if_ether.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <unistd.h>

#include "infrastructure/iface.h"
#include "infrastructure/shared.h"
#include "libft.h"

typedef struct s_iface
{
    int fd;
    unsigned if_index;
    struct sockaddr_ll addr;
} t_iface;

char *iface_strerror(t_iface_status err)
{
    if (err == IFACE_OPENING_SUCCESS)
        return "interface opened successfully";
    else if (err == IFACE_CLOSING_SUCCESS)
        return "interface closed successfully";
    else if (err == IFACE_ALLOC_FAIL)
        return "iface memory allocation failed";
    else if (err == IFACE_SOCKET_FAIL)
        return "opening socket failed";
    else if (err == IFACE_IFINDEX_FAIL)
        return "retrieving interface index failed";
    else if (err == IFACE_BIND_FAIL)
        return "binding socket to interface failed";
    else
        return "unknown iface error";
}

t_iface_status iface_open(t_iface **p_iface)
{
    t_iface *iface = ft_calloc(1, sizeof(t_iface));
    if (!iface)
        return IFACE_ALLOC_FAIL;
    iface->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (iface->fd == -1)
        return IFACE_SOCKET_FAIL;
    iface->if_index = if_nametoindex("eth0");
    if (!iface->if_index)
        return IFACE_IFINDEX_FAIL;
    iface->addr.sll_family = AF_PACKET;
    iface->addr.sll_protocol = htons(ETH_P_ARP);
    iface->addr.sll_ifindex = iface->if_index;
    iface->addr.sll_halen = ETH_ALEN;
    if (bind(iface->fd, (const struct sockaddr *)&iface->addr, sizeof(struct sockaddr_ll)) != 0)
    {
        iface_close(iface);
        return IFACE_BIND_FAIL;
    }
    *p_iface = iface;
    return IFACE_OPENING_SUCCESS;
}

t_iface_status iface_close(t_iface *iface)
{
    if (!iface)
        return false;
    if (iface->fd > 2)
        close(iface->fd);
    free(iface);
    return IFACE_CLOSING_SUCCESS;
}