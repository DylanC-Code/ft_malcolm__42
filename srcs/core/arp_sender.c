/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_sender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:13:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 21:56:05 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_sender.h"
#include "domain/ip_address.h"
#include "infrastructure/iface.h"
#include "infrastructure/net/arp_serializer.h"
#include "libft.h"
#include <net/if_arp.h>
#include <netinet/if_ether.h>

static void	create_arp_response(t_arp_context *ctx, t_arp_frame *arp_response)
{
	ft_memset(arp_response, 0, sizeof(t_arp_frame));
	arp_response->header_arp.ar_pro = ETH_P_IP;
	arp_response->header_arp.ar_hln = ETH_ALEN;
	arp_response->header_arp.ar_pln = IP4LEN;
	arp_response->header_arp.ar_hrd = ARPHRD_ETHER;
	arp_response->header_arp.ar_op = ARPOP_REPLY;
	ft_memcpy(arp_response->src_mac.bytes, ctx->config->src_mac.bytes,
		sizeof(arp_response->src_mac.bytes));
	ft_memcpy(arp_response->tgt_mac.bytes, ctx->config->tgt_mac.bytes,
		sizeof(arp_response->tgt_mac.bytes));
	ft_memcpy(&arp_response->src_ip, &ctx->config->src_ip.s_addr,
		sizeof(arp_response->src_ip));
	ft_memcpy(&arp_response->tgt_ip, &ctx->config->tgt_ip.s_addr,
		sizeof(arp_response->tgt_ip));
}

bool	send_arp_frame(t_arp_context *ctx)
{
	t_arp_frame		arp_response;
	unsigned char	raw_frame[128];
	t_iface_status	sending_status;

	create_arp_response(ctx, &arp_response);
	serialize_arp_frame(&arp_response, raw_frame);
	sending_status = iface_send(ctx->iface, raw_frame, sizeof(raw_frame));
	if (sending_status == IFACE_SEND_SUCCESS)
	{
		__builtin_printf("Frame sent successfully\n");
		ctx->config->once = true;
		return (true);
	}
	return (false);
}
