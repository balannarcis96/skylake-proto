//
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Balan Narcis (balannarcis96@gmail.com)
//
#pragma once

#include <skl_result>
#include <skl_socket>

#include "skl_proto/endpoint.hpp"

namespace skl::proto {

//! Create new server endpoint
[[nodiscard]] skl_result<endpoint_t> make_server_endpoint(ipv4_addr_t f_ip_addr, net_port_t f_udp_port) noexcept;

//! Create new client endpoint
[[nodiscard]] skl_result<endpoint_t> make_client_endpoint(ipv4_addr_t f_ip_addr, net_port_t f_udp_port) noexcept;

} // namespace skl::proto
