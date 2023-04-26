#pragma once
#include <mc/ItemStackBase.hpp>

#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class HashedString;
}

namespace BedrockServer::Extension
{
    public ref class ItemStackBase : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ItemStackBase, ::ItemStackBase)
    public:

        property int Count
        {
            int get();
        }

        property short Id
        {
            short get();
        };
    };
} // namespace BedrockServer::Extension
