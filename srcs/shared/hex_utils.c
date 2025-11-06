/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:41:37 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 13:43:54 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared/hex_utils.h"

uint8_t hex_pair_to_u8(char str[2])
{
    char high = ft_tolower(str[0]);
    char low = ft_tolower(str[1]);

    uint8_t res = 0;
    if (ft_isdigit(high))
        res += ((high - '0') << 4);
    else
        res += ((high - 'a' + 10) << 4);
    if (ft_isdigit(low))
        res += (low - '0');
    else
        res += (low - 'a' + 10);
    return res;
}

char value_to_hex_char(uint8_t nibble)
{
    if (nibble < 10)
        return nibble + '0';
    else
        return (nibble - 10) + 'a';
}

void u8_to_hex_pair(uint8_t src, char dst[2])
{
    int low = src & 0x0F;
    int high = (src >> 4) & 0x0F;
    dst[0] = value_to_hex_char(high);
    dst[1] = value_to_hex_char(low);
}