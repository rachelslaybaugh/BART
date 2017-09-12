#ifndef __ig_base_h__
#define __ig_base_h__

#include "ig_base.h"

template <int dim>
class IGBase : public IterationBase<dim>
{
public:
  IGBase (ParameterHandler &prm);
  virtual ~IGBase();
  
  // has to be provided
  virtual void solve_ig
  (std::vector<Vector<double> > &sflxes_proc,
   std_cxx11::shared_ptr<EquationBase<dim> > equ_ptrs,
   unsigned int &g);
  
protected:
  const double err_phi_tol;
  
  Vector<double> sflx_proc_prev_ig;
};

template <int dim>
class SourceIteration : public IGBase<dim>
{
public:
  SourceIteration (ParameterHandler &prm);
  ~SourceIteration ();
  
  void solve_ig
  (std::vector<Vector<double> > &sflxes_proc,
   std_cxx11::shared_ptr<EquationBase<dim> > equ_ptrs,
   unsigned int &g);
};

#endif //__ig_base_h__