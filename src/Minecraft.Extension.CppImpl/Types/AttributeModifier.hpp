#pragma once
#include <mc/AttributeModifier.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public enum class AttributeModifierOperation
    {
        Add,
        MultiplyBase,
        MultiplyTotal,
        Cap,
        Invalid
    };

    public enum class AttributeOperands
    {
        Min,
        Max,
        Current,
        Invalid
    };

    public ref class AttributeModifierHandle :SafeHandle, ICppClass
    {
    internal: AttributeModifierHandle(::AttributeModifier* ptr) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } AttributeModifierHandle(::AttributeModifier* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::AttributeModifier* () {
        return reinterpret_cast<::AttributeModifier*>((void*)NativePointer);
    } static operator AttributeModifierHandle ^ (::AttributeModifier* ptr) {
        return gcnew AttributeModifierHandle(ptr);
    } property ::AttributeModifier* NativePtr { ::AttributeModifier* get() {
        return reinterpret_cast<::AttributeModifier*>((void*)NativePointer);
    } void set(::AttributeModifier* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } AttributeModifierHandle(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {
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
        if (OwnsNativeInstance) __dtor<::AttributeModifier>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:

        AttributeModifierHandle();
        AttributeModifierHandle(Mce::UUID id, String^ name, float amount, AttributeModifierOperation operation,
            AttributeOperands operand, bool isSerializable);

        property Mce::UUID Id { Mce::UUID get(); void set(Mce::UUID value); }
        property String^ Name { String^ get(); void set(String^ value); }
        property float Amount { float get(); void set(float value); }
        property AttributeModifierOperation Operation
        {
            AttributeModifierOperation get(); void set(AttributeModifierOperation value);
        }
        property AttributeOperands Operand { AttributeOperands get(); void set(AttributeOperands value); }
        property bool IsSerializable { bool get(); void set(bool value); }

        virtual bool Equals(AttributeModifierHandle^ other);
        bool Equals(Object^ other) override;
    };
} // namespace BedrockServer::Extension::Handle
