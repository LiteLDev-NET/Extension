#include "Block.hpp"

#include "CompoundTag.hpp"
#include "Block.hpp"
#include "HashedString.hpp"

namespace BedrockServer::Extension
{
    inline Block^ Block::Create(const String^ str, unsigned short tileData)
    {
        return gcnew Block(::Block::create(marshalString((String^)str), tileData));
    }

    inline Block^ Block::Create(CompoundTag^ nbt)
    {
        return gcnew Block(::Block::create(nbt->NativePtr));
    }

    inline HashedString^ Block::Name::get()
    {
        return gcnew HashedString(const_cast<::HashedString*>(&NativePtr->getName()));
    }

    inline int Block::Id::get()
    {
        return NativePtr->getId();
    }

    inline unsigned short Block::TileData::get()
    {
        return NativePtr->getTileData();
    }

    inline CompoundTag^ Block::Nbt::get()
    {
        return gcnew CompoundTag(NativePtr->getNbt().release(), true);
    }

    inline void Block::Nbt::set(CompoundTag^ nbt)
    {
        NativePtr->setNbt(nbt->NativePtr);
    }
} // namespace BedrockServer::Extension
