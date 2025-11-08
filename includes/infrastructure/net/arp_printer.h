/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_printer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:09:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:42 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_PRINTER_H
# define ARP_PRINTER_H

# include "domain/arp/arp_frame.h"

void	print_arp_frame(t_arp_frame *pkt);

#endif
