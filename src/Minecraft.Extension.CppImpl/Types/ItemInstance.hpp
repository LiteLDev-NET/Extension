#pragma once
#include <mc/ItemInstance.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public
    ref class ItemInstanceHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ItemInstanceHandle, ::ItemInstance)
    public:
    };
} // namespace BedrockServer::Extension::Handle
