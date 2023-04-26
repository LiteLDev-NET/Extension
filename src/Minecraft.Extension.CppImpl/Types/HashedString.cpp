#include "HashedString.hpp"

namespace BedrockServer::Extension
{


    BedrockServer::Extension::HashedString::HashedString(BedrockServer::Extension::HashedString^ _0)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        if (ReferenceEquals(_0, nullptr))
            throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
        auto& __arg0 = *(class ::HashedString*)_0->NativePtr;
        NativePtr = new class ::HashedString(__arg0);
    }

    BedrockServer::Extension::HashedString::HashedString(::String^ _0)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        auto ___arg0 = clix::marshalString<clix::E_UTF8>(_0);
        auto __arg0 = ___arg0.c_str();
        NativePtr = new class ::HashedString(__arg0);
    }

    BedrockServer::Extension::HashedString::HashedString(unsigned long long _0, ::String^ _1)
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        auto ___arg1 = clix::marshalString<clix::E_UTF8>(_1);
        auto __arg1 = ___arg1.c_str();
        NativePtr = new class ::HashedString(_0, __arg1);
    }

    void BedrockServer::Extension::HashedString::Clear()
    {
        ((class ::HashedString*)NativePtr)->clear();
    }

    bool BedrockServer::Extension::HashedString::operator!=(BedrockServer::Extension::HashedString^ __op, BedrockServer::Extension::HashedString^ _0)
    {
        bool __opNull = ReferenceEquals(__op, nullptr);
        bool _0Null = ReferenceEquals(_0, nullptr);
        if (__opNull || _0Null)
            return !(__opNull && _0Null);
        auto& __arg0 = *(class ::HashedString*)__op->NativePtr;
        auto& __arg1 = *(class ::HashedString*)_0->NativePtr;
        auto __ret = __arg0 != __arg1;
        return __ret;
    }

    bool BedrockServer::Extension::HashedString::operator==(BedrockServer::Extension::HashedString^ __op, BedrockServer::Extension::HashedString^ _0)
    {
        bool __opNull = ReferenceEquals(__op, nullptr);
        bool _0Null = ReferenceEquals(_0, nullptr);
        if (__opNull || _0Null)
            return __opNull && _0Null;
        auto& __arg0 = *(class ::HashedString*)__op->NativePtr;
        auto& __arg1 = *(class ::HashedString*)_0->NativePtr;
        auto __ret = __arg0 == __arg1;
        return __ret;
    }

    bool BedrockServer::Extension::HashedString::Equals(::System::Object^ obj)
    {
        return this == safe_cast<BedrockServer::Extension::HashedString^>(obj);
    }

    //void BedrockServer::Extension::HashedString::BindType()
    //{
    //    ::HashedString::bindType();
    //}

    unsigned long long BedrockServer::Extension::HashedString::ComputeHash(::String^ _0)
    {
        auto ___arg0 = clix::marshalString<clix::E_UTF8>(_0);
        auto __arg0 = ___arg0.c_str();
        auto __ret = ::HashedString::computeHash(__arg0);
        return __ret;
    }

    ::String^ BedrockServer::Extension::HashedString::CStr::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->c_str();
        if (__ret == nullptr) return nullptr;
        return (__ret == 0 ? nullptr : clix::marshalString<clix::E_UTF8>(__ret));
    }

    unsigned long long BedrockServer::Extension::HashedString::Hash::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->getHash();
        return __ret;
    }

    ::String^ BedrockServer::Extension::HashedString::String::get()
    {
        auto& __ret = ((class ::HashedString*)NativePtr)->getString();
        return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
    }

    bool BedrockServer::Extension::HashedString::IsEmpty::get()
    {
        auto __ret = ((class ::HashedString*)NativePtr)->isEmpty();
        return __ret;
    }

    BedrockServer::Extension::HashedString^ BedrockServer::Extension::HashedString::EmptyString::get()
    {
        auto& __ret = ::HashedString::getEmptyString();
        return (BedrockServer::Extension::HashedString^)((&__ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::HashedString((class ::HashedString*) & __ret));
    }

    BedrockServer::Extension::HashedString^ BedrockServer::Extension::HashedString::DefaultErrorValue::get()
    {
        return (&::HashedString::defaultErrorValue == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::HashedString((class ::HashedString*) & ::HashedString::defaultErrorValue);
    }

    void BedrockServer::Extension::HashedString::DefaultErrorValue::set(BedrockServer::Extension::HashedString^ value)
    {
        if (ReferenceEquals(value, nullptr))
            throw gcnew ::System::ArgumentNullException("value", "Cannot be null because it is passed by value.");
        ::HashedString::defaultErrorValue = *(class ::HashedString*)value->NativePtr;
    }

}
