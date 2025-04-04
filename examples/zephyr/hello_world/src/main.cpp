// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TyNet simplest example: Hello World
 */

#include <ty/logging.h>
#include <ty/platform/toolchain.h>
#include <zephyr/kernel.h>
#include "tynet/platform/settings.h"

static const char *kLogModule = "HelloWorld";

/*****************************************************************************/
// just as a hint, but better not to pack, because this object only lives once
TY_TOOL_PACKED_BEGIN
struct AppPersistentSettings
{
    int a;
    int b;
} TY_TOOL_PACKED_END;

// keep the settings in global scope but not accessible (in C this would be static)
// the Settings will be injected in each module to support testing setups
namespace {
AppPersistentSettings mAppPersistentSettings = {1, 2};
}

extern "C" int main(void)
{
    tyInstance *instance;
    tyLogInfo(kLogModule, "Starting TyNet example");

    instance = tyInstanceInitSingle();
    // Initialize the settings subsystem
    tyPlatSettingsInit(instance, NULL, 0);
    tyPlatSettingsSet(instance, 1, (uint8_t *)&mAppPersistentSettings, sizeof(mAppPersistentSettings));
    while (true)
    {
        // next event in 1 second
        k_sleep(K_SECONDS(1));
    }
    tyInstanceFinalize(instance);
    return 0;
}
