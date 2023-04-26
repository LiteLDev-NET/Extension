#pragma once
#include <mc/Attribute.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension
{
    public ref class Attribute : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Attribute, ::Attribute)
    };
} // namespace BedrockServer::Extension