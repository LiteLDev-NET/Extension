#pragma once
#include "Types.hpp"
#include <mc/TagMemoryChunk.hpp>
#include <memory>
namespace BedrockServer::Extension::Handle
{
    public ref struct TagMemoryChunkHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(TagMemoryChunkHandle, ::TagMemoryChunk)
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
        static TagMemoryChunkHandle^ Create(array<char>^ data /*, size_t size*/);
        static TagMemoryChunkHandle^ Create(TagMemoryChunkHandle^ a1);
        inline void operator=(TagMemoryChunkHandle^ a1);

        property TagMemoryChunkHandle^ Copy {
            TagMemoryChunkHandle^ get();
        };

        static bool operator!=(TagMemoryChunkHandle^ __op, TagMemoryChunkHandle^ _0);
    };
} // namespace BedrockServer::Extension::Handle
