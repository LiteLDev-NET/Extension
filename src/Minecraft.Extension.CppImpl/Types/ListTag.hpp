#pragma once
#include "Tag.hpp"
#include "TagMemoryChunk.hpp"

#include <mc/ListTag.hpp>

namespace BedrockServer::Extension::Handle
{
    ref class TagHandle;
    ref struct TagMemoryChunkHandle;
}

namespace BedrockServer::Extension::Handle
{

    public ref class ListTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(ListTagHandle, ::ListTag, TagHandle)
    public:

        inline static ListTagHandle^ Create();
        array<TagHandle^>^ Value();
        property TagHandle^ default[int] {
            TagHandle^ get(int index) {
                return gcnew TagHandle(((::Tag*)((*NativePtr)[index])));
            }
        };
        inline TagHandle::Type const GetElementType();
        inline size_t getSize();
        array<TagHandle^>^ Get();
        inline unsigned char GetByte(int i);
        inline short GetShort(int i);
        inline int64_t GetInt64(int i);
        inline TagMemoryChunkHandle^ GetByteArray(int i);
        inline void AddEnd();
        inline void AddByte(unsigned char v);
        inline void AddShort(short v);
        inline void AddInt(int v);
        inline void AddInt64(__int64 v);
        inline void AddFloat(float v);
        inline void AddDouble(double v);
        inline void AddString(String^ v);
        inline void AddByteArray(TagMemoryChunkHandle^ byteArr);
        inline void AddByteArray(array<char>^ data /*, size_t size*/);
        inline void AddIntArray(TagMemoryChunkHandle^ intArr);
        inline void AddIntArray(array<int>^ data /*, size_t size*/);
    };

} // namespace BedrockServer::Extension::Handle
