// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   TyNet simplest example: Hello World
 */

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <unistd.h>

#include <etl/string.h>
#include <ty/instance.h>
#include <ty/logging.h>

#include "tynet/mqtt/mqtt.hpp"

static const char    *kLogModule    = "HelloWorld";
const etl::string<32> kMqttUrl      = "mqtt://localhost:1883";
const etl::string<32> kMqttClientId = "mqtt_client";

/*****************************************************************************/
// just as a hint, but better not to pack, because this object only lives once

extern "C" void app_main(void)
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
}
