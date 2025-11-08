/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iface.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:55:07 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 11:42:43 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFACE_H
# define IFACE_H

# include "domain/config.h"
# include <net/if.h>
# include <net/if_packet.h>
# include <netpacket/packet.h> // ✅ définit struct sockaddr_ll
# include <stdbool.h>
# include <sys/socket.h> // pour socket(), AF_PACKET

typedef struct s_iface
{
	int					fd;
	unsigned int		if_index;
	struct sockaddr_ll	addr;
}						t_iface;

typedef enum e_iface_status
{
	IFACE_CLOSING_SUCCESS,
	IFACE_OPENING_SUCCESS,
	IFACE_RECV_SUCCESS,
	IFACE_ALLOC_FAIL,
	IFACE_SOCKET_FAIL,
	IFACE_IFINDEX_FAIL,
	IFACE_BIND_FAIL,
	IFACE_RECV_FAIL,
	IFACE_CONTENT_TOO_SHORT,
	IFACE_INVALID_PROTOCOL,
	IFACE_INVALID_ARP_OPERATION,
}						t_iface_status;

char					*iface_strerror(t_iface_status err);

t_iface_status			iface_open(t_iface **p_iface);
t_iface_status			iface_close(t_iface *iface);
t_iface_status			iface_recv(t_iface *iface, unsigned char *dst,
							size_t dst_size, ssize_t *bytes_read);

#endif
