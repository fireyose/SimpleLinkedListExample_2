/*************************************************************************************
Implemention file for the rational class.
FILENAME: rational.cpp

See rational.h for documentation.

Author: Dr. Greg Schaper
Modification History:
Created on 9/10/2010
Modified on 9/20/2012 to include type cast for rational to char conversion.
11/6/2012: add code for new print methods
 *************************************************************************************/
#include<cmath>  // need for abs() function
#include<iomanip> // need for print methods


rational::rational(IntegerType n):numerator(n), denominator(1)
{
  infinity = false;
  signInfinity = '+';
  normalize();
}


rational::rational(IntegerType n, IntegerType d):numerator(n), denominator(d)
{
  infinity = false;
  signInfinity = '+';
  normalize();
}




rational::rational(const rational &r)
{
  numerator = r.numerator;
  denominator = r.denominator;
  infinity = r.infinity;
  signInfinity = r.signInfinity;

}



rational::~rational()
{
  /* nothing to do */
}


rational rational::operator =(rational r)
{
  infinity = r.infinity;
  signInfinity = r.signInfinity;
  numerator = r.numerator;
  denominator = r.denominator;
  return(*this);
}



rational::operator double()
{
  double d;
  if(!infinity)
    {
      d = static_cast<double>(numerator) / static_cast<double>(denominator);
    }
  else
    {
      // need to fix this later to return IEEE representaion of infinity
      d = 0.0;
    }
  return d;
}


rational::operator int()
{
  IntegerType number;
  if(!infinity)
    {
      number = numerator / denominator;
    }
  else
    {
      // need to fix this later ... maybe abort the program to indicate an error has occured
      number = 0;
    }
  return(number);
}


rational::operator char()
{
  const char asciiA = 'A';
  char result;
  if(!infinity)
    {
      result = static_cast<char>((abs(numerator/denominator) % 26) + asciiA);
    }
  else
    {
      // need to fix this later ... maybe abort the program to indicate an error has occured
      result = signInfinity;
    }
  return(result);
}



rational rational::operator +(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator + rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();

  return temp;
}


rational rational::operator -(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator - rhs.numerator*denominator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator *(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.numerator;
  temp.denominator = denominator*rhs.denominator;
  temp.normalize();
  return temp;
}


rational rational::operator /(rational rhs) const
{
  rational temp;
  temp.numerator = numerator*rhs.denominator;
  temp.denominator = denominator*rhs.numerator;
  temp.normalize();
  return temp;
}


rational rational::operator +=(rational rhs)
{
  *this = *this + rhs;
  return(*this);
}



rational rational::operator -=(rational rhs)
{
  *this = *this - rhs;
  return(*this);
}


rational rational::operator *=(rational rhs)
{
  *this = *this * rhs;
  return(*this);
}


rational rational::operator /=(rational rhs)
{
  *this = *this / rhs;
  return(*this);
}


bool rational::operator ==(rational rhs) const
{
  return (numerator*rhs.denominator == rhs.numerator*denominator);
}


bool rational::operator !=(rational rhs) const
{
  return (numerator*rhs.denominator != rhs.numerator*denominator);
}


bool rational::operator <(rational rhs) const
{
  return (numerator*rhs.denominator < rhs.numerator*denominator);
}


bool rational::operator >(rational rhs) const
{
  return (numerator*rhs.denominator > rhs.numerator*denominator);
}


bool rational::operator >=(rational rhs) const
{
  return(!(*this < rhs));
}


bool rational::operator <=(rational rhs) const
{
  return(!(*this > rhs));
}


// Unary Operators
rational rational::operator++() // prefix form
{
  numerator += denominator;

  return (*this);
};


rational rational::operator++(int) // postfix form
{
  rational result = *this;
  numerator += denominator;
  return result;
};


rational rational::operator--() // prefix form
{
  numerator -= denominator;
  return (*this);
};


rational rational::operator--(int) // postfix form
{
  rational result = *this;
  numerator -= denominator;
  return result;
};


rational rational::operator+() const
{
  return(*this);
};


rational rational::operator-() const
{
  rational result(-numerator, denominator);
  return (result);
};


bool rational::operator!() const
{
  // return true if the this rational is zero.

  return(numerator==0);
};


void rational::printFraction(std::ostream& outstream, char delimiter) const
{
  IntegerType n, d;
  n = getNumerator();
  d = getDenominator();
  if(!infinity)
    {
      outstream << n << '/' << d;
    }
  else
    {
      outstream << signInfinity  << "infinity";
    }
}



void rational::printDecimal(std::ostream& outstream, char delimiter) const
{
  IntegerType w, n, d;
  rational temp(*this);
  rational zero(0,1);
  if(!temp.infinity)
    {
      if(temp < zero)
	  {
	     rational absTemp(-temp);
          w = absTemp.numerator / absTemp.denominator;
          n = absTemp.numerator - (absTemp.denominator*w);
          d = absTemp.denominator;
          w = w * (-1);
	  }
      else
	  {
          w = temp.numerator / temp.denominator;
          n = temp.numerator - (temp.denominator*w);
          d = temp.denominator;
	  }
      rational fraction(n,d);      
      outstream << w << ' ';
      fraction.printFraction(outstream, delimiter);
    }
  else
    {
      {
	    outstream << temp.signInfinity  << "infinity";
      }
    }
}



void rational::printDouble(std::ostream& outstream, char delimiter) const
{
  double value;
  rational temp(*this);
  if(!infinity)
    {
      //      value = static_cast<double>(numerator) / static_cast<double>(denominator);
      value = (double)temp; 
      outstream << std::fixed << std::setprecision(12) << value << delimiter;
    }
  else
    {
      outstream << signInfinity  << "infinity";
    }
}




/**************************************************************************
PROTECTED MEMBER FUNCTIONS
*************************************************************************/

IntegerType rational::getNumerator() const
{
  return(numerator);
}


IntegerType rational::getDenominator() const
{
  return(denominator);
}


void rational::setRational(IntegerType n, IntegerType d)
{
  numerator = n;
  denominator = d;
  normalize();
}






/**************************************************************************
PRIVATE MEMBER FUNCTIONS
 *************************************************************************/

void rational::normalize()
{
  if(denominator == 0) // rational represents infinity
    {
      if(numerator >= 0)
	   {
	     numerator = 1; // represents positive infinity
          infinity = true;
          signInfinity = '+';
	   }
      else
	   {
	      numerator = -1; // represents negative infinity
          infinity = true;
          signInfinity = '-';
	   }
    }
  else
    {
      // set the sign of the numerator
      setSign();
      // reduce fraction to lowest terms
      if((numerator != 0) && (denominator !=0))
	  reduce();
    }

};


void rational::setSign()
{
  if(denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    }
}


void rational::reduce()
{
  IntegerType gcd;
  IntegerType small, large;
  bool positiveRational;
  
  positiveRational = (numerator >=0);

  if(!positiveRational)
      numerator = -1*numerator;

  if(numerator <= denominator)
    {
      small = numerator;
      large = denominator;
    }
  else
    {
      small = denominator;
      large = numerator;
    }
  
  gcd = greatestCommonDivisor(large, small);

  numerator = numerator / gcd;
  denominator = denominator / gcd;
  
  if(!positiveRational)
    numerator = -1*numerator;
}


IntegerType rational::greatestCommonDivisor(IntegerType a, IntegerType b)
{
  IntegerType r, x, y;
  x = a;
  y = b;
  while(y!=0)
    {
      r = x % y;
      x = y;
      y = r;
    }
  return x;
}



/***********************************************************************
NON MEMBER FUNCTIONS
 **********************************************************************/

std::ostream& operator <<(std::ostream& outstream, rational r)
{
  r.printDecimal(outstream, ',');
  return outstream;
}


std::istream& operator >>(std::istream& instream, rational &r)
{
  IntegerType temp1, temp2;
  char ch;
  
  instream >> temp1;
  instream >> ch;
  instream >> temp2;
  rational temp(temp1, temp2);
  r = temp;

  return instream;
}
