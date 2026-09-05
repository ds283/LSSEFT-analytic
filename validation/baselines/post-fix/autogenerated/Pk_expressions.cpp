// Generated at 2026-Sep-05 21:02:09
//
rsd_dd_Pk compute_b1_1_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree = ((val.D_lin*val.D_lin)*val.f_lin*2.0) * (Ptr_final ? *Ptr_final : Ptr_init);

   Pk_value P13 = Ptr_init * (((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin)*ker.get_ker77() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin)*ker.get_ker89() + (val.D_lin*(val.fF*val.F+val.J*val.fJ))*ker.get_ker77() + (val.D_lin*(val.fF*val.F+val.J*val.fJ))*ker.get_ker51() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker47() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker83() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker43() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker67() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker85() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker46() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker34() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker78() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker63() + (val.E*val.fE*val.D_lin)*ker.get_ker80() + (val.E*val.fE*val.D_lin)*ker.get_ker88() + (val.D_lin*val.G*val.fG)*ker.get_ker80() + (val.D_lin*val.G*val.fG)*ker.get_ker61() + (val.J*val.D_lin*val.fJ)*ker.get_ker64());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker48() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker5() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker1() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker35();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * ((val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker42() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker66() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker81() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker62() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker99());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker73() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker12() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker27() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker28();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker11();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree = ((val.D_lin*val.D_lin)) * (Ptr_final ? *Ptr_final : Ptr_init);

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker78() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker56() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker37() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker36());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker54();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker51() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker61() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker100() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker81() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker32());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker58() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker71();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker45();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker83() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker82() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker79());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker33() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker48() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker5();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker77() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker80() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker86());

   Pk_value P22 = (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker73() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker12() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker76();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker78() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker37() + ((val.J+val.D*-1.0)*val.D_lin)*ker.get_ker83() + ((val.J+val.D*-1.0)*val.D_lin)*ker.get_ker90() + ((val.J+val.F)*val.D_lin)*ker.get_ker77() + ((val.J+val.F)*val.D_lin)*ker.get_ker51() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker56() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker53() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker87() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker84() + (val.E*val.D_lin)*ker.get_ker80() + (val.E*val.D_lin)*ker.get_ker88() + (val.D_lin*val.G)*ker.get_ker80() + (val.D_lin*val.G)*ker.get_ker61() + (val.J*val.D_lin)*ker.get_ker64());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker91());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker74();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker93());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker72();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker98() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker95() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker97());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker93());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker96());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker7();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker13();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker92() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker60() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker68());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bGamma3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker60() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker41() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker65() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker60() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker68());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bGamma3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bGamma3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bGamma3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bGamma3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bdG2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker92());

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bdG2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bdG2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bdG2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bdG2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker82() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker79() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker83());

   Pk_value P22 = (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker2() + (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker16() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker31() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker35() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker21() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker22() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker20() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker48() + (val.fA*(val.A*val.A))*ker.get_ker49() + ((val.B*val.B)*val.fB)*ker.get_ker14() + (val.fA*val.B*val.A)*ker.get_ker4() + (val.B*val.A*val.fB)*ker.get_ker4();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker77() + (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker80() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker86());

   Pk_value P22 = (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker26() + (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker8() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker9();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b1_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker54() + ((val.A*val.A))*ker.get_ker55() + ((val.B*val.B))*ker.get_ker15() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker35() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker22() + (val.B*val.A)*ker.get_ker4();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b1_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b1_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b1_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b1_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker70() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker75() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker50();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_b2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_bG2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker24() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker6() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker25();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_bG2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_bG2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.J+val.D*-1.0)*val.D_lin*val.f_lin)*ker.get_ker83() + ((val.J+val.D*-1.0)*val.D_lin*val.f_lin)*ker.get_ker90() + ((val.J+val.F)*val.D_lin*val.f_lin)*ker.get_ker77() + ((val.J+val.F)*val.D_lin*val.f_lin)*ker.get_ker51() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker87() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker56() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker84() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker53() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker78() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker37() + (val.E*val.D_lin*val.f_lin)*ker.get_ker80() + (val.E*val.D_lin*val.f_lin)*ker.get_ker88() + (val.D_lin*val.G*val.f_lin)*ker.get_ker80() + (val.D_lin*val.G*val.f_lin)*ker.get_ker61() + (val.J*val.D_lin*val.f_lin)*ker.get_ker64());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker91());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker75() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker50() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker57() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker69();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker93());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker44();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_b2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker94();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_b2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_b2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_b2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_b2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_bG2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker52();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_bG2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_bG2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker95() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker97() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker98());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker93());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker96());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker6() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker25() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker30() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker23();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker0();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_bG2_2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker17();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_bG2_2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_bG2_2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker60() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker68() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker92());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bGamma3_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bGamma3_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker60() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker41() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker68() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker65() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker60());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bGamma3_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bGamma3_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bGamma3_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bdG2_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bdG2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker92());

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bdG2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22;   // no contribution at mu^4

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bdG2_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22;   // no contribution at mu^6

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bdG2_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22;   // no contribution at mu^8

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu0(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^0

   Pk_value P13;   // no contribution at mu^0

   Pk_value P22;   // no contribution at mu^0

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22;   // no contribution at mu^2

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree = ((val.D_lin*val.D_lin)*(val.f_lin*val.f_lin)) * (Ptr_final ? *Ptr_final : Ptr_init);

   Pk_value P13 = Ptr_init * (((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin*val.f_lin)*ker.get_ker77() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin*val.f_lin)*ker.get_ker89() + (val.D_lin*(val.fF*val.F+val.J*val.fJ)*val.f_lin)*ker.get_ker77() + (val.D_lin*(val.fF*val.F+val.J*val.fJ)*val.f_lin)*ker.get_ker51() + (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker47() + (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker83() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker67() + (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker85() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker32() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker39() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker51() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker34() + (val.E*val.fE*val.D_lin*val.f_lin)*ker.get_ker80() + (val.E*val.fE*val.D_lin*val.f_lin)*ker.get_ker88() + (val.D_lin*val.G*val.f_lin*val.fG)*ker.get_ker80() + (val.D_lin*val.G*val.f_lin*val.fG)*ker.get_ker61() + (val.J*val.D_lin*val.fJ*val.f_lin)*ker.get_ker64());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker2() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker16() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker31() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker21() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker55() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker19() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker18() + ((val.fA*val.fA)*(val.A*val.A))*ker.get_ker55() + ((val.B*val.B)*(val.fB*val.fB))*ker.get_ker15() + (val.fA*val.B*val.A*val.fB)*ker.get_ker4();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13 = Ptr_init * ((val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker40() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker38() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker59() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker100());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker26() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker8() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker10() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker3();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker29();

   return rsd_dd_Pk{tree, P13, P22};
 }

