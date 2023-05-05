#pragma once
#include <mc/SerializedSkin.hpp>
#include "Types.hpp"
#include "ReadOnlyBinaryStream.hpp"
#include "BinaryStream.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class SerializedSkinHandle : SafeHandle, ICppClass
    {
    internal: SerializedSkinHandle(::SerializedSkin* ptr) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } SerializedSkinHandle(::SerializedSkin* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::SerializedSkin* () {
        return reinterpret_cast<::SerializedSkin*>((void*)NativePointer);
    } static operator SerializedSkinHandle ^ (::SerializedSkin* ptr) {
        return gcnew SerializedSkinHandle(ptr);
    } property ::SerializedSkin* NativePtr { ::SerializedSkin* get() {
        return reinterpret_cast<::SerializedSkin*>((void*)NativePointer);
    } void set(::SerializedSkin* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } SerializedSkinHandle(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = ptr; OwnsNativeInstance = OwnsNativeInstance;
    } virtual property nint_t NativePointer { nint_t get() {
        return handle;
    } void set(nint_t value) {
        handle = value;
    } }; virtual property bool OwnsNativeInstance; virtual void Destruct() {
        ReleaseHandle();
    } virtual size_t GetClassSize() {
        return classSize;
    } virtual bool ReleaseHandle() override {
        if (OwnsNativeInstance) __dtor<::SerializedSkin>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:
        SerializedSkinHandle();
        SerializedSkinHandle(SerializedSkinHandle^ skin);

        property String^ Name { String^ get(); }
        property bool IsTrustedSkin { bool get(); void set(bool value); }
        property bool UseBlinkingAnimation { bool get(); }

        void UpdateGeometryName();
        bool Read(ReadOnlyBinaryStreamHandle^ stream);
        void Write(BinaryStreamHandle^ stream);
    };
}
