#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment);
    // virtual destructor
    virtual ~LookupTable() = default;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
    protected:
    int a;
    double m_start;
    double m_end;
    double m_increment;
    double *x1;
    double *y1;
};

LookupTable::LookupTable(double start, double end, double increment){
    m_start=start;
    m_end=end;
    m_increment=increment;
    vector <double> x1((end-start)/increment);
    vector <double> y1((end-start)/increment);
}
class SquareLookupTable : public LookupTable
{
    // Your code here.
    public:
    SquareLookupTable(double start, double end, double increment) :LookupTable(start, end, increment) {};
    virtual ~SquareLookupTable() = default;
    double getValue(double x){
        size_t i=1;
        x1[0]=m_start;
        y1[0]=pow(x1[0],2);
        while(i<=(m_end-m_start)/m_increment){
            x1[i]=x1[i-1]+m_increment;
            y1[i]=pow(x1[i],2);
            i++;
        }
        i=0;
        while(i<=(m_end-m_start)/m_increment){
            if(x==x1[i]){
                return y1[i];
            }
            i++;
        }
        i=0;
        while(i<(m_end-m_start)/m_increment){
            if(x>x1[i]&&x<x1[i+1]){
                return (((x-x1[i])*y1[i+1]+(x1[i+1]-x)*y1[i])/(x1[i+1]-x1[i]));
            }
            i++;
        }
        return 0;
    }
};


class SinLookupTable : public LookupTable
{
    // Your code here.
     public:
    SinLookupTable(double start, double end, double increment) :LookupTable(start, end, increment) {};
    virtual ~SinLookupTable() = default;
   
    double getValue(double x){
       
        size_t i=1;
        x1[0]=m_start;
        y1[0]=sin(x1[i]);
        while(i<=(m_end-m_start)/m_increment){
            x1[i]=x1[i-1]+m_increment;
            y1[i]=sin(x1[i]);
            i++;
        }
        i=0;
        while(i<=(m_end-m_start)/m_increment){
            if(x==x1[i]){
                return y1[i];
            }
            i++;
        }
        i=0;
        while(i<(m_end-m_start)/m_increment){
            if(x>x1[i]&&x<x1[i+1]){
                return (((x-x1[i])*y1[i+1]+(x1[i+1]-x)*y1[i])/(x1[i+1]-x1[i]));
            }
            i++;
    }
       return 0;
    }
};

class LogLookupTable : public LookupTable
{
    // Your code here.
     public:
    LogLookupTable(double start, double end, double increment) :LookupTable(start, end, increment) {};
    virtual ~LogLookupTable() = default;
   
    double getValue(double x){
      
        size_t i=1;
        x1[0]=m_start;
        y1[0]=log(x1[0]);
        while(i<=(m_end-m_start)/m_increment){
            x1[i]=x1[i-1]+m_increment;
            y1[i]=log(x1[i]);
            i++;
        }
        i=0;
        while(i<=(m_end-m_start)/m_increment){
            if(x==x1[i]){
                return y1[i];
            }
            i++;
        }
        i=0;
        while(i<(m_end-m_start)/m_increment){
            if(x>x1[i]&&x<x1[i+1]){
                return (((x-x1[i])*y1[i+1]+(x1[i+1]-x)*y1[i])/(x1[i+1]-x1[i]));
            }
            i++;
    }
       return 0;
    }
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    // Your code here.
    SquareLookupTable aa(9,1,-2);
    double aaa=aa.getValue(4);
    cout<<aaa;
    return 0;
}
