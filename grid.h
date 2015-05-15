#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <vector>
#include <cmath>
typedef double real ;


class Grid
{
	
    public:
	explicit Grid();
	explicit Grid(size_t level);
		 Grid(const Grid &grid);
	       
        Grid& operator=(const Grid& other);
	//Grid& operator+=(const Grid& other);
	//Grid& operator-=(const Grid& other);
	//Grid& operator*=(const Grid& other);
	//Get functions
	inline size_t xsize(){x_ = pow(2,l) + 1;return x_;}
	inline size_t ysize(){y_ = pow(2,l) + 1;return y_;}
	inline real hsize(){h_ = 1.0 / (x_-1.0);return h_;}
	inline real h2size(){h2_ = hsize() * hsize() ;return h2_;}   

	//Access functions
	inline real & operator()(size_t i, size_t j);
	inline real & operator()(size_t i, size_t j) const;    
		
	void fill (real value);
	void setBoundary();	
	void print();
	
   private:
	size_t y_ ;
	size_t x_ ;
	int l;
	real h_ ;
	real h2_;
	real* v_;

};

#endif // GRID_H
