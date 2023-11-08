#include "OrderComponent.h"
#include "ItemIterator.h"

OrderComponent::OrderComponent()
{
}

OrderComponent::~OrderComponent()
{
}

ItemIterator* OrderComponent::CreateItemIterator()
{
  return new ItemIterator();
}
