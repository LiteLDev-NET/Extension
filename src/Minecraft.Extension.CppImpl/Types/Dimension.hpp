#pragma once
#include <mc/Dimension.hpp>
#include "Types.hpp"


namespace BedrockServer::Extension
{
    public ref class Dimension : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Dimension, ::Dimension)
    public:
    };
} // namespace BedrockServer::Extension