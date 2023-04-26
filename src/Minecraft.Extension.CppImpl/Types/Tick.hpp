#pragma once
#include <mc/Tick.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{

    public
    ref struct Tick : SafeHandle, ICppClass
    {
        DEFAULT_DEF(Tick, ::Tick)

            property unsigned long long T
        {
            unsigned long long get()
            {
                return NativePtr->t;
            }
        }
    };

} // namespace BedrockServer::Extension
