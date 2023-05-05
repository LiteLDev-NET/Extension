#include "ListTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline ListTagHandle^ ListTagHandle::Create()
    {
        return gcnew ListTagHandle(::ListTag::create().release(), true);
    }

    array<TagHandle^>^ ListTagHandle::Value()
    {
        std::vector<::Tag*>& stdvector = NativePtr->value();
        auto len = int(stdvector.size());
        auto list = gcnew array<TagHandle^>(len);
        for (int i = 0; i < len; i++)
            list[i] = gcnew TagHandle(stdvector[i]);
        return list;
    }

    inline TagHandle::Type const ListTagHandle::GetElementType()
    {
        return TagHandle::Type(NativePtr->getElementType());
    }

    inline size_t ListTagHandle::getSize()
    {
        return NativePtr->getSize();
    }

    array<TagHandle^>^ ListTagHandle::Get()
    {
        std::vector<::Tag*>& stdvector = NativePtr->get();
        auto len = int(stdvector.size());
        auto list = gcnew array<TagHandle^>(len);
        for (int i = 0; i < len; i++)
            list[i] = gcnew TagHandle(stdvector[i]);
        return list;
    }

    inline unsigned char ListTagHandle::GetByte(int i)
    {
        return NativePtr->getByte(i);
    }

    inline short ListTagHandle::GetShort(int i)
    {
        return NativePtr->getShort(i);
    }

    inline int64_t ListTagHandle::GetInt64(int i)
    {
        return NativePtr->getInt64(i);
    }

    inline TagMemoryChunkHandle^ ListTagHandle::GetByteArray(int i)
    {
        return gcnew TagMemoryChunkHandle(&NativePtr->getByteArray(i));
    }

    inline void ListTagHandle::AddEnd()
    {
        NativePtr->addEnd();
    }
    inline void ListTagHandle::AddByte(unsigned char v)
    {
        NativePtr->addByte(v);
    }
    inline void ListTagHandle::AddShort(short v)
    {
        NativePtr->addShort(v);
    }
    inline void ListTagHandle::AddInt(int v)
    {
        NativePtr->addInt(v);
    }
    inline void ListTagHandle::AddInt64(__int64 v)
    {
        NativePtr->addInt64(v);
    }
    inline void ListTagHandle::AddFloat(float v)
    {
        NativePtr->addFloat(v);
    }
    inline void ListTagHandle::AddDouble(double v)
    {
        NativePtr->addDouble(v);
    }
    inline void ListTagHandle::AddString(String^ v)
    {
        NativePtr->addString(marshalString(v));
    }
    inline void ListTagHandle::AddByteArray(TagMemoryChunkHandle^ byteArr)
    {
        NativePtr->addByteArray(*byteArr->NativePtr);
    }
    inline void ListTagHandle::AddByteArray(array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        NativePtr->addByteArray((char*)p_ptr, data->Length);
    }
    inline void ListTagHandle::AddIntArray(TagMemoryChunkHandle^ intArr)
    {
        NativePtr->addByteArray(*intArr->NativePtr);
    }
    inline void ListTagHandle::AddIntArray(array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        NativePtr->addIntArray((int*)p_ptr, data->Length);
    }
} // namespace BedrockServer::Extension::Handle
