#include "complex_num.h"
#include <math.h>

complex_num::complex_num(double r, double i){
    // Write your code here
    this->r = r;
    this->i = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here
    z.r = this->r + w.r;
    z.i = this->i + w.i;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z.r = this->r - w.r;
    z.i = this->i - w.i;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here
    z.r = (this->r * w.r - this->i * w.i);
    z.i = (this->r * w.i + this->i * w.r);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    double divisor = (w.r*w.r) + (w.i*w.i);
    // Write your code here
    z.r = ((this->r * w.r + this->i * w.i) / divisor);
    z.i = ((this->i * w.r + this->r * w.i) / divisor);
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    if(this->i < 0)
    {
        os << this->r << " - i" << this->i*-1;
    }
    else
    {
        os << this->r << " + i" << this->i;
    }
    os << std::flush;
}