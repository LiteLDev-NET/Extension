#pragma once
#include <mc/Attribute.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension::Handle
{
    public ref class AttributeHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(AttributeHandle, ::Attribute)
    };
} // namespace BedrockServer::Extension::Handle