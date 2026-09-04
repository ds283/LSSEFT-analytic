// Generated at 2026-Sep-04 05:49:54
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

   Pk_value P13 = Ptr_init * ((val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker0() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker1() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin)*ker.get_ker2() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin)*ker.get_ker3() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker4() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker5() + (val.D_lin*(val.fF*val.F+val.J*val.fJ))*ker.get_ker6() + (val.D_lin*val.G*val.fG)*ker.get_ker7() + (val.D_lin*val.G*val.fG)*ker.get_ker8() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker9() + (val.D_lin*(val.fF*val.F+val.J*val.fJ))*ker.get_ker2() + (val.E*val.fE*val.D_lin)*ker.get_ker7() + (val.E*val.fE*val.D_lin)*ker.get_ker10() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker11() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker12() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker13() + (val.J*val.D_lin*val.fJ)*ker.get_ker14() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker15());

   Pk_value P22 = (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker21() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker22() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker23() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker24();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker16() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker17() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker18() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker19() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker20());

   Pk_value P22 = (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker25() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker26() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker27() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker28();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13;   // no contribution at mu^6

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker29();

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker30() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker11() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker31() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker32());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker35();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker33() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker16() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker34() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker6() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker8());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker36() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker37();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_1_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker38();

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

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin))*ker.get_ker39() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker1() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker40());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker42() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker21() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker22();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b1_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * ((val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker7() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker2() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker41());

   Pk_value P22 = (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker28() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker43() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker25();

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

   Pk_value P13 = Ptr_init * (((val.J+val.F)*val.D_lin)*ker.get_ker6() + (val.E*val.D_lin)*ker.get_ker7() + ((val.J+val.D*-1.0)*val.D_lin)*ker.get_ker1() + (val.J*val.D_lin)*ker.get_ker14() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker32() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker44() + (val.D_lin*val.G)*ker.get_ker7() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker11() + (val.D_lin*val.G)*ker.get_ker8() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker45() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker46() + ((val.J+val.D*-1.0)*val.D_lin)*ker.get_ker47() + ((val.J+val.F)*val.D_lin)*ker.get_ker2() + (val.E*val.D_lin)*ker.get_ker10() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker30());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker48());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker50();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_b2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker49());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker51();

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker52() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker53() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker54());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker49());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker55());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker56();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_1_bG2_2_mu2(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^2

   Pk_value P13;   // no contribution at mu^2

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker57();

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker58() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker59() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker60());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker59() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker59() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker60() + (val.B*val.fB*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker61() + (val.fA*val.A*(val.D_lin*val.D_lin)*1.0/val.f_lin)*ker.get_ker62());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker58());

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

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker39() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker1() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker40());

   Pk_value P22 = (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker63() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker24() + (val.B*val.A*val.fB)*ker.get_ker64() + ((val.B*val.B)*val.fB)*ker.get_ker65() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker66() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker67() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker22() + (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker68() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker69() + (val.fA*(val.A*val.A))*ker.get_ker70() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker71() + (val.fA*val.B*val.A)*ker.get_ker64();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b1_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * ((val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker7() + (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker2() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker41());

   Pk_value P22 = (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker72() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker73() + (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker74();

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

   Pk_value P22 = (val.B*(val.D_lin*val.D_lin))*ker.get_ker71() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker24() + ((val.A*val.A))*ker.get_ker75() + (val.B*val.A)*ker.get_ker64() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker35() + ((val.B*val.B))*ker.get_ker76();

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

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker77() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker78() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker79();

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

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker80() + (val.B*(val.D_lin*val.D_lin))*ker.get_ker81() + (val.A*(val.D_lin*val.D_lin))*ker.get_ker82();

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

   Pk_value P13 = Ptr_init * (((val.J+val.D*-1.0)*val.D_lin*val.f_lin)*ker.get_ker1() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker32() + ((val.J+val.D*-1.0)*val.D_lin*val.f_lin)*ker.get_ker47() + (val.E*val.D_lin*val.f_lin)*ker.get_ker7() + (val.D_lin*val.G*val.f_lin)*ker.get_ker8() + (val.E*val.D_lin*val.f_lin)*ker.get_ker10() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker45() + (val.D_lin*val.G*val.f_lin)*ker.get_ker7() + (val.J*val.D_lin*val.f_lin)*ker.get_ker14() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker46() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker11() + ((val.J+val.F)*val.D_lin*val.f_lin)*ker.get_ker2() + ((val.J+val.F)*val.D_lin*val.f_lin)*ker.get_ker6() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker44() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker30());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker48());

   Pk_value P22 = (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker78() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker79() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker83() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker84();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_b2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker49());

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker85();

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

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker86();

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

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker87();

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

   Pk_value P13 = Ptr_init * ((val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker53() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker52() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker54());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker49());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker55());

   Pk_value P22 = (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker81() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker82() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker88() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker89();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_bG2_2_mu4(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^4

   Pk_value P13;   // no contribution at mu^4

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker90();

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

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin))*ker.get_ker91();

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker58() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker59() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker60());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker59() + (val.B*val.fB*(val.D_lin*val.D_lin))*ker.get_ker61() + (val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker59() + (val.B*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker60() + (val.fA*val.A*(val.D_lin*val.D_lin))*ker.get_ker62());

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

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker58());

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

   Pk_value P13 = Ptr_init * ((val.D_lin*val.G*val.f_lin*val.fG)*ker.get_ker7() + (val.D_lin*(val.fF*val.F+val.J*val.fJ)*val.f_lin)*ker.get_ker6() + (val.B*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker0() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker9() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker33() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin*val.f_lin)*ker.get_ker2() + (val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker1() + (val.D_lin*val.G*val.f_lin*val.fG)*ker.get_ker8() + (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker5() + (val.E*val.fE*val.D_lin*val.f_lin)*ker.get_ker7() + (val.E*val.fE*val.D_lin*val.f_lin)*ker.get_ker10() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker92() + (val.J*val.D_lin*val.fJ*val.f_lin)*ker.get_ker14() + (val.D_lin*(val.fF*val.F+val.J*val.fJ)*val.f_lin)*ker.get_ker2() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker6() + ((val.D*val.fD+val.J*val.fJ*-1.0)*val.D_lin*val.f_lin)*ker.get_ker3() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker12());

   Pk_value P22 = ((val.fA*val.fA)*(val.A*val.A))*ker.get_ker75() + (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker68() + (val.fA*val.B*val.A*val.fB)*ker.get_ker64() + (val.fA*val.A*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker69() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker75() + ((val.B*val.B)*(val.fB*val.fB))*ker.get_ker76() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker96() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker63() + (val.B*val.fB*(val.D_lin*val.D_lin)*val.f_lin)*ker.get_ker67() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker97();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu6(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^6

   Pk_value P13 = Ptr_init * (((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker34() + (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker93() + (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker94() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker95());

   Pk_value P22 = (val.B*val.fB*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker72() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin))*ker.get_ker98() + (val.fA*val.A*(val.D_lin*val.D_lin)*(val.f_lin*val.f_lin))*ker.get_ker74() + ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker99();

   return rsd_dd_Pk{tree, P13, P22};
 }

rsd_dd_Pk compute_nobias_mu8(const Mpc_units::energy& k, const oneloop_growth_record& val, const loop_integral& loop_data, const Pk_value& Ptr_init, const boost::optional<Pk_value>& Ptr_final)
 {
   const kernels& ker = loop_data.get_kernels();

   Pk_value tree;   // no contribution at mu^8

   Pk_value P13;   // no contribution at mu^8

   Pk_value P22 = ((val.D_lin*val.D_lin*val.D_lin*val.D_lin)*(val.f_lin*val.f_lin*val.f_lin*val.f_lin))*ker.get_ker100();

   return rsd_dd_Pk{tree, P13, P22};
 }

