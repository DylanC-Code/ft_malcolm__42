/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_serializer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:50:31 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:52:00 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_SERIALIZER_H
# define ARP_SERIALIZER_H

# include "domain/arp/arp_frame.h"

bool	serialize_arp_frame(const t_arp_frame *frame, unsigned char dst[64]);

#endif