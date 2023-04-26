#pragma once
#include <mc/BlockPalette.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension
{
    public ref class BlockPalette : SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockPalette, ::BlockPalette)
    public:
    };
} // namespace BedrockServer::Extension