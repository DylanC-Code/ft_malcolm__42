/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iface.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:54:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:16:05 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/iface.h"
#include "infrastructure/shared.h"
#include "libft.h"
#include <linux/if_ether.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

char	*iface_strerror(t_iface_status err)
{
	if (err == IFACE_OPENING_SUCCESS)
		return ("interface opened successfully");
	else if (err == IFACE_CLOSING_SUCCESS)
		return ("interface closed successfully");
	else if (err == IFACE_RECV_SUCCESS)
		return ("data read successfully from interface");
	else if (err == IFACE_ALLOC_FAIL)
		return ("iface memory allocation failed");
	else if (err == IFACE_SOCKET_FAIL)
		return ("opening socket failed");
	else if (err == IFACE_IFINDEX_FAIL)
		return ("retrieving interface index failed");
	else if (err == IFACE_BIND_FAIL)
		return ("binding socket to interface failed");
	else if (err == IFACE_RECV_FAIL)
		return ("receiving data from interface failed");
	else if (err == IFACE_CONTENT_TOO_SHORT)
		return ("received content is too short");
	else if (err == IFACE_INVALID_PROTOCOL)
		return ("received content has invalid protocol");
	else if (err == IFACE_INVALID_ARP_OPERATION)
		return ("received content has invalid ARP operation");
	else
		return ("unknown iface error");
}

t_iface_status	iface_open(t_iface **p_iface)
{
	t_iface	*iface;

	iface = ft_calloc(1, sizeof(t_iface));
	if (!iface)
		return (IFACE_ALLOC_FAIL);
	iface->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (iface->fd == -1)
		return (IFACE_SOCKET_FAIL);
	iface->if_index = if_nametoindex("eth0");
	if (!iface->if_index)
		return (IFACE_IFINDEX_FAIL);
	iface->addr.sll_family = AF_PACKET;
	iface->addr.sll_protocol = htons(ETH_P_ARP);
	iface->addr.sll_ifindex = iface->if_index;
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

t_iface_status	iface_close(t_iface *iface)
{
	if (iface->fd > 2)
		close(iface->fd);
	free(iface);
	return (IFACE_CLOSING_SUCCESS);
}

static inline uint16_t	get_u16(const void *ptr)
{
	uint16_t	res;

	res = 0;
	ft_memcpy(&res, ptr, sizeof(uint16_t));
	return (htons(res));
}

t_iface_status	iface_recv(t_iface *iface, unsigned char *dst, size_t dst_size,
		ssize_t *bytes_read)
{
	// unsigned char buff[65536];
	// struct sockaddr_ll src;
	// socklen_t slen = sizeof(src);
	*bytes_read = recvfrom(iface->fd, dst, dst_size, 0, NULL, NULL);
	if (*bytes_read == -1)
		return (IFACE_RECV_FAIL);
	if (*bytes_read < ETH_HLEN)
		return (IFACE_CONTENT_TOO_SHORT);
	return (IFACE_RECV_SUCCESS);
	// if (bytes_read < ETH_HLEN + 28)
	// 	return (IFACE_CONTENT_TOO_SHORT);
	// uint16_t ethertype = get_u16(buff + offsetof(struct ethhdr, h_proto));
	// uint16_t arp_op = get_u16(buff + ETH_HLEN + offsetof(struct arphdr,
	// ar_op));
	// if (ethertype != ETH_P_ARP)
	// 	return (IFACE_INVALID_PROTOCOL);
	// if (arp_op == ARPOP_REQUEST)
	// 	__builtin_printf("ARP request reçue, taille=%zd\n", bytes_read);
	// return (IFACE_INVALID_ARP_OPERATION);
}
