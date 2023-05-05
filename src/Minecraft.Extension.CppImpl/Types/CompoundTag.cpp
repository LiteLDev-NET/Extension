#include "CompoundTag.hpp"

#include "ItemStack.hpp"
#include "Actor.hpp"
#include "Block.hpp"
#include "BlockActor.hpp"
#include "Player.hpp"
#include "CompoundTagVariant.hpp"
#include "ByteArrayTag.hpp"
#include "ByteTag.hpp"
#include "CompoundTag.hpp"
#include "DoubleTag.hpp"
#include "ShortTag.hpp"
#include "EndTag.hpp"
#include "FloatTag.hpp"
#include "Int64Tag.hpp"
#include "IntArrayTag.hpp"
#include "IntTag.hpp"
#include "ListTag.hpp"
#include "ShortTag.hpp"
#include "StringTag.hpp"
#include "Tag.hpp"

namespace BedrockServer::Extension::Handle
{

    inline CompoundTagHandle^ CompoundTagHandle::Create()
    {
        return gcnew CompoundTagHandle(::CompoundTag::create().release(), true);
    }

    inline Dictionary<String^, CompoundTagVariantHandle^>^ CompoundTagHandle::Value()
    {
        Dictionary<String^, CompoundTagVariantHandle^>^ ret;
        auto& stdmap = NativePtr->value();
        ret = gcnew Dictionary<String^, CompoundTagVariantHandle^>(int(stdmap.size()));
        for (auto iter = stdmap.begin(); iter != stdmap.end(); ++iter)
            ret->Add(
                marshalString((*iter).first),
                gcnew CompoundTagVariantHandle(&iter->second));
        return ret;
    }

    // put value
    inline void CompoundTagHandle::PutEnd(String^ key)
    {
        NativePtr->putEnd(marshalString(key));
    }

    inline double^ CompoundTagHandle::PutDouble(String^ key, double val)
    {
        return NativePtr->putDouble(marshalString(key), val);
    }

    inline void CompoundTagHandle::PutByteArray(String^ key, array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        NativePtr->putByteArray(marshalString(key), (char*)p_ptr, data->Length);
    }

    inline void CompoundTagHandle::PutIntArray(String^ key, array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        NativePtr->putIntArray(marshalString(key), (int*)p_ptr, data->Length);
    }

    inline TagMemoryChunkHandle^ CompoundTagHandle::PutIntArray(String^ key, TagMemoryChunkHandle^ val)
    {
        return gcnew TagMemoryChunkHandle(
            &NativePtr->putIntArray(marshalString(key), *val->NativePtr));
    }

    // get value
    inline double CompoundTagHandle::GetDouble(String^ key)
    {
        return NativePtr->getDouble(marshalString(key));
    }

    inline TagMemoryChunkHandle const^ CompoundTagHandle::GetIntArray(String^ key)
    {
        return gcnew TagMemoryChunkHandle(const_cast<::TagMemoryChunk*>(&NativePtr->getIntArray(marshalString(key))));
    }

    // get tag
    inline IntTagHandle const^ CompoundTagHandle::GetIntTag(String^ key)
    {
        return gcnew IntTagHandle((::IntTag*)NativePtr->getIntTag(marshalString(key)));
    }
    inline Int64TagHandle const^ CompoundTagHandle::GetInt64Tag(String^ key)
    {
        return gcnew Int64TagHandle((::Int64Tag*)NativePtr->getInt64Tag(marshalString(key)));
    }
    inline ByteTagHandle const^ CompoundTagHandle::GetByteTag(String^ key)
    {
        return gcnew ByteTagHandle((::ByteTag*)NativePtr->getByteTag(marshalString(key)));
    }
    inline ShortTagHandle const^ CompoundTagHandle::GetShortTag(String^ key)
    {
        return gcnew ShortTagHandle((::ShortTag*)NativePtr->getShortTag(marshalString(key)));
    }
    inline FloatTagHandle const^ CompoundTagHandle::GetFloatTag(String^ key)
    {
        return gcnew FloatTagHandle((::FloatTag*)NativePtr->getFloatTag(marshalString(key)));
    }
    inline DoubleTagHandle const^ CompoundTagHandle::GetDoubleTag(String^ key)
    {
        return gcnew DoubleTagHandle((::DoubleTag*)NativePtr->getDoubleTag(marshalString(key)));
    }
    inline ByteArrayTagHandle const^ CompoundTagHandle::GetByteArrayTag(String^ key)
    {
        return gcnew ByteArrayTagHandle((::ByteArrayTag*)NativePtr->getByteArrayTag(marshalString(key)));
    }
    inline StringTagHandle const^ CompoundTagHandle::GetStringTag(String^ key)
    {
        return gcnew StringTagHandle((::StringTag*)NativePtr->getStringTag(marshalString(key)));
    }
    inline IntArrayTagHandle const^ CompoundTagHandle::GetIntArrayTag(String^ key)
    {
        return gcnew IntArrayTagHandle((::IntArrayTag*)NativePtr->getIntArrayTag(marshalString(key)));
    }
    inline ListTagHandle const^ CompoundTagHandle::GetListTag(String^ key)
    {
        return gcnew ListTagHandle((::ListTag*)NativePtr->getListTag(marshalString(key)));
    }
    inline CompoundTagHandle^ CompoundTagHandle::GetCompoundTag(String^ key)
    {
        return gcnew CompoundTagHandle((::CompoundTag*)NativePtr->getCompoundTag(marshalString(key)));
    }

    // io
    inline void CompoundTagHandle::SetItemStack(ItemStackHandle^ item)
    {
        NativePtr->setItemStack(item->NativePtr);
    }

    inline void CompoundTagHandle::SetBlock(BlockHandle^ block)
    {
        NativePtr->setBlock(block);
    }

    inline bool CompoundTagHandle::SetActor(ActorHandle^ actor)
    {
        return NativePtr->setActor(actor);
    }

    inline bool CompoundTagHandle::SetBlockActor(BlockActorHandle^ ble)
    {
        return NativePtr->setBlockActor(ble);
    }

    inline bool CompoundTagHandle::SetPlayer(PlayerHandle^ player)
    {
        return NativePtr->setPlayer(player->NativePtr);
    }

    inline CompoundTagHandle^ CompoundTagHandle::FromItemStack(ItemStackHandle^ item)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromItemStack(item->NativePtr).release(), true);
    }

    inline CompoundTagHandle^ CompoundTagHandle::FromBlock(BlockHandle^ block)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBlock(block).release(), true);
    }

    inline CompoundTagHandle^ CompoundTagHandle::FromActor(ActorHandle^ actor)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromActor(actor).release(), true);
    }

    inline CompoundTagHandle^ CompoundTagHandle::FromBlockActor(BlockActorHandle^ blockActor)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBlockActor(blockActor).release(), true);
    }

    inline CompoundTagHandle^ CompoundTagHandle::FromPlayer(PlayerHandle^ player)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromPlayer(player->NativePtr).release(), true);
    }

    inline String^ CompoundTagHandle::ToSNBT()
    {
        return marshalString(NativePtr->toSNBT());
    }
    inline String^ CompoundTagHandle::ToBinaryNBT(bool isLittleEndian)
    {
        return marshalString(NativePtr->toBinaryNBT(isLittleEndian));
    }
    inline String^ CompoundTagHandle::ToBinaryNBT()
    {
        return marshalString(NativePtr->toBinaryNBT());
    }
    inline CompoundTagHandle^ CompoundTagHandle::FromSNBT(String^ snbt)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromSNBT(marshalString(snbt)).release(), true);
    }
    inline CompoundTagHandle^ CompoundTagHandle::FromBinaryNBT(void* data, size_t len, bool isLittleEndian)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBinaryNBT(data, len, isLittleEndian).release(), true);
    }
    inline CompoundTagHandle^ CompoundTagHandle::FromBinaryNBT(void* data, size_t len)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBinaryNBT(data, len).release(), true);
    }
    inline CompoundTagHandle^ CompoundTagHandle::FromBinaryNBT(void* data, size_t len, size_t& endOffset, bool isLittleEndian)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBinaryNBT(data, len, endOffset, isLittleEndian).release(), true);
    }
    inline CompoundTagHandle^ CompoundTagHandle::FromBinaryNBT(void* data, size_t len, size_t& endOffset)
    {
        return gcnew CompoundTagHandle(::CompoundTag::fromBinaryNBT(data, len, endOffset).release(), true);
    }

} // namespace BedrockServer::Extension::Handle


#ifdef INCLUDE_MCAPI

#include <memory>

void BedrockServer::Extension::Handle::CompoundTag::DeleteChildren()
{
    ((class ::CompoundTag*)NativePtr)->deleteChildren();
}

::String^ BedrockServer::Extension::Handle::CompoundTag::ToString()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->toString();
    return clix::marshalString<clix::E_UTF8>(__ret);
}

BedrockServer::Extension::Handle::Tag::Type BedrockServer::Extension::Handle::CompoundTag::GetId()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->getId();
    return (BedrockServer::Extension::Handle::Tag::Type)__ret;
}

bool BedrockServer::Extension::Handle::CompoundTag::Equals(BedrockServer::Extension::Handle::Tag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::Tag*)_0->NativePtr;
    auto __ret = ((class ::CompoundTag*)NativePtr)->equals(__arg0);
    return __ret;
}

unsigned long long BedrockServer::Extension::Handle::CompoundTag::hash()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->hash();
    return __ret;
}

void BedrockServer::Extension::Handle::CompoundTag::Append(BedrockServer::Extension::Handle::CompoundTag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::CompoundTag*)_0->NativePtr;
    ((class ::CompoundTag*)NativePtr)->append(__arg0);
}

void BedrockServer::Extension::Handle::CompoundTag::Clear()
{
    ((class ::CompoundTag*)NativePtr)->clear();
}

bool BedrockServer::Extension::Handle::CompoundTag::Contains(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->contains(__arg0);
    return __ret;
}

bool BedrockServer::Extension::Handle::CompoundTag::Contains(::String^ _0, BedrockServer::Extension::Handle::Tag::Type _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = (enum ::Tag::Type)_1;
    auto __ret = ((class ::CompoundTag*)NativePtr)->contains(__arg0, __arg1);
    return __ret;
}

void BedrockServer::Extension::Handle::CompoundTag::DeepCopy(BedrockServer::Extension::Handle::CompoundTag^ _0)
{
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(class ::CompoundTag*)_0->NativePtr;
    ((class ::CompoundTag*)NativePtr)->deepCopy(__arg0);
}

BedrockServer::Extension::Handle::Tag^ BedrockServer::Extension::Handle::CompoundTag::Get(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->get(__arg0);
    if (__ret == nullptr) return nullptr;
    return (__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::Tag((class ::Tag*)__ret);
}

bool BedrockServer::Extension::Handle::CompoundTag::GetBoolean(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getBoolean(__arg0);
    return __ret;
}

unsigned char BedrockServer::Extension::Handle::CompoundTag::GetByte(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getByte(__arg0);
    return __ret;
}

BedrockServer::Extension::Handle::CompoundTag^ BedrockServer::Extension::Handle::CompoundTag::GetCompound(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getCompound(__arg0);
    if (__ret == nullptr) return nullptr;
    return (__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::CompoundTag((class ::CompoundTag*)__ret);
}

float BedrockServer::Extension::Handle::CompoundTag::GetFloat(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getFloat(__arg0);
    return __ret;
}

int BedrockServer::Extension::Handle::CompoundTag::GetInt(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getInt(__arg0);
    return __ret;
}

long long BedrockServer::Extension::Handle::CompoundTag::GetInt64(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getInt64(__arg0);
    return __ret;
}

short BedrockServer::Extension::Handle::CompoundTag::GetShort(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->getShort(__arg0);
    return __ret;
}

::String^ BedrockServer::Extension::Handle::CompoundTag::GetString(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->getString(__arg0);
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

BedrockServer::Extension::Handle::Tag^ BedrockServer::Extension::Handle::CompoundTag::Put(::String^ _0, BedrockServer::Extension::Handle::Tag^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    if (ReferenceEquals(_1, nullptr))
        throw gcnew ::System::ArgumentNullException("_1", "Cannot be null because it is a C++ reference (&).");
    auto& __arg1 = *(class ::Tag*)_1->NativePtr;
    auto& __ret = ((class ::CompoundTag*)NativePtr)->put(__arg0, std::move(__arg1));
    return (BedrockServer::Extension::Handle::Tag^)((&__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::Tag((class ::Tag*) & __ret));
}

void BedrockServer::Extension::Handle::CompoundTag::PutBoolean(::String^ _0, bool _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    ((class ::CompoundTag*)NativePtr)->putBoolean(__arg0, _1);
}

unsigned char BedrockServer::Extension::Handle::CompoundTag::PutByte(::String^ _0, unsigned char _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putByte(__arg0, _1);
    return (unsigned char)(__ret);
}

BedrockServer::Extension::Handle::CompoundTag^ BedrockServer::Extension::Handle::CompoundTag::PutCompound(::String^ _0, BedrockServer::Extension::Handle::CompoundTag^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    if (ReferenceEquals(_1, nullptr))
        throw gcnew ::System::ArgumentNullException("_1", "Cannot be null because it is passed by value.");
    auto __ret = ((class ::CompoundTag*)NativePtr)->putCompound(__arg0, std::unique_ptr<::CompoundTag>((::CompoundTag*)_1->Release()));
    return __ret == nullptr ? nullptr : gcnew ::BedrockServer::Extension::Handle::CompoundTag(__ret);
}

float BedrockServer::Extension::Handle::CompoundTag::PutFloat(::String^ _0, float _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putFloat(__arg0, _1);
    return (float)(__ret);
}

int BedrockServer::Extension::Handle::CompoundTag::PutInt(::String^ _0, int _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putInt(__arg0, _1);
    return (int)(__ret);
}

long long BedrockServer::Extension::Handle::CompoundTag::PutInt64(::String^ _0, long long _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putInt64(__arg0, _1);
    return (long long)(__ret);
}

short BedrockServer::Extension::Handle::CompoundTag::PutShort(::String^ _0, short _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putShort(__arg0, _1);
    return (short)(__ret);
}

::String^ BedrockServer::Extension::Handle::CompoundTag::PutString(::String^ _0, ::String^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = clix::marshalString<clix::E_UTF8>(_1);
    auto& __ret = ((class ::CompoundTag*)NativePtr)->putString(__arg0, __arg1);
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

bool BedrockServer::Extension::Handle::CompoundTag::Remove(::String^ _0)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __ret = ((class ::CompoundTag*)NativePtr)->remove(__arg0);
    return __ret;
}

void BedrockServer::Extension::Handle::CompoundTag::Rename(::String^ _0, ::String^ _1)
{
    auto __arg0 = clix::marshalString<clix::E_UTF8>(_0);
    auto __arg1 = clix::marshalString<clix::E_UTF8>(_1);
    ((class ::CompoundTag*)NativePtr)->rename(__arg0, __arg1);
}

bool BedrockServer::Extension::Handle::CompoundTag::IsEmpty::get()
{
    auto __ret = ((class ::CompoundTag*)NativePtr)->isEmpty();
    return __ret;
}
#endif // INCLUDE_MCAPI
