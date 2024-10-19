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

#pragma once
#include"tundra.h"


extern bool utils_xlat_addr__nat64_clat__translate_6to4_translator_ip(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv6, uint8_t *out_ipv4);
extern bool utils_xlat_addr__nat64_clat__translate_4to6_translator_ip(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv4, uint8_t *out_ipv6);
extern bool utils_xlat_addr__nat64_clat__translate_6to4_prefix_for_main_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv6, uint8_t *out_ipv4);
extern bool utils_xlat_addr__nat64_clat__translate_4to6_prefix_for_main_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv4, uint8_t *out_ipv6);
extern bool utils_xlat_addr__siit__translate_6to4_prefix_for_main_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv6, uint8_t *out_ipv4);
extern bool utils_xlat_addr__siit__translate_4to6_prefix_for_main_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv4, uint8_t *out_ipv6);
extern bool utils_xlat_addr__siit__translate_6to4_prefix_for_main_packet_local(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv6, uint8_t *out_ipv4);
extern bool utils_xlat_addr__siit__translate_4to6_prefix_for_main_packet_local(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv4, uint8_t *out_ipv6);
extern bool utils_xlat_addr__nat64_clat_siit__translate_6to4_prefix_for_icmp_error_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv6, uint8_t *out_ipv4);
extern void utils_xlat_addr__nat64_clat_siit__translate_4to6_prefix_for_icmp_error_packet(const tundra__thread_ctx *const ctx, const uint8_t *in_ipv4, uint8_t *out_ipv6);
