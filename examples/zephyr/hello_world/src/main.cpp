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

#include <etl/string.h>
#include <ty/instance.h>
#include <ty/logging.h>

#include "tynet/mqtt/mqtt.hpp"

static const char    *kLogModule    = "HelloWorld";
const etl::string<32> kMqttUrl      = "mqtt://localhost:1883";
const etl::string<32> kMqttClientId = "mqtt_client";

extern "C" int main(void)
{
    tyInstance *instance;
    tyLogInfo(kLogModule, "Starting TyNet example");
    instance  = tyInstanceInitSingle();
    auto mqtt = ty::Mqtt::create(*instance);
    if (mqtt.has_value())
    {
        ty::Mqtt::MqttConfiguration mqttConfig = {kMqttUrl, kMqttClientId};
        mqtt->get()->Init(mqttConfig);
    }

    while (true)
    {
        // next event in 1 second
        sleep(1);
    }
    tyInstanceFinalize(instance);
    return 0;
}
