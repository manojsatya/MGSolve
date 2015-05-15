#include "grid.h"
#include <cmath>
#include <vector>
#include <assert.h>
#include <iostream>
#include <cstring>

using namespace std;

Grid::Grid()
{
    //ctor
}

Grid::Grid(size_t level){

	l = level;
	v_ = new real [l + 1];
	//std::vector<real> v_(l+1);
}

Grid::Grid(const Grid& grid){
	
	v_ = new real[l + 1];
	v_ = grid.v_ ;	
	
}

/*Grid::~Grid()
{
    //dtor
}*/

Grid& Grid::operator=(const Grid& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
 	v_ = rhs.v_ ;   
 //assignment operator
    return *this;
}

/*Grid& Grid::operator+=(const Grid& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Grid& Grid::operator-=(const Grid& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Grid& Grid::operator*=(const Grid& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/


/*inline size_t Grid::xsize(){
	
	x_ = pow(2,l) + 1;		
	return x_;
}

inline size_t Grid::ysize(){
	y_ = pow(2,l) + 1;		
	return y_;
}

inline real Grid::hsize(){
	h_ = 1.0 / (xsize()-1.0);
	return h_ ; 
}

inline real Grid::h2size(){
	h2_ = hsize() * hsize() ;
	return h2_ ;
}*/

void Grid::setBoundary(){
	for(size_t i=0;i<xsize();++i){
	v_[ 0 + i] = sin(M_PI * hsize() * i) * sinh(M_PI * 0.0) ;//bottom
	v_[xsize()*i] = sin(M_PI * 1.0) * sinh(M_PI * hsize() * i); // left
	v_[i +(xsize()-1)*xsize()] = sin(M_PI * i * hsize()) * sinh (M_PI*xsize()*hsize());//top
		//for(size_t i=1;i<grid[lv];++i) // Right boundary
	v_[xsize() * i -1] = sin(M_PI * 0.0 ) * sinh(M_PI * xsize()*i);}

	}

inline real& Grid::operator()(size_t i, size_t j){
	assert (i < x_);
	assert (j < y_);
	return v_[i + j* xsize()];
}

/*void Grid::fill (real value){

	std::fill(v_.begin(),v_.end(),value);

}*/

void Grid::print(){
	std::cout << xsize() << std::endl;
	std::cout << ysize() << std::endl;
	std::cout << hsize() << std::endl;
	std::cout << h2size() << std::endl;
	for(size_t j=0 ; j< xsize() ; ++j)
	for(size_t i=0;i<xsize();++i){
		cout << "v_["<<i + xsize()*j<<"]="<< v_[i + xsize()*j] << endl ; // bottom
	}
}

/*Grid::~Grid()
{
    //dtor
}*/

