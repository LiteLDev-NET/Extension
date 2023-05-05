#pragma once
#include "Attribute.hpp"
#include "MC/SharedAttributes.hpp"

namespace BedrockServer::Extension::Handle
{
public
ref class SharedAttributes __static
{
public:
    static initonly AttributeHandle^ Absorption = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::ABSORPTION));
    static initonly AttributeHandle^ AttackDamage = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::ATTACK_DAMAGE));
    static initonly AttributeHandle^ FollowRange = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::FOLLOW_RANGE));
    static initonly AttributeHandle^ Health = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::HEALTH));
    static initonly AttributeHandle^ JumpStrength = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::JUMP_STRENGTH));
    static initonly AttributeHandle^ KnockbackResistance = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::KNOCKBACK_RESISTANCE));
    static initonly AttributeHandle^ LavaMovementSpeed = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::LAVA_MOVEMENT_SPEED));
    static initonly AttributeHandle^ Luck = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::LUCK));
    static initonly AttributeHandle^ MovementSpeed = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::MOVEMENT_SPEED));
    static initonly AttributeHandle^ UnderwaterMovementSpeed = gcnew AttributeHandle(const_cast<::Attribute*>(&::SharedAttributes::UNDERWATER_MOVEMENT_SPEED));
};
}
