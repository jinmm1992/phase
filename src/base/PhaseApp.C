#include "PhaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<PhaseApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

PhaseApp::PhaseApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PhaseApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PhaseApp::associateSyntax(_syntax, _action_factory);
}

PhaseApp::~PhaseApp()
{
}

// External entry point for dynamic application loading
extern "C" void PhaseApp__registerApps() { PhaseApp::registerApps(); }
void
PhaseApp::registerApps()
{
  registerApp(PhaseApp);
}

// External entry point for dynamic object registration
extern "C" void PhaseApp__registerObjects(Factory & factory) { PhaseApp::registerObjects(factory); }
void
PhaseApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void PhaseApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PhaseApp::associateSyntax(syntax, action_factory); }
void
PhaseApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
