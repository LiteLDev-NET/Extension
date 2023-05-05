#pragma once
#include "BinaryStream.hpp"

namespace BedrockServer::Extension::Handle
{
    inline BinaryStreamHandle::BinaryStreamHandle(String^ str, bool b)
        : ReadOnlyBinaryStreamHandle(nint_t(static_cast<void*>(nullptr)), false)
    {
        NativePtr = new ::BinaryStream(marshalString(str), b);
        OwnsNativeInstance = true;
    }

    inline BinaryStreamHandle::BinaryStreamHandle()
        : ReadOnlyBinaryStreamHandle(nint_t(static_cast<void*>(nullptr)), false)
    {
        NativePtr = new ::BinaryStream;
        OwnsNativeInstance = true;
    }

    inline String^ BinaryStreamHandle::GetAndReleaseData()
    {
        return marshalString(NativePtr->getAndReleaseData());
    }

    inline ref_std_string^ BinaryStreamHandle::GetAndReleaseData_Native()
    {
        return gcnew ref_std_string(nint_t(new std::string(NativePtr->getAndReleaseData())), true);
    }

    inline void BinaryStreamHandle::Reset()
    {
        NativePtr->reset();
    }

    inline void BinaryStreamHandle::WriteBool(bool val)
    {
        NativePtr->writeBool(val);
    }

    inline void BinaryStreamHandle::WriteByte(System::Byte val)
    {
        NativePtr->writeByte(val);
    }

    inline void BinaryStreamHandle::WriteDouble(double val)
    {
        NativePtr->writeDouble(val);
    }

    inline void BinaryStreamHandle::WriteFloat(float val)
    {
        NativePtr->writeFloat(val);
    }

    inline void BinaryStreamHandle::WriteSignedBigEndianInt(int val)
    {
        NativePtr->writeSignedBigEndianInt(val);
    }

    inline void BinaryStreamHandle::WriteSignedInt(int val)
    {
        NativePtr->writeSignedInt(val);
    }

    inline void BinaryStreamHandle::WriteSignedInt64(__int64 val)
    {
        NativePtr->writeSignedInt64(val);
    }

    inline void BinaryStreamHandle::WriteSignedShort(short val)
    {
        NativePtr->writeSignedShort(val);
    }

    inline void BinaryStreamHandle::WriteString(String^ val)
    {
        NativePtr->writeString(marshalString(val));
    }

    inline void BinaryStreamHandle::WriteUnsignedInt(unsigned int val)
    {
        NativePtr->writeUnsignedInt(val);
    }

    inline void BinaryStreamHandle::WriteUnsignedInt64(unsigned __int64 val)
    {
        NativePtr->writeUnsignedInt64(val);
    }

    inline void BinaryStreamHandle::WriteUnsignedShort(unsigned short val)
    {
        NativePtr->writeUnsignedShort(val);
    }

    inline void BinaryStreamHandle::WriteUnsignedVarInt(unsigned int val)
    {
        NativePtr->writeUnsignedVarInt(val);
    }

    inline void BinaryStreamHandle::WriteUnsignedVarInt64(unsigned __int64 val)
    {
        NativePtr->writeUnsignedVarInt64(val);
    }

    inline void BinaryStreamHandle::WriteVarInt(int val)
    {
        NativePtr->writeVarInt(val);
    }

    inline void BinaryStreamHandle::WriteVarInt64(__int64 val)
    {
        NativePtr->writeVarInt64(val);
    }

    inline void BinaryStreamHandle::Write(const void* p, unsigned __int64 size)
    {
        NativePtr->write(p, size);
    }

    inline void BinaryStreamHandle::Write(array<System::Byte>^ arr)
    {
        pin_ptr<System::Byte> p = &arr[0];
        NativePtr->write(p, arr->Length);
    }

    void BinaryStreamHandle::WriteUUID(Mce::UUID uuid)
    {
        NativePtr->writeType(*(::mce::UUID*)&uuid);
    }

    void BinaryStreamHandle::WriteVec3(Vec3 vec3)
    {
        NativePtr->writeType(*(::mce::UUID*)&vec3);
    }
}
