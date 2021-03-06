/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "PresetBC.h"

template <>
InputParameters
validParams<PresetBC>()
{
  InputParameters p = validParams<NodalBC>();
  p.addRequiredParam<Real>("value", "Value of the BC");
  p.declareControllable("value");
  p.addClassDescription(
      "Similar to DirichletBC except the value is applied before the solve begins");
  return p;
}

PresetBC::PresetBC(const InputParameters & parameters)
  : PresetNodalBC(parameters), _value(getParam<Real>("value"))
{
}

Real
PresetBC::computeQpValue()
{
  return _value;
}
