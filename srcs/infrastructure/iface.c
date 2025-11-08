/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iface.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:54:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 13:13:40 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/iface.h"
#include "infrastructure/shared.h"
#include "libft.h"
#include "shared/byte_utils.h"
#include <errno.h>
#include <net/if.h>
#include <netinet/if_ether.h>
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
	// iface->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	iface->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (iface->fd == -1)
		return (IFACE_SOCKET_FAIL);
	iface->if_index = if_nametoindex("eth0");
	if (!iface->if_index)
		return (IFACE_IFINDEX_FAIL);
	iface->addr.sll_family = AF_PACKET;
	// iface->addr.sll_protocol = htons(ETH_P_ARP);
	iface->addr.sll_protocol = htons(ETH_P_ALL);
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

t_iface_status	iface_recv(t_iface *iface, unsigned char *dst, size_t dst_size,
		ssize_t *bytes_read)
{
	*bytes_read = recvfrom(iface->fd, dst, dst_size, MSG_DONTWAIT, NULL, NULL);
	if (*bytes_read == -1 && errno != EAGAIN && errno != EWOULDBLOCK)
		return (IFACE_RECV_FAIL);
	if (*bytes_read == -1)
		return (IFACE_RECV_NOTHING);
	if (*bytes_read < ETH_HLEN)
		return (IFACE_CONTENT_TOO_SHORT);
	if (ntohs(get_u16(dst + 12)) != ETH_P_ARP)
		return (IFACE_INVALID_PROTOCOL);
	return (IFACE_RECV_SUCCESS);
}
