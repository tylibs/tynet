#ifndef TY_CONNECTION_H_
#define TY_CONNECTION_H_

#include <ty/printable.hpp>
#include "etl/string.h"

class Connection : public Printable
{
public:
    Connection();
    virtual ~Connection();

    size_t printTo(Print &out) const;

private:
};
#endif // TY_CONNECTION_H_
