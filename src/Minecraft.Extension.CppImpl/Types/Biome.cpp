#include "Biome.hpp"

namespace BedrockServer::Extension::Handle
{
    inline BiomeHandle^ BiomeHandle::FromId(int id) { return gcnew BiomeHandle(::Biome::fromId(id)); }
    inline BiomeHandle^ BiomeHandle::FromName(String^ name) { return gcnew BiomeHandle(::Biome::fromName(marshalString(name))); }
    inline array<BiomeHandle^>^ BiomeHandle::GetBiomesByType(VanillaBiomeTypes type) {
        auto& vec = ::Biome::getBiomesByType(::VanillaBiomeTypes(type));
        auto ret = gcnew array<BiomeHandle^>((int)vec.size());
        for (int i = 0; i < vec.size(); ++i) {
            ret[i] = gcnew BiomeHandle(vec[i]);
        }
        return ret;
    }
}