/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include <string>

namespace ctre {
namespace phoenix6 {

    class ISerializable
    {
    public:
        virtual std::string Serialize() const = 0;
    };

}
}
