// Copyright (c) 2013 BitGem developers
//
// Simple implementation of 4Cs (Carat, Color, Clarity and Cut) gemstones model.
//

#include <string>
#include <list>
#include <map>


#include <stdio.h>


#include <math.h>

#include "gem.h"


double Gem::getGems(double bitgems)
 {
	
	double gem_value=  pow( carat, 2.0) *  (('Z' - color - 3.0)  / ('Z' - 'J' - 3.0)) * ((clarity * 1.0) / VVS2) * ((cut * 1.0) / GOOD) * ((shape * 1.0) / OVAL);

	switch (type) 
	{ 
	    case DIAMOND: gem_value  *= 10; break;
	    case RUBY: gem_value  *= 1.15; break;
	    case SAPPHIRE: break;
	    case EMERALD: gem_value  *= 0.85; break;
        }
        
	return 	bitgems / gem_value ;
 }


double Gem::getGems (unsigned int _type, double _carat, unsigned int _color, unsigned int _clarity, unsigned int _cut,  unsigned int _shape, double _bitgems) 
{

	double gem_value=  pow( _carat, 2.0) * (('Z' - _color - 3.0)  / ('Z' - 'J' - 3.0)) * ((_clarity * 1.0) / VVS2) * ((_cut * 1.0)/ GOOD) * ((_shape * 1.0) / OVAL);

	
	switch (_type) 
	{ 
	    case DIAMOND: gem_value  *= 10; break;
	    case RUBY: gem_value  *= 1.15; break;
	    case SAPPHIRE: break;
	    case EMERALD: gem_value  *= 0.85; break;
        }
        
	return 	_bitgems / gem_value ;

}

/*
int main( int argc, const char* argv[] )	

{
	 printf( "Gems= %f \n", Gem::getGems(SAPPHIRE, 1.0 , 'J', VVS2, GOOD, OVAL, 1.0) );

}
*/
