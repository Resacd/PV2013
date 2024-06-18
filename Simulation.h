#pragma once

#include "VelocitySet.h"
#include "Subdomain.h"
#include "OutputFile.h"
#include "Boundary.h"
#include <vector>
#include "pulsatile.h"

class Simulation
{

public:
	int myrank_, num_procs_;
	SubDomain SubDomain_;
	Pulsatile Pulsatile_;
	double pressure_;
	double m_relaxation;
double m_omega;
	double m_dt;
	std::vector<double> wall_shear_stress;
	std::vector<double> InletVelocity_;
	Simulation(SubDomain& SubDomain, double tau, double pressure, double del_t);
	~Simulation();
	void Collision();
	void Streaming();
	void ApplyEqBc();
	void ApplyZouHeBc();
	void ApplyOutletBc();
	void ApplyWallBc();

	void ComputeVelocityGradientAtWall();
	void ComputeWallShearStress();

	void writeDataToFile(const std::vector<double>& data, const std::string& baseFilename, int iteration);
	void FaceCommunicate(int iter);
	void EdgeCommunicate();
	void WSS();
	double getInletVelocity(double x, double period);
	void Iterate();
	void SetRelaxation(double tau);
	void WriteOutput(int iter);

};


