#pragma once
#include <mc/HashedString.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension::Handle
{
    public ref class HashedStringHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(HashedStringHandle, ::HashedString)
    public:

        //#ifdef INCLUDE_MCAPI

        HashedStringHandle(HashedStringHandle^ _0);

        HashedStringHandle(::String^ _0);

        HashedStringHandle(unsigned long long _0, ::String^ _1);

        property ::String^ CStr {
            ::String^ get();
        };

        property unsigned long long Hash
        {
            unsigned long long get();
        }

        property ::String^ String {
            ::String^ get();
        };

        property bool IsEmpty
        {
            bool get();
        }

        static property HashedStringHandle^ EmptyString {
            HashedStringHandle^ get();
        };

        void Clear();

        static bool operator!=(HashedStringHandle^ __op, HashedStringHandle^ _0);


        static bool operator==(HashedStringHandle^ __op, HashedStringHandle^ _0);

        virtual bool Equals(::System::Object^ obj) override;

        //static void BindType();

        static unsigned long long ComputeHash(::String^ _0);

        static property HashedStringHandle^ DefaultErrorValue {
            HashedStringHandle^ get();
            /*void set(HashedStringHandle^);*/
        }

        //#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension::Handle
