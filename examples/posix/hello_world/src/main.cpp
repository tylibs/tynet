// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TyNet simplest example: Hello World
 */

#include <pthread.h>
#include <stdio.h>
#include <ty/instance.h>
#include <ty/logging.h>
#include <unistd.h>
#include "tynet/platform/ethernet.hpp"

static const char *kLogModule = "HelloWorld";

/*****************************************************************************/
// just as a hint, but better not to pack, because this object only lives once

extern "C" int main(void)
{
    tyInstance *instance;
    tyLogInfo(kLogModule, "Starting TyNet example");
    instance = tyInstanceInitSingle();
    Ethernet::create(*instance);
    while (true)
    {
        // next event in 1 second
        sleep(1);
    }
    tyInstanceFinalize(instance);
    return 0;
}
