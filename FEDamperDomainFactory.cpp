#include "FEDamperDomainFactory.h"
#include "FEHeatTransferMaterial.h"
#include "FEHeatSolidDomain.h"

//-----------------------------------------------------------------------------
//! Use the material and the element type to determine the domain type.
FEDomain* FEDomainDomainFactory::CreateDomain(const FE_Element_Spec& spec, FEMesh* pm, FEMaterial* pmat)
{
	// TODO Add logic here...
	FEModel& fem = *pmat->GetFEModel();
	FE_Element_Class eclass = spec.eclass;
	const char* sztype = 0;
	if (dynamic_cast<FEHeatTransferMaterial*>(pmat))
	{
		if (eclass == FE_ELEM_SOLID) sztype = "heat-solid";
	}

	if (sztype)
	{
		FEDomain* pd = fecore_new<FEDomain>(FEDOMAIN_ID, sztype, &fem);
		if (pd) pd->SetMaterial(pmat);
		return pd;
	}
	else return 0;
}
