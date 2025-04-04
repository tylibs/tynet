// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0
/**
 * @file
 *   This file implements the Tiny platform abstraction for non-volatile storage of settings.
 */

#include <ty/common/debug.hpp>
#include <ty/exit_code.h>
#include <ty/logging.h>
#include "ty/common/code_utils.hpp"

#include <tynet/platform/ethernet.hpp>

class PosixEthernet : public Ethernet
{
public:
};

Ethernet::Ethernet(uint8_t eth_index)
    : _eth_index(eth_index)
    , _eth_started(false)
    , _link_speed(100)
    , _full_duplex(true)
    , _auto_negotiation(true)
    , _task_stack_size(4096)
{
}

Ethernet::~Ethernet() {}
auto Ethernet::create(tyInstance const &instance) -> etl::optional<etl::unique_ptr<Ethernet>>
{
    auto pImpl = etl::unique_ptr<Ethernet>(new PosixEthernet());
    if (pImpl)
    {
        return etl::optional(etl::move(pImpl));
    }
    return etl::nullopt;
}
