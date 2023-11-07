#include "OrderComponent.h"
#include "ItemIterator.h"

OrderComponent::OrderComponent()
{
}

OrderComponent::~OrderComponent()
{
}

ItemIterator* OrderComponent::createItemIterator()
{
  return new ItemIterator();
}
