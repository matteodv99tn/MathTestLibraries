#include "complex.hpp"

#include <iostream>

namespace math{

  using namespace std;

  Complex::Complex(){
    _real      = 0;
    _imaginary = 0;
  }

  Complex::Complex(const complex_type& real_part,
      const complex_type& imaginary_part){
    
    _real       = real_part;
    _imaginary  = imaginary_part;

  }

  Complex::Complex(const Complex& other){
    _real       = other.get_real_part();
    _imaginary  = other.get_imaginary_part();
  }

  complex_type Complex::get_real_part() const{
    return _real;
  }

  complex_type Complex::get_imaginary_part() const{
    return _imaginary;
  }

  void Complex::set_real_part(const complex_type& real_part){
    _real = real_part;
  }

  void Complex::set_imaginary_part(const complex_type& imaginary_part){
    _imaginary = imaginary_part;
  }

  Complex Complex::conjugate() const{
    return Complex(_real, -_imaginary);
  }

  Complex Complex::operator=(const Complex& other){
    return Complex(other.get_real_part(), other.get_imaginary_part());
  }

  ostream& operator<<(ostream& stream,
      const Complex& var){
    
    complex_type rp = var.get_real_part();
    complex_type ip = var.get_imaginary_part();

    if(rp != 0)
      stream << var.get_real_part();
    if(ip > 0)
      stream << "+i" << ip;
    else if (ip < 0)
      stream << "-i" << -ip;
    if(rp==0 && ip==0)
      stream << "0";

    return stream;
  }

  Complex Complex::operator+(const Complex& other) const{
    return Complex(_real + other.get_real_part(), 
        _imaginary + other.get_imaginary_part());
  }

  Complex& Complex::operator+=(const Complex& other){
    _real      += other.get_real_part();
    _imaginary += other.get_imaginary_part();
    return *this;
  }

  Complex Complex::operator-(const Complex& other) const{
    return Complex(_real - other.get_real_part(), 
        _imaginary - other.get_imaginary_part());
  }

  Complex& Complex::operator-=(const Complex& other){
    _real      -= other.get_real_part();
    _imaginary -= other.get_imaginary_part();
    return *this;
  }

  Complex Complex::operator*(const Complex& other) const{
    Complex res;

    res._real       = _real*other.get_real_part() - _imaginary*other.get_imaginary_part();
    res._imaginary  = _imaginary*other.get_real_part() + _real*other.get_imaginary_part();

    return res;
  }

  Complex& Complex::operator*=(const Complex& other){

    complex_type rp = _real;
    complex_type ip = _imaginary;

    _real       = rp*other.get_real_part() - ip*other.get_imaginary_part();
    _imaginary  = rp*other.get_imaginary_part() + ip*other.get_real_part();

    return *this;
  }

  Complex& Complex::operator*=(const complex_type& k){
    _real      *= k;
    _imaginary *= k;
    return *this;
  }

  Complex Complex::operator/(const Complex& other) const{
    Complex res(*this);

    res *= other.conjugate();
    res /= ( other.get_real_part()*other.get_real_part() - other.get_imaginary_part()*other.get_imaginary_part() );
    return res;
  }

  Complex operator*(const complex_type& k, const Complex& var){
    Complex res(var);
    res._real      *= k;
    res._imaginary *= k;
    return res;
  }

  Complex& Complex::operator/=(const complex_type& k){
    _real      /= k;
    _imaginary /= k;
    return *this;
  }

}
