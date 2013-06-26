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
	
    double gem_value=  pow( carat, 2.0) *  (('Z' - color + 1.0 )  / ('Z' - 'J' + 1.0 )) * ((clarity * 1.0) / VVS2) * ((cut * 1.0) / GOOD) * ((shape * 1.0) / OVAL);

	switch (type) 
	{ 
        case DIAMOND: gem_value  *= 15.602145295; break;
        case RUBY: gem_value  *= 3.100513821; break;
	    case SAPPHIRE: break;
        case EMERALD: gem_value  *= 0.992836515; break;
        }
        
    if (gem_value == 0)
            return 0;
    else
           return 	bitgems / gem_value ;
 }


double Gem::getGems (unsigned int _type, double _carat, unsigned int _color, unsigned int _clarity, unsigned int _cut,  unsigned int _shape, double _bitgems) 
{

    double gem_value=  pow( _carat, 2.0) * (('Z' - _color + 1.0 )  / ('Z' - 'J' + 1.0)) * ((_clarity * 1.0) / VVS2) * ((_cut * 1.0)/ GOOD) * ((_shape * 1.0) / OVAL);

	
	switch (_type) 
	{ 
        case DIAMOND: gem_value  *= 15.602145295; break;
        case RUBY: gem_value  *= 3.100513821; break;
	    case SAPPHIRE: break;
        case EMERALD: gem_value  *= 0.992836515; break;
    }

    if (gem_value == 0)
            return 0;
    else
           return 	_bitgems / gem_value ;

}

unsigned int Gem::getshapefromindex ( int shape) {
    switch (shape) {
    case 0: shape=15; break;
    case 1:case 2:case 3:case 4: shape=13; break;
    case 5:case 6:case 7: shape=12; break;
    case 8:case 9:case 10:case 11: case 12: shape=11; break;
    case 13:case 14: shape=10; break;
    default: shape=OVAL;
    }

    return shape;
}


bool Gem::getGemWallet() {
    return gemWallet;
}

void Gem::setGemWallet(bool _gemWallet) {
  gemWallet= _gemWallet;
}

/*
int main( int argc, const char* argv[] )	

{
	 printf( "Gems= %f \n", Gem::getGems(SAPPHIRE, 1.0 , 'J', VVS2, GOOD, OVAL, 1.0) );

}
*/
