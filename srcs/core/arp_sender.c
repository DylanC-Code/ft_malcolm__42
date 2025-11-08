/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_sender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:13:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:46:32 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_sender.h"
#include "infrastructure/iface.h"
#include "libft.h"

bool	send_arp_frame(t_arp_context *ctx)
{
	t_arp_frame	arp_response;
	

	ft_memset(&arp_response, 0, sizeof(t_arp_frame));
	arp_response.header_arp.ar_pro = ARPOP_REPLY;
	arp_response.src_ip = ctx->arp_pkt.tgt_ip;
	arp_response.src_mac = ctx->config->src_mac;
	arp_response.tgt_ip = ctx->arp_pkt.src_ip;
	arp_response.tgt_mac = ctx->arp_pkt.src_mac;
	// iface_send(ctx->iface, )
	return (true);
}
