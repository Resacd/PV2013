#pragma once
#include <iostream>
#include "VelocitySet.h"
#include "include.h"
#include "Struct.h"
#include "Macro.h"
class Node
{



public:
	std::vector<double> m_distributions;
	std::vector<double> m_newDistributions;
	std::vector<double> m_eqdistributions;
	std::shared_ptr<Node> m_neighbours[_nLatNodes];
	int x_position;
	int y_position;
	int z_position;
	NodeType NodeType_;
	BoundaryType BoundaryType_;
        double density;
        std::vector<double>velocity;

	std::vector<double> velocity_gradient; 
	double wall_shear_stress;

	Node() = default;
	Node(int coord_x, int coord_y, int coord_z, NodeType nt);
	~Node();

	double Equilibrium(std::shared_ptr<VelocitySet> velSet, int dir);
	void Stream(int dir);
	void Initialize(std::shared_ptr<VelocitySet> velSet, int dir);
	virtual double Density();
	virtual std::vector<double> Velocity(std::shared_ptr<VelocitySet> velSet);
	virtual void MacroscopicValue(std::shared_ptr<VelocitySet> velSet);
	double GetVelocityXGradient(double delta_x, std::shared_ptr<VelocitySet> velSet);
	double GetVelocityYGradient(double delta_y, std::shared_ptr<VelocitySet> velSet);
	double GetVelocityZGradient(double delta_z, std::shared_ptr<VelocitySet> velSet);
	double CalculateWallShearStress(double delta_x, double delta_y, double delta_z, std::shared_ptr<VelocitySet> velSet);
	double Pressure(std::shared_ptr<VelocitySet> velSet);
	void BounceBack(int dir, int opp_dir);
	virtual void ApplyEqBc();
	virtual void ApplyBc();


};

