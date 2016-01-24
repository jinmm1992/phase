#ifndef PHASEAPP_H
#define PHASEAPP_H

#include "MooseApp.h"

class PhaseApp;

template<>
InputParameters validParams<PhaseApp>();

class PhaseApp : public MooseApp
{
public:
  PhaseApp(InputParameters parameters);
  virtual ~PhaseApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PHASEAPP_H */
