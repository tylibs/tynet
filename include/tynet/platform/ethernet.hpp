#include "tynet/network_interface.hpp"
#include <ty/instance.h>
#include "tynet/tynet-config.h"

#include "etl/memory.h"
#include "etl/optional.h"

#if CONFIG_TYNET_ETH_ENABLED

#ifndef _ETH_H_
#define _ETH_H_

class Ethernet : public NetworkInterface
{
public:
    Ethernet(uint8_t eth_index = 0);
    ~Ethernet();

    bool begin() { return false; }

    void end();

    // This function must be called before `begin()`
    void setTaskStackSize(size_t size);

    // ETH Handle APIs
    bool fullDuplex() const;
    bool setFullDuplex(bool on);

    uint16_t linkSpeed() const;
    bool     setLinkSpeed(uint16_t speed); // 10 or 100

    bool autoNegotiation() const;
    bool setAutoNegotiation(bool on);

    uint32_t phyAddr() const;

    // void getMac(uint8_t* mac);
    size_t printDriverInfo(Print &out) const;
    // static void eth_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

public:
    void _onEthEvent(int32_t event_id, void *event_data);

public:
    static auto create(tyInstance const &) -> etl::optional<etl::unique_ptr<Ethernet>>;
    static auto destroy(etl::unique_ptr<Ethernet> &) -> void;

private:
    uint8_t  _eth_index;
    bool     _eth_started;
    uint16_t _link_speed;
    bool     _full_duplex;
    bool     _auto_negotiation;
    size_t   _task_stack_size;
    // network_event_handle_t _eth_connected_event_handle;

    static bool ethDetachBus(void *bus_pointer);
    bool        _setFullDuplex(bool on);
    bool        _setLinkSpeed(uint16_t speed);
    bool        _setAutoNegotiation(bool on);
};

#endif /* _ETH_H_ */
#endif /* CONFIG_ETH_ENABLED */
