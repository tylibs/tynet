#include "tynet/tynet-config.h"

#include <ty/instance.h>
#include "tynet/connection.hpp"

#include "etl/memory.h"
#include "etl/optional.h"

#if CONFIG_TYNET_ETH_ENABLED

#ifndef _ETH_H_
#define _ETH_H_

class Mqtt : public Connection
{
public:
    Mqtt();
    ~Mqtt();
    size_t printDriverInfo(Print &out) const;

public:
    static auto create(tyInstance const &) -> etl::optional<etl::unique_ptr<Mqtt>>;
    static auto destroy(etl::unique_ptr<Mqtt> &) -> void;

    void Init();

private:
};

#endif /* _ETH_H_ */
#endif /* CONFIG_ETH_ENABLED */
