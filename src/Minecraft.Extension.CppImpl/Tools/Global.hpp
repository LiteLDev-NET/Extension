#pragma once
using System::Console;
using System::GC;
using System::IntPtr;
using System::String;
using System::Object;
using System::Exception;
using System::Delegate;
using System::Collections::Generic::Dictionary;
using System::Collections::Generic::List;
using System::Collections::Generic::Queue;
using System::Reflection::Assembly;
using System::Reflection::AssemblyName;
using System::Runtime::InteropServices::FieldOffsetAttribute;
using System::Runtime::InteropServices::GCHandle;
using System::Runtime::InteropServices::LayoutKind;
using System::Runtime::InteropServices::Marshal;
using System::Runtime::InteropServices::StructLayoutAttribute;
using System::Runtime::InteropServices::OutAttribute;
using System::Runtime::InteropServices::InAttribute;
using System::Runtime::InteropServices::SafeHandle;
using System::Runtime::InteropServices::DefaultParameterValueAttribute;
using System::Runtime::CompilerServices::MethodImplAttribute;
using System::Runtime::CompilerServices::MethodImplOptions;
using System::Runtime::CompilerServices::ExtensionAttribute;
using System::Runtime::CompilerServices::Unsafe;
using System::Runtime::ConstrainedExecution::CriticalFinalizerObject;

using System::Collections::Generic::IEnumerator;
using System::Collections::Generic::IAsyncEnumerator;
using System::Collections::Generic::IEnumerable;
using System::Collections::Generic::IAsyncEnumerable;
using IEnumerableNonGgeneric = System::Collections::IEnumerable;
using IEnumeratorNonGgeneric = System::Collections::IEnumerator;

using SystemType = System::Type;
using byte_t = unsigned char;

using nint_t = IntPtr;

#include "clix.hpp"
#include "type_traits.hpp"
#include "mutex.hpp"

#define __static abstract sealed
#define _in [In]
#define _out [Out]
#define _ext [Extension]
#define __default(val) [DefaultParameterValue(val)]

inline String^ marshalString(std::string const& str)
{
    return clix::marshalString<clix::Encoding::E_UTF8>(str);
}

inline std::string marshalString(String^ str)
{
    return clix::marshalString<clix::Encoding::E_UTF8>(str);
}

inline String^ marshalWstring(std::wstring const& str)
{
    return clix::marshalString<clix::Encoding::E_UTF16>(str);
}

inline std::wstring marshalWstring(String^ str)
{
    return clix::marshalString<clix::Encoding::E_UTF16>(str);
}

inline uint64_t do_Hash(String^ str)
{
    uint64_t rval = 0;
    for (int i = 0; i < str->Length; ++i)
    {
        if (i & 1)
        {
            rval ^= (~((rval << 11) ^ str[i] ^ (rval >> 5)));
        }
        else
        {
            rval ^= (~((rval << 7) ^ str[i] ^ (rval >> 3)));
        }
    }
    return rval;
}

template<typename T, typename U>
inline T As(U u)
{
    return __as<T>(u);
}

template<typename T, typename U>
inline bool Is(U u)
{
    return As<T>(u) != nullptr;
}

#include "../Tools/type_traits.hpp"

template<typename T>
inline cli::array<T>^ PackArray()
{
    return System::Array::Empty<T>();
}

template<typename T>
inline cli::array<T>^ PackArray(...cli::array<T>^ args)
{
    using namespace LiteLoader::NET;

    static_assert(is_ref_class_v<remove_handle_t<T>>);

    return args;
}

#using <Minecraft.Extension.Foundation.dll> as_friend
#using <InteropServices/LiteLoader.NET.InteropServices.dll>
#using <CppStd/LiteLoader.NET.CppStd.dll>

using LiteLoader::NET::InteropServices::ICppClass;
using ref_std_string = LiteLoader::NET::CppStd::string;
using ref_std_wstring = LiteLoader::NET::CppStd::wstring;
#define ref_std_vector LiteLoader::NET::CppStd::vector;

template<typename T>
struct __dtor {
    inline static void destruct(T* p) { p->~T(); }
};

#define DEFAULT_DEF(_class,_nativeClass)\
internal:\
    _class(_nativeClass* ptr) :SafeHandle(nint_t::Zero, true) {\
        NativePointer = nint_t(ptr);\
        OwnsNativeInstance = false;\
    }\
    _class(_nativeClass* ptr, bool ownsinstance) :SafeHandle(nint_t::Zero, true) {\
        NativePointer = nint_t(ptr);\
        OwnsNativeInstance = ownsinstance;\
    }\
    operator _nativeClass* () { return reinterpret_cast<_nativeClass*>((void*)NativePointer); }\
    static operator _class ^ (_nativeClass* ptr) { return gcnew _class(ptr); }\
    property _nativeClass* NativePtr {\
        _nativeClass* get() { return reinterpret_cast<_nativeClass*>((void*)NativePointer); }\
        void set(_nativeClass* value){NativePointer = static_cast<nint_t>((void*)value); }\
    }\
    static size_t classSize = 0;\
public:\
    static void SetClassSize(size_t size) { classSize = size; }\
    _class() :SafeHandle(nint_t::Zero, true) {}\
    _class(nint_t ptr, bool ownInstance) :SafeHandle(nint_t::Zero, true) {\
        NativePointer = ptr;\
        OwnsNativeInstance = OwnsNativeInstance;\
    }\
    virtual property nint_t NativePointer{ nint_t get() { return handle; } void set(nint_t value) { handle = value; } };\
    virtual property bool OwnsNativeInstance;\
    virtual void Destruct() { ReleaseHandle(); }\
    virtual size_t GetClassSize() { return classSize; }\
    virtual bool ReleaseHandle() override { if(OwnsNativeInstance) __dtor<_nativeClass>::destruct(NativePtr); return true; }\
    property bool IsInvalid{ virtual bool get() override { return false; } }

#define DEFAULT_DEF_OVERRIDE(_class,_nativeClass,_baseClass)\
internal:\
    _class(_nativeClass* ptr) :_baseClass(nint_t::Zero, true) {\
        NativePointer = nint_t(ptr);\
        OwnsNativeInstance = false;\
    }\
    _class(_nativeClass* ptr, bool ownsinstance) :_baseClass(nint_t::Zero, true) {\
        NativePointer = nint_t(ptr);\
        OwnsNativeInstance = ownsinstance;\
    }\
    operator _nativeClass* () { return reinterpret_cast<_nativeClass*>((void*)NativePointer); }\
    static operator _class ^ (_nativeClass* ptr) { return gcnew _class(ptr); }\
    property _nativeClass* NativePtr {\
        _nativeClass* get() { return reinterpret_cast<_nativeClass*>((void*)NativePointer); }\
        void set(_nativeClass* value){ NativePointer = static_cast<nint_t>((void*)value); }\
    }\
    static size_t classSize = 0;\
public:\
    static void SetClassSize(size_t size) { classSize = size; }\
    _class() :_baseClass(nint_t::Zero, true) {}\
    _class(nint_t ptr, bool ownInstance) :_baseClass(nint_t::Zero, true) {\
        NativePointer = ptr;\
        OwnsNativeInstance = OwnsNativeInstance;\
    }\
    virtual void Destruct() override { ReleaseHandle(); }\
    virtual size_t GetClassSize() override { return classSize; }\
    virtual bool ReleaseHandle() override { if(OwnsNativeInstance) __dtor<_nativeClass>::destruct(NativePtr); return true; }\
    property bool IsInvalid{ virtual bool get() override { return false; } }