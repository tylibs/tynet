#include <tynet/platform/mqtt.hpp>

size_t Mqtt::printDriverInfo(Print &out) const
{
    auto   self  = static_cast<const Mqtt *>(this);
    size_t bytes = 0;
    // bytes += out.print(",");
    // bytes += out.print(linkSpeed());
    // bytes += out.print("M");
    // if (fullDuplex())
    // {
    //     bytes += out.print(",FULL_DUPLEX");
    // }
    // if (autoNegotiation())
    // {
    //     bytes += out.print(",AUTO");
    // }
    // bytes += out.printf(",ADDR:0x%lX", phyAddr());
    return bytes;
}
