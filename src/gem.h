// Copyright (c) 2013 BitGem developers
//
// Simple implementation of 4Cs (Carat, Color, Clarity and Cut) gemstones model.
//

#include <string>
#include <list>
#include <map>


enum GEM_TYPES {
	DIAMOND,   // diamond : Mosh level 10
	RUBY,      // Corundum: Mosh level 9
	SAPPHIRE,  // Corundum: Mosh level 9
	EMERALD    // beryl: Mosh level 8-7.5
};



enum GEM_PROPERTIES {
       CARAT,
       COLOR,
       CLARITY,
       CUT
};


enum GEM_CLARITY_LEVELS
{
	I3 = 1,
	I2,
	I1,
	SI2,
	SI1,
	VS2,
	VS1,
	VVS2,
	VVS1,
	IF,
	FL
};


enum DIAMOND_COLOR_LEVELS {  // COLOR_LESS is better
	LIGHT,           // 'T' to 'Z'
	VERY_LIGHT,	 //  'N' to 'S'
        FAINT,		 // 'K' to 'N'
	NEAR_COLORLESS,  // 'G' to 'J'
	COLOR_LESS       // 'D' to 'F'
};


enum RUBY_SAPPHIRE_EMERALD_COLOR_LEVELS { // An Hue, Saturation, Tone combination, with definied hue, high saturation  and tone are better.
	POOR_HST,        // 'T' to 'Z'
	FAIR_HST,	 //  'N' to 'S'
        GOOD_HST,	 // 'K' to 'N'
	VERY_GOOD_HST,   // 'G' to 'J'
	EXECELLENT_HST   // 'D' to 'F'
};



enum GEM_CUT_PROPORTION_LEVELS
{
        POOR=1,
	FAIR,
	GOOD,
	VERY_GOOD,
	EXCELLENT
};


enum GEM_SHAPES // assumed oval gems
{
	TRILLION=10,
	TRIANGLE=10,
	CUSHION=11,
	EMERALD_SHAPE=11,
	RECTANGLE=11,
	TAPERED_BAGUETTE=11,
	BAGUETTE=11,
	SQUARE_CUSHION=12,
	SQUARE_EMERALD=12,
	SQUARE=12,
	HEART=13,
	MARQUISE=13,
	PEAR=13,
        OVAL=13,
	ROUND=15
};


class Gem
{
public:
   unsigned int type;
   double carat;
   unsigned int color; // 'D' to 'Z'
   unsigned int clarity;
   unsigned int cut;  
   unsigned int shape;  
   

   Gem(unsigned int type, double carat, unsigned int color, unsigned int clarity, unsigned int cut, unsigned int shape){
   this->type=type;
   this->carat=carat;
   this->color=carat;
   this->clarity=carat;
   this->cut=carat;
   this->shape=shape;     
   }

  Gem()
  {
	Gem(SAPPHIRE, 1.0, 'J' ,VVS2 , GOOD, OVAL); // 1 ROUND SAPPHIRE 1 CARAT 'J' COLOR, VVS CLARITY AND 'J' CUT
  }


  double getGems(double bitgems);
  static double getGems (unsigned int type, double carat, unsigned int color, unsigned int clarity, unsigned int cut, unsigned int shape, double bitgems);	
   
};
