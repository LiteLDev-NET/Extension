#include "ReadOnlyBinaryStream.hpp"

namespace BedrockServer::Extension::Handle
{
    inline void ReadOnlyBinaryStreamHandle::Read(void* buffer, unsigned __int64 size) { NativePtr->read(buffer, size); }

    inline void ReadOnlyBinaryStreamHandle::Read(array<System::Byte>^ buffer)
    {
        pin_ptr<System::Byte> p = &buffer[0];
        NativePtr->read(p, buffer->Length);
    }

    inline ReadOnlyBinaryStreamHandle::ReadOnlyBinaryStreamHandle(String^ str)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::ReadOnlyBinaryStream(marshalString(str));
        OwnsNativeInstance = true;
    }

    inline ReadOnlyBinaryStreamHandle::ReadOnlyBinaryStreamHandle(String^ str, bool b)
        :SafeHandle(nint_t::Zero, true)
    {
        NativePtr = new ::ReadOnlyBinaryStream(marshalString(str), b);
        OwnsNativeInstance = true;
    }

    inline bool ReadOnlyBinaryStreamHandle::CanReadBool() { return NativePtr->canReadBool(); }

    inline bool ReadOnlyBinaryStreamHandle::GetBool() { return NativePtr->getBool(); }

    inline System::Byte ReadOnlyBinaryStreamHandle::GetByte() { return NativePtr->getByte(); }

    inline double ReadOnlyBinaryStreamHandle::GetDouble() { return NativePtr->getDouble(); }

    inline float ReadOnlyBinaryStreamHandle::GetFloat() { return NativePtr->getFloat(); }

    inline StreamReadResult ReadOnlyBinaryStreamHandle::GetReadCompleteResult()
    {
        return static_cast<StreamReadResult>(NativePtr->getReadCompleteResult());
    }

    inline int ReadOnlyBinaryStreamHandle::GetSignedBigEndianInt() { return NativePtr->getSignedBigEndianInt(); }

    inline int ReadOnlyBinaryStreamHandle::GetSignedInt() { return NativePtr->getSignedInt(); }

    inline __int64 ReadOnlyBinaryStreamHandle::GetSignedInt64() { return NativePtr->getSignedInt64(); }

    inline short ReadOnlyBinaryStreamHandle::GetSignedShort() { return NativePtr->getSignedShort(); }

    inline String^ ReadOnlyBinaryStreamHandle::GetString() { return marshalString(NativePtr->getString()); }

    inline bool ReadOnlyBinaryStreamHandle::GetString([Out] String^% str)
    {
        str = nullptr;
        std::string __str;
        auto ret = NativePtr->getString(__str);
        if (!ret)
            return false;
        str = marshalString(__str);
        return true;
    }

    inline unsigned int ReadOnlyBinaryStreamHandle::GetUnsignedInt() { return NativePtr->getUnsignedInt(); }

    inline unsigned __int64 ReadOnlyBinaryStreamHandle::GetUnsignedInt64() { return NativePtr->getUnsignedInt64(); }

    inline unsigned short ReadOnlyBinaryStreamHandle::GetUnsignedShort() { return NativePtr->getUnsignedShort(); }

    inline unsigned int ReadOnlyBinaryStreamHandle::GetUnsignedVarInt() { return NativePtr->getUnsignedVarInt(); }

    inline unsigned __int64 ReadOnlyBinaryStreamHandle::GetUnsignedVarInt64() { return NativePtr->getUnsignedVarInt64(); }

    inline int ReadOnlyBinaryStreamHandle::GetVarInt() { return NativePtr->getVarInt(); }

    inline __int64 ReadOnlyBinaryStreamHandle::GetVarInt64() { return NativePtr->getVarInt64(); }

    Mce::UUID ReadOnlyBinaryStreamHandle::GetUUID()
    {
        mce::UUID uuid;
        NativePtr->readType(uuid);
        return *(Mce::UUID*)&uuid;
    }

    /*Vec3 ReadOnlyBinaryStream::GetVec3()
    {
        ::Vec3 vec3;
        NativePtr->readType(vec3);
        return vec3;
    }*/
}
