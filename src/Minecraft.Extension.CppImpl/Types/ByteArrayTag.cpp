#include "ByteArrayTag.hpp"
#include "TagMemoryChunk.hpp"
namespace BedrockServer::Extension::Handle
{

    inline TagMemoryChunkHandle^ ByteArrayTagHandle::Value()
    {
        return gcnew TagMemoryChunkHandle(&NativePtr->value());
    }

    inline ByteArrayTagHandle^ ByteArrayTagHandle::operator=(TagMemoryChunkHandle^ val)
    {
        *NativePtr = *val->NativePtr;
        return this;
    }

    inline ByteArrayTagHandle^ ByteArrayTagHandle::Create()
    {
        return gcnew ByteArrayTagHandle(::ByteArrayTag::create().release(), true);
    }

    inline ByteArrayTagHandle^ ByteArrayTagHandle::Create(TagMemoryChunkHandle^ val)
    {
        return gcnew ByteArrayTagHandle(::ByteArrayTag::create(*val->NativePtr).release(), true);
    }

    inline ByteArrayTagHandle^ ByteArrayTagHandle::Create(array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        return gcnew ByteArrayTagHandle(::ByteArrayTag::create((char*)p_ptr, data->Length).release(), true);
    }

    inline bool ByteArrayTagHandle::Set(TagMemoryChunkHandle^ val)
    {
        return NativePtr->set(*val->NativePtr);
    }

    inline TagMemoryChunkHandle^ ByteArrayTagHandle::Get()
    {
        return gcnew TagMemoryChunkHandle(new ::TagMemoryChunk(NativePtr->get()), true);
    }
} // namespace BedrockServer::Extension::Handle