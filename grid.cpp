#include "grid.h"
#include <cmath>
#include <vector>
#include <assert.h>

Grid::Grid()
{
    //ctor
}

Grid::Grid(size_t level){

	l = level;
}

/*Grid::~Grid()
{
    //dtor
}*/

Grid& Grid::operator=(const Grid& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

inline size_t Grid::xsize(){
	
	x_ = pow(2,l + 1);		
	return x_;
}

inline size_t Grid::ysize(){
	y_ = pow(2,l + 1);		
	return y_;
}

inline real Grid::hsize(){
		
	return h_ = 1.0 / (l -1);
}

/*inline real& Grid::operator()(size_t i, size_t j){
	
	assert (i < x_);
	assert (j < y_);
	return v_[i + j* x_];
}*/

inline real& Grid::operator()(size_t i, size_t j){
	assert (i < x_);
	assert (j < y_);
	return v_[i + j* xsize()];
}

void Grid::fill (real value){

	std::fill(v_.begin(),v_.end(),value);

}

/*Grid::~Grid()
{
    //dtor
}*/

