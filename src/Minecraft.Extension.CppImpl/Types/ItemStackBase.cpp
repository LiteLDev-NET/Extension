#include "ItemStackBase.hpp"
namespace BedrockServer::Extension::Handle
{
int ItemStackBaseHandle::Count::get()
{
    return NativePtr->getCount();
}
#ifndef INCLUDE_MCAPI
short BedrockServer::Extension::Handle::ItemStackBaseHandle::Id::get()
{
    auto __ret = NativePtr->getId();
    return __ret;
}
#endif // INCLUDE_MCAPI


} // namespace BedrockServer::Extension::Handle
