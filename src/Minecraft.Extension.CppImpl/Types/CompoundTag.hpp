#pragma once

#include "CompoundTagVariant.hpp"
#include "ByteArrayTag.hpp"
#include "ByteTag.hpp"
#include "DoubleTag.hpp"
#include "EndTag.hpp"
#include "ShortTag.hpp"
#include "FloatTag.hpp"
#include "StringTag.hpp"
#include "IntArrayTag.hpp"
#include "ListTag.hpp"

#include <mc/CompoundTag.hpp>

using System::Collections::Generic::Dictionary;

namespace BedrockServer::Extension::Handle
{
    ref class ActorHandle;
    ref class PlayerHandle;
    ref class ItemStackHandle;
    ref class BlockHandle;
    ref class BlockActorHandle;
    ref class ItemStackHandle;
    ref class CompoundTagVariantHandle;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class CompoundTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(CompoundTagHandle, ::CompoundTag, TagHandle)
    public:

        inline static CompoundTagHandle^ Create();
        inline Dictionary<String^, CompoundTagVariantHandle^>^ Value();
        // put value
        inline void PutEnd(String^ key);
        inline double^ PutDouble(String^ key, double val);
        inline void PutByteArray(String^ key, array<char>^ data /*, size_t size*/);
        inline void PutIntArray(String^ key, array<int>^ data /*, size_t size*/);
        inline TagMemoryChunkHandle^ PutIntArray(String^ key, TagMemoryChunkHandle^ val);
        // get value
        inline double GetDouble(String^ key);
        inline TagMemoryChunkHandle const^ GetIntArray(String^ key);
        // get tag
        inline ByteTagHandle const^ GetByteTag(String^ key);
        inline IntTagHandle const^ GetIntTag(String^ key);
        inline Int64TagHandle const^ GetInt64Tag(String^ key);
        inline ShortTagHandle const^ GetShortTag(String^ key);
        inline FloatTagHandle const^ GetFloatTag(String^ key);
        inline DoubleTagHandle const^ GetDoubleTag(String^ key);
        inline ByteArrayTagHandle const^ GetByteArrayTag(String^ key);
        inline StringTagHandle const^ GetStringTag(String^ key);
        inline IntArrayTagHandle const^ GetIntArrayTag(String^ key);
        inline ListTagHandle const^ GetListTag(String^ key);
        inline CompoundTagHandle^ GetCompoundTag(String^ key);
        property TagHandle^ default[String^] {
            TagHandle^ get(String ^ key) {
                return gcnew TagHandle(((::Tag*)((*NativePtr)[marshalString(key)])));
            }
        };
        // io
        inline void SetItemStack(ItemStackHandle^ item);
        inline void SetBlock(BlockHandle^ blk);
        inline bool SetActor(ActorHandle^ actor);
        inline bool SetBlockActor(BlockActorHandle^ ble);
        inline bool SetPlayer(PlayerHandle^ player);
        inline static CompoundTagHandle^ FromItemStack(ItemStackHandle^ item);
        inline static CompoundTagHandle^ FromBlock(BlockHandle^ blk);
        inline static CompoundTagHandle^ FromActor(ActorHandle^ actor);
        inline static CompoundTagHandle^ FromBlockActor(BlockActorHandle^ ble);
        inline static CompoundTagHandle^ FromPlayer(PlayerHandle^ player);
        inline String^ ToSNBT();
        inline String^ ToBinaryNBT(bool isLittleEndian);
        inline String^ ToBinaryNBT();
        inline static CompoundTagHandle^ FromSNBT(String^ snbt);
        inline static CompoundTagHandle^ FromBinaryNBT(void* data, size_t len, bool isLittleEndian);
        inline static CompoundTagHandle^ FromBinaryNBT(void* data, size_t len);
        inline static CompoundTagHandle^ FromBinaryNBT(void* data, size_t len, size_t& endOffset, bool isLittleEndian);
        inline static CompoundTagHandle^ FromBinaryNBT(void* data, size_t len, size_t& endOffset);


#ifdef INCLUDE_MCAPI

        property bool IsEmpty
        {
            bool get();
        }

        virtual void DeleteChildren() override;

        virtual ::String^ ToString() override;

        virtual BedrockServer::Extension::Handle::Tag::Type GetId();

        virtual bool Equals(BedrockServer::Extension::Handle::Tag^ _0) override;

        virtual unsigned long long hash();

        void Append(BedrockServer::Extension::Handle::CompoundTag^ _0);

        void Clear();

        bool Contains(::String^ _0);

        bool Contains(::String^ _0, BedrockServer::Extension::Handle::Tag::Type _1);

        void DeepCopy(BedrockServer::Extension::Handle::CompoundTag^ _0);

        BedrockServer::Extension::Handle::Tag^ Get(::String^ _0);

        bool GetBoolean(::String^ _0);

        unsigned char GetByte(::String^ _0);

        BedrockServer::Extension::Handle::CompoundTag^ GetCompound(::String^ _0);

        float GetFloat(::String^ _0);

        int GetInt(::String^ _0);

        long long GetInt64(::String^ _0);

        short GetShort(::String^ _0);

        ::String^ GetString(::String^ _0);

        BedrockServer::Extension::Handle::Tag^ Put(::String^ _0, BedrockServer::Extension::Handle::Tag^ _1);

        void PutBoolean(::String^ _0, bool _1);

        unsigned char PutByte(::String^ _0, unsigned char _1);

        BedrockServer::Extension::Handle::CompoundTag^ PutCompound(::String^ _0, BedrockServer::Extension::Handle::CompoundTag^ _1);

        float PutFloat(::String^ _0, float _1);

        int PutInt(::String^ _0, int _1);

        long long PutInt64(::String^ _0, long long _1);

        short PutShort(::String^ _0, short _1);

        ::String^ PutString(::String^ _0, ::String^ _1);

        bool Remove(::String^ _0);

        void Rename(::String^ _0, ::String^ _1);

#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension::Handle
