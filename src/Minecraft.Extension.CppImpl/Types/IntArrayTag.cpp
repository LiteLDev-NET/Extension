#include "IntArrayTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline TagMemoryChunkHandle^ IntArrayTagHandle::Value()
    {
        return gcnew TagMemoryChunkHandle(&NativePtr->value());
    }
    inline IntArrayTagHandle^ IntArrayTagHandle::operator=(TagMemoryChunkHandle^ val)
    {
        *NativePtr = *val->NativePtr;
        return this;
    }
    inline IntArrayTagHandle^ IntArrayTagHandle::Create()
    {
        return gcnew IntArrayTagHandle(::IntArrayTag::create().release(), true);
    }
    inline IntArrayTagHandle^ IntArrayTagHandle::Create(TagMemoryChunkHandle^ val)
    {
        return gcnew IntArrayTagHandle(::IntArrayTag::create(*val->NativePtr).release(), true);
    }
    inline IntArrayTagHandle^ IntArrayTagHandle::Create(array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        return gcnew IntArrayTagHandle(::IntArrayTag::create(p_ptr, data->Length).release(), true);
    }
    inline bool IntArrayTagHandle::Set(TagMemoryChunkHandle^ val)
    {
        return NativePtr->set(*val->NativePtr);
    }
    inline TagMemoryChunkHandle^ IntArrayTagHandle::Get()
    {
        return gcnew TagMemoryChunkHandle(new ::TagMemoryChunk(NativePtr->get()), true);
    }
} // namespace BedrockServer::Extension::Handle
