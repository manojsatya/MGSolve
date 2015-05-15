#include "mgsolver.h"
#include "grid.h"
#include <iostream>

using namespace std;

MGSolve::MGSolve()
{
    //ctor
}

MGSolve& MGSolve::operator=(const MGSolve& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MGSolve::setRestrictionStencil(const Stencil& stencil){
	
	R_ = stencil;
	R_.C = 0.25;
	R_.N = 0.125;
	R_.W = 0.125;
	R_.E = 0.125;
	R_.S = 0.125;
	R_.NW = 0.0625;
	R_.NE = 0.0625;
	R_.SW = 0.0625;
	R_.SE = 0.0625;
}

void MGSolve::setSmootherStencil(const Stencil& stencil){
	
	RB_ = stencil;
	RB_.N = 0.25; 
	RB_.S = 0.25;
	RB_.W = 0.25;
	RB_.E = 0.25;
}

void MGSolve::setInterpolationStencil(const Stencil& stencil){
	
	I_ = stencil;
	I_.C = 1.0;
	I_.N = 0.5;
	I_.W = 0.5;
	I_.E = 0.5;
	I_.S = 0.5;
	I_.NW = 0.25;
	I_.NE = 0.25;
	I_.SW = 0.25;
	I_.SE = 0.25;	
}

void MGSolve::smooth(Grid& u,Grid& f,size_t iter){
	//iter = 2;
	const size_t size= sizeof(u.xsize()* u.xsize());
	std::cout << size << std::endl;;
	real h2 = u.h2size();
	std::cout << h2 << std::endl;;
	//std::cout <<"xsize:"<<<< xsize() << std::endl;
	for(iter = 0 ; iter < 2 ; ++iter){

	for(size_t j=1;j<size-1;++j)
		for(size_t i= 1 + (j+1)%2 ; i <size-1;++i){

		u[i + size*j] = 0.25 * ( h2 * f[i +size*j] 
					+ u[(i-1) +size*j]
					+ u[(i+1) +size*j]
					+ u[i +size*(j+1)]
					+ u[i +size*(j-1)]);} 
		
	for(size_t j=1;j<size-1;++j)
		for(size_t i= 1 + (j)%2 ; i <size-1;++i){

		u[i + size*j] = 0.25 * ( h2 * f[i +size*j] 
					+ u[(i-1) +size*j]
					+ u[(i+1) +size*j]
					+ u[i +size*(j+1)]
					+ u[i +size*(j-1)]);}


	}
}

MGSolve::~MGSolve()
{
    //dtor
}






