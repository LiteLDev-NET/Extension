#pragma once
#include "Tag.hpp"
#include "TagMemoryChunk.hpp"

#include <mc/ListTag.hpp>

namespace BedrockServer::Extension
{
    ref class Tag;
    ref struct TagMemoryChunk;
}

namespace BedrockServer::Extension
{

    public ref class ListTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(ListTag, ::ListTag, Tag)
    public:

        inline static ListTag^ Create();
        array<Tag^>^ Value();
        property Tag^ default[int] {
            Tag^ get(int index) {
                return gcnew Tag(((::Tag*)((*NativePtr)[index])));
            }
        };
        inline Tag::Type const GetElementType();
        inline size_t getSize();
        array<Tag^>^ Get();
        inline unsigned char GetByte(int i);
        inline short GetShort(int i);
        inline int64_t GetInt64(int i);
        inline TagMemoryChunk^ GetByteArray(int i);
        inline void AddEnd();
        inline void AddByte(unsigned char v);
        inline void AddShort(short v);
        inline void AddInt(int v);
        inline void AddInt64(__int64 v);
        inline void AddFloat(float v);
        inline void AddDouble(double v);
        inline void AddString(String^ v);
        inline void AddByteArray(TagMemoryChunk^ byteArr);
        inline void AddByteArray(array<char>^ data /*, size_t size*/);
        inline void AddIntArray(TagMemoryChunk^ intArr);
        inline void AddIntArray(array<int>^ data /*, size_t size*/);
    };

} // namespace BedrockServer::Extension
