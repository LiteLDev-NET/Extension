#pragma once

#include "ReadOnlyBinaryStream.hpp"
#include <mc/BinaryStream.hpp>

namespace BedrockServer::Extension
{
    public ref class BinaryStream : ReadOnlyBinaryStream
    {
    internal: BinaryStream(::BinaryStream* ptr) :ReadOnlyBinaryStream(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } BinaryStream(::BinaryStream* ptr, bool ownsinstance) :ReadOnlyBinaryStream(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::BinaryStream* () {
        return reinterpret_cast<::BinaryStream*>((void*)NativePointer);
    } static operator BinaryStream ^ (::BinaryStream* ptr) {
        return gcnew BinaryStream(ptr);
    } property ::BinaryStream* NativePtr { ::BinaryStream* get() {
        return reinterpret_cast<::BinaryStream*>((void*)NativePointer);
    } void set(::BinaryStream* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } BinaryStream(nint_t ptr, bool ownInstance) :ReadOnlyBinaryStream(nint_t::Zero, true) {
        NativePointer = ptr; OwnsNativeInstance = OwnsNativeInstance;
    } virtual void Destruct() override {
        ReleaseHandle();
    } virtual size_t GetClassSize() override {
        return classSize;
    } virtual bool ReleaseHandle() override {
        if (OwnsNativeInstance) __dtor<::BinaryStream>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:

        property String^ WriteBuf
        {
            String^ get() { return marshalString(NativePtr->writeBuf); }

            void set(String^ value)
            {
                NativePtr->writeBuf = marshalString(value);
            }
        }
        property ref_std_string^ WBuf
        {
            ref_std_string^ get() { return gcnew ref_std_string(nint_t(NativePtr->pwBuf), false); }

            void set(ref_std_string^ value)
            {
                *NativePtr->pwBuf = *reinterpret_cast<std::string*>((void*)(gcnew ref_std_string(value))->NativePointer);
            }
        }

        BinaryStream(String^ str, bool b);
        BinaryStream();
        String^ GetAndReleaseData();
        ref_std_string^ GetAndReleaseData_Native();
        void Reset();
        void WriteBool(bool val);
        void WriteByte(System::Byte val);
        void WriteDouble(double val);
        void WriteFloat(float val);
        void WriteSignedBigEndianInt(int val);
        void WriteSignedInt(int val);
        void WriteSignedInt64(__int64 val);
        void WriteSignedShort(short val);
        void WriteString(String^ val);
        void WriteUnsignedInt(unsigned int val);
        void WriteUnsignedInt64(unsigned __int64 val);
        void WriteUnsignedShort(unsigned short val);
        void WriteUnsignedVarInt(unsigned int val);
        void WriteUnsignedVarInt64(unsigned __int64 val);
        void WriteVarInt(int val);
        void WriteVarInt64(__int64 val);
        void WriteUUID(Mce::UUID uuid);
        void WriteVec3(Vec3 vec3);

        void Write(const void* p, unsigned __int64 size);
        void Write(array<System::Byte>^ arr);
    };
}
