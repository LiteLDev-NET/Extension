#pragma once
#include <mc/Tick.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{

    public
    ref struct TickHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(TickHandle, ::Tick)

            property unsigned long long T
        {
            unsigned long long get()
            {
                return NativePtr->t;
            }
        }
    };

} // namespace BedrockServer::Extension::Handle
