/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_receiver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:06:20 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 23:24:42 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_receiver.h"
#include "domain/arp/arp_parser.h"
#include "infrastructure/log/logger.h"

bool	receive_arp_frame(t_arp_context *ctx)
{
	t_iface_status	status;
	unsigned char	buff[65536];
	ssize_t			bytes_read;

	bytes_read = 0;
	status = iface_recv(ctx->iface, buff, sizeof(buff), &bytes_read);
	if (status == IFACE_RECV_NOTHING)
		return (false);
	if (status >= IFACE_ALLOC_FAIL)
	{
		log_error(iface_strerror(status));
		/* TODO: handle which error will made quit the program. */
		return (false);
	}
	if (status != IFACE_RECV_SUCCESS)
		return (false);
	return (parse_arp_request(buff, bytes_read, &ctx->arp_pkt));
}
