#include "ItemStackBase.hpp"
namespace BedrockServer::Extension
{
int ItemStackBase::Count::get()
{
    return NativePtr->getCount();
}
#ifndef INCLUDE_MCAPI
short BedrockServer::Extension::ItemStackBase::Id::get()
{
    auto __ret = NativePtr->getId();
    return __ret;
}
#endif // INCLUDE_MCAPI


} // namespace BedrockServer::Extension
