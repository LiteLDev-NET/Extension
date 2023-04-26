#pragma once
#include "Types.hpp"
#include <mc/TagMemoryChunk.hpp>
#include <memory>
namespace BedrockServer::Extension
{
    public ref struct TagMemoryChunk : SafeHandle, ICppClass
    {
        DEFAULT_DEF(TagMemoryChunk, ::TagMemoryChunk)
    public:

        property size_t Capacity
        {
            size_t get();
            void set(size_t val);
        }
        property size_t Size
        {
            size_t get();
            void set(size_t val);
        }
        ref class Data
        {
            Data()
            {
            }
            std::unique_ptr<char[]>* u_ptr;
            size_t size;

        public:
            inline size_t Size();
            inline std::unique_ptr<char[]>* get();
            inline Data(std::unique_ptr<char[]>& p, size_t len);
            inline ~Data();
            inline char^ operator[](int index);
        };
        property Data^ data {Data^ get(); void set(Data^ d); };
        static TagMemoryChunk^ Create(array<char>^ data /*, size_t size*/);
        static TagMemoryChunk^ Create(TagMemoryChunk^ a1);
        inline void operator=(TagMemoryChunk^ a1);

        property TagMemoryChunk^ Copy {
            TagMemoryChunk^ get();
        };

        static bool operator!=(TagMemoryChunk^ __op, TagMemoryChunk^ _0);
    };
} // namespace BedrockServer::Extension
