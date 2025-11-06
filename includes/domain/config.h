/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:13 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 14:02:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <netinet/in.h>
#include "domain/mac.h"

typedef struct config
{
    struct in_addr src_ip;
    struct in_addr tgt_ip;
    t_mac src_mac;
    t_mac tgt_mac;
} t_config;

#endif