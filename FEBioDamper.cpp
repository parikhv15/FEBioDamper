#include <FECore/sdk.h>
#include "FEIsotropicFourier.h"
#include "FEPlotHeatFlux.h"
#include "FEHeatFlux.h"
#include "FEConvectiveHeatFlux.h"
#include "FEHeatSolver.h"
#include "FEHeatSolidDomain.h"
#include "FEHeatDomainFactory.h"
#include "FEHeatSource.h"
#include "FEHeatSolidDomain.h"
#include "FEGapHeatFlux.h"

FECORE_PLUGIN void PluginInitialize(FECoreKernel& fecore)
{
	// Set the kernel to match FEBio's kernel
	FECoreKernel::SetInstance(&fecore);

	// Create the damper module
	fecore.CreateModule("damper");

	// Domain factory
	fecore.RegisterDomain(new FEDamperDomainFactory);

	// Feature classes that you want to add to the plugin.
	// FETASK_ID : Create a task class
	// FESOLVER_ID : Create a solver class
	// FEMATERIAL_ID : Create a material class
	// FEBODYLOAD_ID : Create a body load class
	// FENLCONSTRAINT_ID : Create a nonlinear constraint class
	// FECOORDSYSMAP_ID : Create a coordinate system class
	// FEPLOTDATA_ID : Create a plot data class
	// FECALLBACK_ID : Create a callback class
	REGISTER_FECORE_CLASS(FEHeatSolidDomain		, FEDOMAIN_ID								 , "heat-solid");
	REGISTER_FECORE_CLASS(FEHeatSolver        , FESOLVER_ID                , "heat");
	REGISTER_FECORE_CLASS(FEIsotropicFourier  , FEMATERIAL_ID              , "isotropic Fourier");
	REGISTER_FECORE_CLASS(FEConstHeatSource   , FEBODYLOAD_ID              , "heat_source");
	REGISTER_FECORE_CLASS(FEHeatFlux          , FESURFACELOAD_ID           , "heatflux");
	REGISTER_FECORE_CLASS(FEConvectiveHeatFlux, FESURFACELOAD_ID           , "convective_heatflux");
	REGISTER_FECORE_CLASS(FEPlotHeatFlux      , FEPLOTDATA_ID              , "heat flux");
	REGISTER_FECORE_CLASS(FEGapHeatFlux       , FESURFACEPAIRINTERACTION_ID, "gap heat flux");

	fecore.SetActiveModule(0);
}

FECORE_PLUGIN int GetSDKVersion()
{
	return FE_SDK_VERSION;
}
