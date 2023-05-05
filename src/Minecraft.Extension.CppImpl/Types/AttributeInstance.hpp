﻿#pragma once
#include <mc/AttributeInstance.hpp>
#include "Attribute.hpp"
#include "AttributeModifier.hpp"
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public enum class AttributeValueType
    {
        Min,
        Max,
        Current
    };

    public ref class AttributeInstanceHandle :SafeHandle, ICppClass
    {
    internal: AttributeInstanceHandle(::AttributeInstance* ptr) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = false;
    } AttributeInstanceHandle(::AttributeInstance* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = nint_t(ptr); OwnsNativeInstance = ownsinstance;
    } operator ::AttributeInstance* () {
        return reinterpret_cast<::AttributeInstance*>((void*)NativePointer);
    } static operator AttributeInstanceHandle ^ (::AttributeInstance* ptr) {
        return gcnew AttributeInstanceHandle(ptr);
    } property ::AttributeInstance* NativePtr { ::AttributeInstance* get() {
        return reinterpret_cast<::AttributeInstance*>((void*)NativePointer);
    } void set(::AttributeInstance* value) {
        NativePointer = static_cast<nint_t>((void*)value);
    } } static size_t classSize = 0; public: static void SetClassSize(size_t size) {
        classSize = size;
    } AttributeInstanceHandle(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {
        NativePointer = ptr; OwnsNativeInstance = OwnsNativeInstance;
    } virtual property nint_t NativePointer { nint_t get() { return handle; } void set(nint_t value) { handle = value; } }; virtual property bool OwnsNativeInstance; virtual void Destruct() {
        ReleaseHandle();
    } virtual size_t GetClassSize() {
        return classSize;
    } virtual bool ReleaseHandle() override {
        if (OwnsNativeInstance) __dtor<::AttributeInstance>::destruct(NativePtr); return true;
    } property bool IsInvalid { virtual bool get() override {
        return false;
    } }
    public:

        AttributeInstanceHandle(AttributeInstanceHandle^ attr);
        AttributeInstanceHandle();

        property AttributeHandle^ AttributeHandle { BedrockServer::Extension::Handle::AttributeHandle^ get(); }
        property float CurrentValue { float get(); void set(float value); }
        property float MaxValue { float get(); void set(float value); }
        property float MinValue { float get(); }
        property bool IsValid { bool get(); }
        property bool HasModifiers { bool get(); }
        property bool HasTemporalBuffs { bool get(); }

        //void AddBuff(AttributeBuff^);
        void AddModifier(AttributeModifierHandle^ modifier);
        //List<TemporalAttributeBuff^>^ GetBuffs();
        float GetDefaultValue(AttributeValueType type);
        //AttributeInstanceHandle^ GetHandle();
        //List<AttributeInstanceHandle>^ GetListeners();
        AttributeModifierHandle^ GetModifier(Mce::UUID id);
        array<AttributeModifierHandle^>^ GetModifiers();
        bool HasModifier(AttributeModifierHandle^ modifier);
        bool HasModifier(Mce::UUID id);
        //void InheritFrom(AttributeInstance^, BaseAttributeMap^);
        void Notify(long long _0);
        void RecalculateModifiers();
        void RegisterListener(AttributeInstanceHandle^ attr);
        //void RemoveBuff(AttributeBuff^);
        //void RemoveBuff(AttributeBuff^);
        void RemoveBuffs();
        void RemoveModifier(AttributeModifierHandle^ modifier);
        bool RemoveModifier(Mce::UUID id);
        void RemoveModifiers();
        void ResetToDefaultValue();
        void ResetToMaxValue();
        void ResetToMinValue();
        void SerializationSetRange(float min, float defaultCurrent, float max);
        void SerializationSetValue(float value, AttributeValueType type, float limit);
        void SetDefaultValue(float value, AttributeValueType type);
        void SetDefaultValueOnly(float value);
        //void SetDelegate(AttributeInstanceDelegate^);
        void SetRange(float min, float current, float max);
        void UpdateModifier(AttributeModifierHandle^ modifier);
        virtual bool Equals(AttributeInstanceHandle^ other);
        bool Equals(Object^ other) override;
    };
} // namespace BedrockServer::Extension::Handle
