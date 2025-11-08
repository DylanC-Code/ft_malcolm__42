/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_serializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:50:15 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 16:11:41 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/net/arp_serializer.h"
#include "libft.h"
#include <net/ethernet.h>

static void	serialize_arp_header(const t_arp_frame *frame,
		unsigned char dst[64])
{
	unsigned char	*arp_p;
	uint16_t		tmp16;

	arp_p = dst + ETH_HLEN;
	tmp16 = htons(frame->header_arp.ar_hrd);
	ft_memcpy(arp_p, tmp16, sizeof(tmp16));
	arp_p += 2;
	tmp16 = htons(frame->header_arp.ar_pro);
	ft_memcpy(arp_p, tmp16, sizeof(tmp16));
	arp_p += 2;
	*arp_p++ = frame->header_arp.ar_hln;
	*arp_p++ = frame->header_arp.ar_pln;
	tmp16 = htons(frame->header_arp.ar_op);
	ft_memcpy(arp_p, tmp16, sizeof(tmp16));
}

/// @brief Serialize an ARP frame into a byte array
/// @param frame Pointer to the ARP frame to serialize
/// @param dst Destination byte array (must be at least 64 bytes)
/// @return true on success, false on failure
bool	serialize_arp_frame(const t_arp_frame *frame, unsigned char dst[64])
{
	ft_memset(dst, 0, sizeof(dst));
	serialize_arp_header(frame, dst);
}
