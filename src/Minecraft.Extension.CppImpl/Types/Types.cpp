#include "Types.hpp"

namespace BedrockServer
{
    inline ActorUniqueID::operator ::ActorUniqueID()
    {
        return { id };
    }

    inline ActorUniqueID::ActorUniqueID(::ActorUniqueID const* p)
        :id(p->id) {}

    inline ActorUniqueID::ActorUniqueID(long long i)
        : id(i) {}

    inline long long ActorUniqueID::Id::get()
    {
        return id;
    }

    inline void ActorUniqueID::Id::set(long long value)
    {
        id = value;
    }

    inline ActorUniqueID::operator long long(ActorUniqueID obj)
    {
        return obj.id;
    }

    ActorRuntimeID::ActorRuntimeID(unsigned long long id)
    {
        this->id = id;
    }
    inline unsigned long long ActorRuntimeID::Id::get()
    {
        return id;
    }
    inline void ActorRuntimeID::Id::set(unsigned long long value)
    {
        this->id = value;
    }
    inline ActorRuntimeID::operator unsigned long long(ActorRuntimeID id)
    {
        return id.id;
    }

    generic<typename A, typename T>
    inline AutomaticID<A, T>::AutomaticID(T x)
    {
        id = x;
    }
    generic<typename A, typename T>
    inline AutomaticID<A, T>::operator T(AutomaticID<A, T>^ _this)
    {
        return _this->id;
    }
} // namespace BedrockServer::Extension::Handle
