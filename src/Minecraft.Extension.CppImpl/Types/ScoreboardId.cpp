#include "ScoreboardId.hpp"
namespace BedrockServer::Extension
{
    ScoreboardId::ScoreboardId()
        :SafeHandle(nint_t::Zero, true)
    {
        OwnsNativeInstance = true;
        NativePtr = new ::ScoreboardId;
    }
    inline __int64 ScoreboardId::Id::get()
    {
        return NativePtr->id;
    }
    inline void ScoreboardId::Id::set(__int64 id)
    {
        NativePtr->id = id;
    }
    inline nint_t ScoreboardId::Null::get()
    {
        return nint_t(NativePtr->null);
    }
    inline void ScoreboardId::Null::set(nint_t p)
    {
        NativePtr->null = p.ToPointer();
    }
} // namespace BedrockServer::Extension

BedrockServer::Extension::ScoreboardId::ScoreboardId(BedrockServer::Extension::ScoreboardId^ _0)
    :SafeHandle(nint_t::Zero, true)
{
    OwnsNativeInstance = true;
    if (ReferenceEquals(_0, nullptr))
        throw gcnew ::System::ArgumentNullException("_0", "Cannot be null because it is a C++ reference (&).");
    auto& __arg0 = *(struct ::ScoreboardId*)_0->NativePtr;
    NativePtr = new struct ::ScoreboardId(__arg0);
}

int BedrockServer::Extension::ScoreboardId::GetHashCode()
{
    return (int)Hash;
}

BedrockServer::Extension::ScoreboardId::ScoreboardId(long long _0)
    :SafeHandle(nint_t::Zero, true)
{
    OwnsNativeInstance = true;
    NativePtr = new struct ::ScoreboardId(_0);
}

bool BedrockServer::Extension::ScoreboardId::operator!=(BedrockServer::Extension::ScoreboardId^ __op, BedrockServer::Extension::ScoreboardId^ _0)
{
    bool __opNull = ReferenceEquals(__op, nullptr);
    bool _0Null = ReferenceEquals(_0, nullptr);
    if (__opNull || _0Null)
        return !(__opNull && _0Null);
    auto& __arg0 = *(struct ::ScoreboardId*)__op->NativePtr;
    auto& __arg1 = *(struct ::ScoreboardId*)_0->NativePtr;
    auto __ret = __arg0 != __arg1;
    return __ret;
}

bool BedrockServer::Extension::ScoreboardId::operator==(BedrockServer::Extension::ScoreboardId^ __op, BedrockServer::Extension::ScoreboardId^ _0)
{
    bool __opNull = ReferenceEquals(__op, nullptr);
    bool _0Null = ReferenceEquals(_0, nullptr);
    if (__opNull || _0Null)
        return __opNull && _0Null;
    auto& __arg0 = *(struct ::ScoreboardId*)__op->NativePtr;
    auto& __arg1 = *(struct ::ScoreboardId*)_0->NativePtr;
    auto __ret = __arg0 == __arg1;
    return __ret;
}

bool BedrockServer::Extension::ScoreboardId::Equals(::System::Object^ obj)
{
    return this == safe_cast<BedrockServer::Extension::ScoreboardId^>(obj);
}

BedrockServer::Extension::ScoreboardId::operator BedrockServer::Extension::ScoreboardId ^ (long long _0) {
    auto __ret = (::ScoreboardId)_0;
    auto ____ret = new struct ::ScoreboardId(__ret);
    return (____ret == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::ScoreboardId((struct ::ScoreboardId*)____ret, true);
}

unsigned long long BedrockServer::Extension::ScoreboardId::Hash::get()
{
    auto __ret = NativePtr->getHash();
    return __ret;
}

bool BedrockServer::Extension::ScoreboardId::IsValid::get()
{
    auto __ret = NativePtr->isValid();
    return __ret;
}
