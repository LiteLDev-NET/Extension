#pragma once
#include <mc/ItemStackBase.hpp>

#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class HashedStringHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ItemStackBaseHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ItemStackBaseHandle, ::ItemStackBase)
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
} // namespace BedrockServer::Extension::Handle
