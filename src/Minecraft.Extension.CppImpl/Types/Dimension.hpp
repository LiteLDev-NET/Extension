#pragma once
#include <mc/Dimension.hpp>
#include "Types.hpp"


namespace BedrockServer::Extension::Handle
{
    public ref class DimensionHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(DimensionHandle, ::Dimension)
    public:
    };
} // namespace BedrockServer::Extension::Handle