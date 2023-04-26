#pragma once

#include "Types.hpp"
#include <mc/Biome.hpp>
namespace BedrockServer::Extension
{
    public enum class VanillaBiomeTypes {};

    public ref class Biome :SafeHandle, ICppClass
    {
        DEFAULT_DEF(Biome, ::Biome)
    public:
        enum class BiomeTempCategory {};
        property int Id {int get() { return NativePtr->getId(); }};
        property String^ Name {String^ get() { return marshalString(NativePtr->getName()); }};

        static Biome^ FromId(int id);;
        static Biome^ FromName(String^ name);;
        static array<Biome^>^ GetBiomesByType(VanillaBiomeTypes type);
    };
}