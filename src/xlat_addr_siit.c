/*
Copyright (c) 2024 Vít Labuda. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
following conditions are met:
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
    disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
    following disclaimer in the documentation and/or other materials provided with the distribution.
 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
    products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include"tundra.h"
#include"xlat_addr_siit.h"

#include"utils_xlat_addr.h"


bool xlat_addr_siit__translate_4to6_addr_for_main_packet(tundra__thread_ctx *const ctx, const uint8_t *in_src_ipv4, const uint8_t *in_dst_ipv4, uint8_t *out_src_ipv6, uint8_t *out_dst_ipv6) {
    if(!utils_xlat_addr__siit__translate_4to6_prefix_for_main_packet_local(ctx, in_src_ipv4, out_src_ipv6))
        return false;

    return utils_xlat_addr__siit__translate_4to6_prefix_for_main_packet(ctx, in_dst_ipv4, out_dst_ipv6);
}

bool xlat_addr_siit__translate_4to6_addr_for_icmp_error_packet(tundra__thread_ctx *const ctx, const uint8_t *in_src_ipv4, const uint8_t *in_dst_ipv4, uint8_t *out_src_ipv6, uint8_t *out_dst_ipv6) {
    utils_xlat_addr__nat64_clat_siit__translate_4to6_prefix_for_icmp_error_packet(ctx, in_src_ipv4, out_src_ipv6);
    utils_xlat_addr__nat64_clat_siit__translate_4to6_prefix_for_icmp_error_packet(ctx, in_dst_ipv4, out_dst_ipv6);

    return true;
}

bool xlat_addr_siit__translate_6to4_addr_for_main_packet(tundra__thread_ctx *const ctx, const uint8_t *in_src_ipv6, const uint8_t *in_dst_ipv6, uint8_t *out_src_ipv4, uint8_t *out_dst_ipv4) {
    if(!utils_xlat_addr__siit__translate_6to4_prefix_for_main_packet(ctx, in_src_ipv6, out_src_ipv4))
        return false;

    return utils_xlat_addr__siit__translate_6to4_prefix_for_main_packet_local(ctx, in_dst_ipv6, out_dst_ipv4);
}

bool xlat_addr_siit__translate_6to4_addr_for_icmp_error_packet(tundra__thread_ctx *const ctx, const uint8_t *in_src_ipv6, const uint8_t *in_dst_ipv6, uint8_t *out_src_ipv4, uint8_t *out_dst_ipv4) {
    if(!utils_xlat_addr__nat64_clat_siit__translate_6to4_prefix_for_icmp_error_packet(ctx, in_src_ipv6, out_src_ipv4))
        return false;

    return utils_xlat_addr__nat64_clat_siit__translate_6to4_prefix_for_icmp_error_packet(ctx, in_dst_ipv6, out_dst_ipv4);
}
