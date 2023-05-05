#pragma once

#include "Types.hpp"
#include <mc/Biome.hpp>
namespace BedrockServer::Extension::Handle
{
    public enum class VanillaBiomeTypes {};

    public ref class BiomeHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BiomeHandle, ::Biome)
    public:
        enum class BiomeTempCategory {};
        property int Id {int get() { return NativePtr->getId(); }};
        property String^ Name {String^ get() { return marshalString(NativePtr->getName()); }};

        static BiomeHandle^ FromId(int id);;
        static BiomeHandle^ FromName(String^ name);;
        static array<BiomeHandle^>^ GetBiomesByType(VanillaBiomeTypes type);
    };
}