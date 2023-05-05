#include "TagMemoryChunk.hpp"
namespace BedrockServer::Extension::Handle
{
    size_t TagMemoryChunkHandle::Capacity::get()
    {
        return NativePtr->capacity;
    }
    void TagMemoryChunkHandle::Capacity::set(size_t val)
    {
        NativePtr->capacity = val;
    }
    size_t TagMemoryChunkHandle::Size::get()
    {
        return NativePtr->size;
    }
    void TagMemoryChunkHandle::Size::set(size_t val)
    {
        NativePtr->size = val;
    }

    inline size_t TagMemoryChunkHandle::Data::Size()
    {
        return size;
    }
    inline std::unique_ptr<char[]>* TagMemoryChunkHandle::Data::get()
    {
        return u_ptr;
    }
    inline TagMemoryChunkHandle::Data::Data(std::unique_ptr<char[]>& p, size_t len)
        : size(len)
    {
        u_ptr = new std::unique_ptr<char[]>(std::move(p));
    }
    inline TagMemoryChunkHandle::Data::~Data()
    {
        delete u_ptr;
    }
    inline char^ TagMemoryChunkHandle::Data::operator[](int index)
    {
        if (index < size)
            return (*u_ptr)[index];
        else
            throw gcnew System::IndexOutOfRangeException;
    }


    TagMemoryChunkHandle::Data^ TagMemoryChunkHandle::data::get()
    {
        return gcnew Data(NativePtr->data, NativePtr->size);
    }
    void TagMemoryChunkHandle::data::set(Data^ d)
    {
        NativePtr->data = std::move(*d->get());
        Size = d->Size();
    }

    TagMemoryChunkHandle^ TagMemoryChunkHandle::Create(array<char>^ data)
    {
        pin_ptr<char> p_ptr = &data[0];
        return gcnew TagMemoryChunkHandle(new ::TagMemoryChunk(p_ptr, data->Length), true);
    }

    TagMemoryChunkHandle^ TagMemoryChunkHandle::Create(TagMemoryChunkHandle^ a1)
    {
        return gcnew TagMemoryChunkHandle(new ::TagMemoryChunk(*a1->NativePtr), true);
    }

    inline void TagMemoryChunkHandle::operator=(TagMemoryChunkHandle^ a1)
    {
        *NativePtr = *a1->NativePtr;
    }
} // namespace BedrockServer::Extension::Handle

bool BedrockServer::Extension::Handle::TagMemoryChunkHandle::operator!=(BedrockServer::Extension::Handle::TagMemoryChunkHandle^ __op, BedrockServer::Extension::Handle::TagMemoryChunkHandle^ _0)
{
    bool __opNull = ReferenceEquals(__op, nullptr);
    bool _0Null = ReferenceEquals(_0, nullptr);
    if (__opNull || _0Null)
        return !(__opNull && _0Null);
    auto& __arg0 = *(struct ::TagMemoryChunk*)__op->NativePtr;
    auto& __arg1 = *(struct ::TagMemoryChunk*)_0->NativePtr;
    auto __ret = __arg0 != __arg1;
    return __ret;
}

BedrockServer::Extension::Handle::TagMemoryChunkHandle^ BedrockServer::Extension::Handle::TagMemoryChunkHandle::Copy::get()
{
    auto __ret = ((struct ::TagMemoryChunk*)NativePtr)->copy();
    auto ____ret = new struct ::TagMemoryChunk(__ret);
    return (____ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::TagMemoryChunkHandle((struct ::TagMemoryChunk*)____ret, true);
}