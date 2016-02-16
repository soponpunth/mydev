#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/asio.hpp>
#include <armadillo>

using namespace arma;

int main () {
  	boost::asio::io_service io;

  	mat A(5,5);  
  	A.eye();

	mat B = { {1, 3, 5},
          {2, 4, 6} };

  	std::cout << A << endl;
  	std::cout << B << endl;


  	return 0;
}
