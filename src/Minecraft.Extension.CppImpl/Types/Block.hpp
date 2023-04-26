#pragma once
#include <mc/Block.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class CompoundTag;
    ref class HashedString;
}

namespace BedrockServer::Extension
{
    public ref class Block :SafeHandle, ICppClass
    {
        DEFAULT_DEF(Block, ::Block)
    public:

        inline static Block^ Create(const String^ str, unsigned short tileData);
        inline static Block^ Create(CompoundTag^ nbt);

        property HashedString^ Name { HashedString^ get(); };
        property CompoundTag^ Nbt { CompoundTag^ get(); void set(CompoundTag^ value); };

        property int Id
        {
            int get();
        }
        property unsigned short TileData
        {
            unsigned short get();
        }
    };
} // namespace BedrockServer::Extension
