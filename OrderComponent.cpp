#include "OrderComponent.h"

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
