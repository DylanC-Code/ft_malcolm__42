/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iface_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:24:47 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 14:04:55 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/iface/iface_open.h"
#include "infrastructure/log/logger.h"
#include "libft.h"
#include <errno.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <netinet/if_ether.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/// @brief Checks if the given sockaddr is of type Ethernet
/// @param ifa_addr Pointer to the sockaddr to check
/// @return True if the sockaddr is of type Ethernet, false otherwise
static bool	is_ll_of_type_ether(struct sockaddr *ifa_addr)
{
	struct sockaddr_ll	*ll_addr;

	if (ifa_addr->sa_family != AF_PACKET)
		return (false);
	ll_addr = (struct sockaddr_ll *)ifa_addr;
	return (ll_addr->sll_hatype == ARPHRD_ETHER);
}

static void	set_ifindex(t_iface *iface, struct ifaddrs *ifa)
{
	const struct sockaddr_ll	*addr = (struct sockaddr_ll *)ifa->ifa_addr;

	iface->if_index = addr->sll_ifindex;
	iface->addr.sll_ifindex = iface->if_index;
	log_info("Found available interface: %s, index: %d", ifa->ifa_name,
		iface->if_index);
}

static bool	find_and_set_ifindex(t_iface *iface)
{
	struct ifaddrs	*ifa;
	struct ifaddrs	*next;

	if (getifaddrs(&ifa) != 0)
		return (false);
	next = ifa;
	while (next && !is_ll_of_type_ether(next->ifa_addr))
		next = next->ifa_next;
	if (next)
		set_ifindex(iface, next);
	freeifaddrs(ifa);
	return (true);
}

t_iface_status	iface_open(t_iface **p_iface)
{
	t_iface	*iface;

	iface = ft_calloc(1, sizeof(t_iface));
	if (!iface)
		return (IFACE_ALLOC_FAIL);
	iface->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (iface->fd == -1)
		return (IFACE_SOCKET_FAIL);
	// iface->if_index = if_nametoindex("eth0");
	// if (!iface->if_index)
	// 	return (IFACE_IFINDEX_FAIL);
	iface->addr.sll_family = AF_PACKET;
	iface->addr.sll_protocol = htons(ETH_P_ALL);
	if (!find_and_set_ifindex(iface))
		return (IFACE_IFINDEX_FAIL);
	iface->addr.sll_halen = ETH_ALEN;
	if (bind(iface->fd, (const struct sockaddr *)&iface->addr,
			sizeof(struct sockaddr_ll)) != 0)
	{
		iface_close(iface);
		return (IFACE_BIND_FAIL);
	}
	*p_iface = iface;
	return (IFACE_OPENING_SUCCESS);
}
