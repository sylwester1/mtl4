// Software License for MTL
// 
// Copyright (c) 2007 The Trustees of Indiana University.
//               2008 Dresden University of Technology and the Trustees of Indiana University.
//               2010 SimuNova UG (haftungsbeschränkt), www.simunova.com.
// All rights reserved.
// Authors: Peter Gottschling and Andrew Lumsdaine
// 
// This file is part of the Matrix Template Library
// 
// See also license.mtl.txt in the distribution.

#include <iostream>
#include <boost/numeric/mtl/mtl.hpp>
#include <boost/numeric/itl/itl.hpp>


int main()
{
    mtl::vampir_trace<9999> tracer;
  // For a more realistic example set size to 1000 or larger
  const int size = 10, N = size * size;

  typedef mtl::compressed2D<double>  matrix_type;
  mtl::compressed2D<double>          A(N, N);
  laplacian_setup(A, size, size);

  itl::pc::identity<matrix_type>     P(A);

  mtl::dense_vector<double> x(N, 1.0), b(N);

  b = A * x;
  x= 0;
  itl::cyclic_iteration<double> iter(b, 100, 1.e-11, 0.0, 5);
  cg(A, x, b, P, iter);

  return 0;
}
