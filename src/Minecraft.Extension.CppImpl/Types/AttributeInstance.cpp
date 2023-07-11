#include "AttributeInstance.hpp"

namespace BedrockServer::Extension::Handle
{
    AttributeInstanceHandle::AttributeInstanceHandle(AttributeInstanceHandle^ attr)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        NativePtr = new ::AttributeInstance(*attr->NativePtr);
    }

    AttributeHandle^ AttributeInstanceHandle::AttributeHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::AttributeHandle(const_cast<::Attribute*>(NativePtr->getAttribute()));
    }

    float AttributeInstanceHandle::CurrentValue::get()
    {
        return NativePtr->getCurrentValue();
    }

    void AttributeInstanceHandle::CurrentValue::set(float value)
    {
        NativePtr->setCurrentValue(value);
    }

    float AttributeInstanceHandle::MaxValue::get()
    {
        return NativePtr->getMaxValue();
    }

    void AttributeInstanceHandle::MaxValue::set(float value)
    {
        NativePtr->setMaxValue(value);
    }

    float AttributeInstanceHandle::MinValue::get()
    {
        return NativePtr->getMinValue();
    }

    bool AttributeInstanceHandle::IsValid::get()
    {
        return NativePtr->isValid();
    }

    bool AttributeInstanceHandle::HasModifiers::get()
    {
        return NativePtr->hasModifiers();
    }

    bool AttributeInstanceHandle::HasTemporalBuffs::get()
    {
        return NativePtr->hasTemporalBuffs();
    }

    void AttributeInstanceHandle::AddModifier(AttributeModifierHandle^ modifier)
    {
        NativePtr->addModifier(*modifier->NativePtr);
    }

    float AttributeInstanceHandle::GetDefaultValue(AttributeValueType type)
    {
        return NativePtr->getDefaultValue(static_cast<int>(type));
    }

    AttributeModifierHandle^ AttributeInstanceHandle::GetModifier(Mce::UUID id)
    {
        return gcnew AttributeModifierHandle(&NativePtr->getModifier(*(::mce::UUID*)&id));
    }

    array<AttributeModifierHandle^>^ AttributeInstanceHandle::GetModifiers()
    {
        auto modifiers = NativePtr->getModifiers();
        auto result = gcnew array<AttributeModifierHandle^>(static_cast<int>(modifiers.size()));

        for (int i = 0; i < modifiers.size(); ++i)
        {
            result[i] = gcnew AttributeModifierHandle(&modifiers[i]);
        }

        return result;
    }

    bool AttributeInstanceHandle::HasModifier(AttributeModifierHandle^ modifier)
    {
        for (auto& temp : NativePtr->getModifiers())
        {
            if (temp == *modifier->NativePtr)
                return true;
        }

        return false;
    }

    bool AttributeInstanceHandle::HasModifier(Mce::UUID id)
    {
        return NativePtr->hasModifier(*(::mce::UUID*)&id);
    }

    //void AttributeInstanceHandle::Notify(long long _0)
    //{
    //    NativePtr->notify(_0);
    //}

    void AttributeInstanceHandle::RecalculateModifiers()
    {
        NativePtr->recalculateModifiers();
    }

    void AttributeInstanceHandle::RegisterListener(AttributeInstanceHandle^ attr)
    {
        NativePtr->registerListener(*attr->NativePtr);
    }

    void AttributeInstanceHandle::RemoveBuffs()
    {
        NativePtr->removeBuffs();
    }

    void AttributeInstanceHandle::RemoveModifier(AttributeModifierHandle^ modifier)
    {
        NativePtr->removeModifier(*modifier->NativePtr);
    }

    bool AttributeInstanceHandle::RemoveModifier(Mce::UUID id)
    {
        return NativePtr->removeModifier(*(::mce::UUID*)&id);
    }

    void AttributeInstanceHandle::RemoveModifiers()
    {
        NativePtr->removeModifiers();
    }

    void AttributeInstanceHandle::ResetToDefaultValue()
    {
        NativePtr->resetToDefaultValue();
    }

    void AttributeInstanceHandle::ResetToMaxValue()
    {
        NativePtr->resetToMaxValue();
    }

    void AttributeInstanceHandle::ResetToMinValue()
    {
        NativePtr->resetToMinValue();
    }

    void AttributeInstanceHandle::SerializationSetRange(float min, float defaultCurrent, float max)
    {
        NativePtr->serializationSetRange(min, defaultCurrent, max);
    }

    void AttributeInstanceHandle::SerializationSetValue(float value, AttributeValueType type, float limit)
    {
        NativePtr->serializationSetValue(value, static_cast<int>(type), limit);
    }

    void AttributeInstanceHandle::SetDefaultValue(float value, AttributeValueType type)
    {
        NativePtr->setDefaultValue(value, static_cast<int>(type));
    }

    void AttributeInstanceHandle::SetDefaultValueOnly(float value)
    {
        NativePtr->setDefaultValueOnly(value);
    }

    void AttributeInstanceHandle::SetRange(float min, float current, float max)
    {
        NativePtr->setRange(min, current, max);
    }

    void AttributeInstanceHandle::UpdateModifier(AttributeModifierHandle^ modifier)
    {
        NativePtr->updateModifier(*modifier->NativePtr);
    }

    bool AttributeInstanceHandle::Equals(AttributeInstanceHandle^ other)
    {
        return NativePtr == other->NativePtr;
    }

    bool AttributeInstanceHandle::Equals(Object^ other)
    {
        AttributeInstanceHandle^ otherModifier = dynamic_cast<AttributeInstanceHandle^>(other);
        return otherModifier != nullptr && Equals(otherModifier);
    }
}
