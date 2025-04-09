#include "tynet/tynet-config.h"

#include <etl/string.h>
#include <ty/instance.h>
#include "tynet/connection.hpp"

#include "etl/memory.h"
#include "etl/optional.h"

#if CONFIG_TYNET_MQTT_ENABLED

#ifndef _TY_MQTT_HPP_
#define _TY_MQTT_HPP_

namespace ty {
class Mqtt : public Connection
{
public:
    struct MqttConfiguration
    {
        const etl::istring &serverUri;
        const etl::istring &clientId;
    };

public:
    Mqtt();
    ~Mqtt();
    size_t printDriverInfo(Print &out) const;

public:
    static auto create(tyInstance const &) -> etl::optional<etl::unique_ptr<Mqtt>>;
    static auto destroy(etl::unique_ptr<Mqtt> &) -> void;

    void Init(MqttConfiguration &aConfiguration);

private:
};
} // namespace ty

#endif /* _TY_MQTT_HPP_ */
#endif /* CONFIG_ETH_ENABLED */
