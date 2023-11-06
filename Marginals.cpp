#include "Marginals.h"

Marginals::Marginals(PrintBill* component):PrintBill(), component_(component)
{

}

Marginals::~Marginals()
{
    delete component_;
}

void Marginals::Print() {
  if (component_)
    component_->Print();
}