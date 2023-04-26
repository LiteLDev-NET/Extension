#include "ListTag.hpp"
namespace BedrockServer::Extension
{
    inline ListTag^ ListTag::Create()
    {
        return gcnew ListTag(::ListTag::create().release(), true);
    }

    array<Tag^>^ ListTag::Value()
    {
        std::vector<::Tag*>& stdvector = NativePtr->value();
        auto len = int(stdvector.size());
        auto list = gcnew array<Tag^>(len);
        for (int i = 0; i < len; i++)
            list[i] = gcnew Tag(stdvector[i]);
        return list;
    }

    inline Tag::Type const ListTag::GetElementType()
    {
        return Tag::Type(NativePtr->getElementType());
    }

    inline size_t ListTag::getSize()
    {
        return NativePtr->getSize();
    }

    array<Tag^>^ ListTag::Get()
    {
        std::vector<::Tag*>& stdvector = NativePtr->get();
        auto len = int(stdvector.size());
        auto list = gcnew array<Tag^>(len);
        for (int i = 0; i < len; i++)
            list[i] = gcnew Tag(stdvector[i]);
        return list;
    }

    inline unsigned char ListTag::GetByte(int i)
    {
        return NativePtr->getByte(i);
    }

    inline short ListTag::GetShort(int i)
    {
        return NativePtr->getShort(i);
    }

    inline int64_t ListTag::GetInt64(int i)
    {
        return NativePtr->getInt64(i);
    }

    inline TagMemoryChunk^ ListTag::GetByteArray(int i)
    {
        return gcnew TagMemoryChunk(&NativePtr->getByteArray(i));
    }

    inline void ListTag::AddEnd()
    {
        NativePtr->addEnd();
    }
    inline void ListTag::AddByte(unsigned char v)
    {
        NativePtr->addByte(v);
    }
    inline void ListTag::AddShort(short v)
    {
        NativePtr->addShort(v);
    }
    inline void ListTag::AddInt(int v)
    {
        NativePtr->addInt(v);
    }
    inline void ListTag::AddInt64(__int64 v)
    {
        NativePtr->addInt64(v);
    }
    inline void ListTag::AddFloat(float v)
    {
        NativePtr->addFloat(v);
    }
    inline void ListTag::AddDouble(double v)
    {
        NativePtr->addDouble(v);
    }
    inline void ListTag::AddString(String^ v)
    {
        NativePtr->addString(marshalString(v));
    }
    inline void ListTag::AddByteArray(TagMemoryChunk^ byteArr)
    {
        NativePtr->addByteArray(*byteArr->NativePtr);
    }
    inline void ListTag::AddByteArray(array<char>^ data /*, size_t size*/)
    {
        pin_ptr<char> p_ptr = &data[0];
        NativePtr->addByteArray((char*)p_ptr, data->Length);
    }
    inline void ListTag::AddIntArray(TagMemoryChunk^ intArr)
    {
        NativePtr->addByteArray(*intArr->NativePtr);
    }
    inline void ListTag::AddIntArray(array<int>^ data /*, size_t size*/)
    {
        pin_ptr<int> p_ptr = &data[0];
        NativePtr->addIntArray((int*)p_ptr, data->Length);
    }
} // namespace BedrockServer::Extension
