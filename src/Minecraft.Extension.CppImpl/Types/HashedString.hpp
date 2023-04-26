#pragma once
#include <mc/HashedString.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension
{
    public ref class HashedString :SafeHandle, ICppClass
    {
        DEFAULT_DEF(HashedString, ::HashedString)
    public:

        //#ifdef INCLUDE_MCAPI

        HashedString(HashedString^ _0);

        HashedString(::String^ _0);

        HashedString(unsigned long long _0, ::String^ _1);

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

        static property HashedString^ EmptyString {
            HashedString^ get();
        };

        void Clear();

        static bool operator!=(HashedString^ __op, HashedString^ _0);


        static bool operator==(HashedString^ __op, HashedString^ _0);

        virtual bool Equals(::System::Object^ obj) override;

        //static void BindType();

        static unsigned long long ComputeHash(::String^ _0);

        static property HashedString^ DefaultErrorValue {
            HashedString^ get();
            void set(HashedString^);
        }

        //#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension
