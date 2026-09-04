// Generated at 2026-Sep-04 05:49:54
//
static int ker99_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_*z_*z_)*1575.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*225.0+(z_*z_)*270.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-104.0+1.0/q_*k_*z_*-108.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*1332.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-302.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*696.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-1620.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-1800.0+1.0/(q_*q_)*(k_*k_)*-2.0+-90.0)*(k_*k_*k_*k_)*-(1.0/420.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker98_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*30.0+(z_*z_)*-45.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-90.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*123.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-51.0+1.0/q_*k_*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*96.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*114.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*11.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-42.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-45.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*39.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-90.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-90.0+1.0/(q_*q_)*(k_*k_)*2.0+15.0)*(k_*k_)*(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker21_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*-(2.0/5.0)+(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(82.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(32.0/15.0)+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(8.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(7.0/6.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(43.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*(2.0/5.0)+(q_*q_)*(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-(2.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*-(7.0/6.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-6.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker96_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*20.0+(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*81.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-27.0+1.0/q_*k_*z_*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*12.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*38.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*17.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-54.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-27.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-30.0+1.0/(q_*q_)*(k_*k_)*-6.0+5.0)*(k_*k_)*-(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker92_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-1.0+(q_*q_)*k_*z_*2.0+q_*(k_*k_)*(z_*z_)*-2.0+(q_*q_)*k_*(z_*z_*z_))*-8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker93_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = ((q_*q_)*k_+(q_*q_*q_)*z_*-1.0+(q_*q_)*k_*(z_*z_*z_*z_)*-3.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_+(q_*q_)*k_*(z_*z_)*-4.0+q_*(k_*k_)*(z_*z_*z_)*5.0)*1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker95_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*((q_*q_)*k_*2.0+(q_*q_*q_)*z_*-1.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_*3.0+(q_*q_)*k_*(z_*z_)*-8.0+q_*(k_*k_)*(z_*z_*z_)*3.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker87_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(8.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(4.0/3.0)+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(2.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+(q_*q_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker85_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(q_+k_*z_*2.0+q_*(z_*z_)*-3.0)*(k_*k_)*-1.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker84_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*-(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker72_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*48.0+(z_*z_)*-315.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*114.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*3150.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-1335.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*487.0+1.0/q_*k_*z_*-210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-1260.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*144.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*-1470.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-2520.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*445.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-734.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*430.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-315.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-1080.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-2175.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-630.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*3150.0+1.0/(q_*q_)*(k_*k_)*-42.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*2880.0+105.0)*(1.0/420.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker83_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-3.0+-1.0)*(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker12_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker78_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(8.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(4.0/3.0)+q_*k_*z_*4.0+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(11.0/6.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*5.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker60_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*16.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker74_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*30.0+(z_*z_)*-45.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-90.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*123.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-51.0+1.0/q_*k_*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*96.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*114.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*11.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-42.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-45.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*39.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-90.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-90.0+1.0/(q_*q_)*(k_*k_)*2.0+15.0)*(k_*k_)*-(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker80_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)*(2.0/5.0)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(54.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(24.0/5.0)+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*-(2.0/5.0)+(q_*q_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(2.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*11.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker86_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (q_*q_);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker71_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*(2.0/5.0)+(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(82.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(32.0/15.0)+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(8.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(7.0/6.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(43.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*-(2.0/5.0)+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(2.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(7.0/6.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*6.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker68_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*20.0+(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*81.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-27.0+1.0/q_*k_*z_*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*12.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*38.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*17.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-54.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-27.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-30.0+1.0/(q_*q_)*(k_*k_)*-6.0+5.0)*(k_*k_)*(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker88_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*140.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-24.0+(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*272.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*195.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-9.0+1.0/q_*k_*z_*84.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*96.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*61.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-144.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*72.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-216.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-94.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-393.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*210.0+1.0/(q_*q_)*(k_*k_)*-70.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*240.0+35.0)*(k_*k_)*-(1.0/105.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker67_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*(2.0/5.0)+(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(2.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(8.0/15.0)+q_*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(8.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(5.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(43.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*-(2.0/5.0)+(q_*q_)*(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(2.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(7.0/6.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker66_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*20.0+(z_*z_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-27.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*9.0+1.0/q_*k_*z_*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*14.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-19.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*10.0+1.0/(q_*q_)*(k_*k_)*2.0+-15.0)*(k_*k_)*(1.0/20.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker65_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*(z_*z_*z_)*480.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*-765.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,6)*z_*192.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,7)*-48.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*1050.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*-1470.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*342.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*350.0+k_*140.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*87.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-765.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*(z_*z_)*-432.0+q_*z_*210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*80.0+1.0/q_*(k_*k_)*z_*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*-66.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*390.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_*z_*z_)*-420.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-90.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*1050.0+1.0/(q_*q_)*(k_*k_*k_)*-42.0+k_*(z_*z_)*-525.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-735.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*245.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*315.0)*-(2.0/105.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker77_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*-(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker64_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*-(2.0/5.0)+(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(2.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(8.0/15.0)+q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(8.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(5.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(43.0/15.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*(2.0/5.0)+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-(2.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*-(7.0/6.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker55_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*(32.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker62_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*-8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker76_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*(z_*z_*z_)*480.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*-765.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,6)*z_*192.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,7)*-48.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*1050.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*-1470.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*342.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*350.0+k_*140.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*87.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-765.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*(z_*z_)*-432.0+q_*z_*210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*80.0+1.0/q_*(k_*k_)*z_*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*-66.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*390.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_*z_*z_)*-420.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-90.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*1050.0+1.0/(q_*q_)*(k_*k_*k_)*-42.0+k_*(z_*z_)*-525.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-735.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*245.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*315.0)*-(1.0/105.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker58_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*-(32.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker57_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*96.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*150.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-54.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-64.0+k_*25.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-27.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-98.0+q_*z_*-90.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*19.0+1.0/q_*(k_*k_)*z_*34.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*82.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-24.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-60.0+1.0/(q_*q_)*(k_*k_*k_)*-24.0+k_*(z_*z_)*-30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*40.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-105.0)*k_*(1.0/15.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker7_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(16.0/3.0)+(q_*q_)*-(16.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker18_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_*q_)*k_*z_*5.0+(q_*q_*q_)*k_*(z_*z_*z_)*-1.0+(q_*q_)*(k_*k_)*-3.0+(q_*q_*q_*q_)*(z_*z_)*-2.0+(k_*k_*k_*k_)*(z_*z_)*2.0+q_*(k_*k_*k_)*(z_*z_*z_)*-5.0+(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*3.0+q_*(k_*k_*k_)*z_)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker56_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-1.0+1.0/(q_*q_)*(k_*k_*k_*k_)*-(2.0/5.0)+(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(54.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(24.0/5.0)+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*(2.0/5.0)+(q_*q_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-(2.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-11.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker54_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*(64.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker97_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_*k_*k_)*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*(k_*k_*k_*k_)*12.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_)*-150.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_)*40.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*z_*72.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*(z_*z_)*108.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*-20.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*(z_*z_*z_)*-120.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*-36.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*k_*z_*-80.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*(k_*k_*k_)*z_*-48.0+1.0/(q_*q_)*28.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_*z_*z_)*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(z_*z_)*60.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*57.0)*(1.0/280.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker69_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-4.0+k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*2.0+k_*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-6.0)*(2.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker52_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker19_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_)*(k_*k_)*(z_*z_)*6.0+(q_*q_*q_)*k_*z_*7.0+(q_*q_*q_)*k_*(z_*z_*z_)*-3.0+(q_*q_)*(k_*k_)*-6.0+(q_*q_*q_*q_)*(z_*z_)*-2.0+(k_*k_*k_*k_)*(z_*z_)*2.0+q_*(k_*k_*k_)*(z_*z_*z_)*-3.0+q_*(k_*k_*k_)*z_*-1.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker75_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-4.0+k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*2.0+k_*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-6.0)*-(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker82_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-1.0+1.0/(q_*q_)*(k_*k_*k_*k_)*-(2.0/5.0)+(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(82.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(32.0/15.0)+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*(2.0/5.0)+(q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-(2.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-3.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker51_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*z_*-1.0+z_*-1.0)*k_*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker50_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker90_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*70.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*4.0+(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*35.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*34.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-9.0+1.0/q_*k_*z_*14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*12.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*61.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-102.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-90.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-183.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*240.0+35.0)*(1.0/35.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker49_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker48_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*-8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker2_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(8.0/3.0)+(q_*q_)*-(8.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker44_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*(16.0/3.0)+(q_*q_)*(80.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker42_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(8.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(4.0/3.0)+q_*k_*z_*4.0+(k_*k_)*(4.0/3.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(8.0/3.0)+(q_*q_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(2.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker39_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(8.0/3.0)+(q_*q_)*-(56.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker100_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(q_*k_*(z_*z_*z_)*40.0+(q_*q_)*(z_*z_)*30.0+(k_*k_)*(z_*z_)*-12.0+q_*k_*z_*-24.0+(k_*k_)*4.0+(q_*q_)*(z_*z_*z_*z_)*-35.0+(q_*q_)*-3.0)*-(1.0/8.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker38_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*2.0+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0)*-(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker32_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*((q_*q_)*(z_*z_)+(k_*k_)*(z_*z_)+q_*k_*z_*-3.0+(q_*q_*q_)*1.0/k_*z_*-1.0+(q_*q_)*2.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker37_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(k_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*8.0+q_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*3.0+k_*(z_*z_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*6.0)*-(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker91_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*12.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*2.0+1.0/(q_*q_)*(k_*k_*k_*k_)*(8.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*(z_*z_*z_)*-(32.0/7.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,7)*z_*-(64.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_*z_*z_)*4.0+(k_*k_)*(z_*z_)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(8.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(164.0/105.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-8.0+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(444.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*(96.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(6.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(48.0/35.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(4.0/3.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,8)*(16.0/35.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-(12.0/7.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(256.0/35.0)+1.0/q_*(k_*k_*k_)*z_*-(16.0/5.0)+(q_*q_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(72.0/35.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(z_*z_)*(144.0/35.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker17_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_)*(k_*k_)*(z_*z_)*6.0+(q_*q_*q_)*k_*z_*7.0+(q_*q_*q_)*k_*(z_*z_*z_)*-3.0+(q_*q_)*(k_*k_)*-6.0+(q_*q_*q_*q_)*(z_*z_)*-2.0+(k_*k_*k_*k_)*(z_*z_)*2.0+q_*(k_*k_*k_)*(z_*z_*z_)*-3.0+q_*(k_*k_*k_)*z_*-1.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker13_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_*2.0+(q_*q_*q_*q_)*1.0/k_*z_+(q_*q_*q_)*(z_*z_)*-4.0+q_*(k_*k_)*-2.0+(q_*q_)*k_*z_*6.0+q_*(k_*k_)*(z_*z_)*-5.0+(q_*q_*q_)*-1.0+(q_*q_)*k_*(z_*z_*z_)*3.0)*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker35_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(2.0/3.0)+q_*k_*z_*-2.0+(k_*k_)*-(2.0/3.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(2.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(4.0/3.0)+(q_*q_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*-(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker70_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-4.0+k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*2.0+k_*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-6.0)*-(2.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker45_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(q_*k_*(z_*z_*z_)+(q_*q_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-1.0+q_*k_*z_*2.0+(q_*q_*q_)*1.0/k_*z_+(q_*q_)*-1.0)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker27_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(z_*z_*z_)*90.0+1.0/q_*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*48.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*(z_*z_)*-48.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*z_*-63.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*z_*-54.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_)*-12.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_)*z_*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(z_*z_*z_)*90.0+1.0/(q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*(z_*z_)*-114.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*19.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_)*z_*51.0)*-(1.0/30.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker31_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(q_*k_*(z_*z_*z_)+(q_*q_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-1.0+q_*k_*z_*2.0+(q_*q_*q_)*1.0/k_*z_+(q_*q_)*-1.0)*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker94_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*((q_*q_)*k_*2.0+(q_*q_*q_)*z_*-1.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_*3.0+(q_*q_)*k_*(z_*z_)*-8.0+q_*(k_*k_)*(z_*z_*z_)*3.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker25_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(k_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*8.0+q_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*3.0+k_*(z_*z_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-6.0)*-(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker61_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*-16.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker79_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker30_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*((q_*q_)*(z_*z_)+(k_*k_)*(z_*z_)+q_*k_*z_*-3.0+(q_*q_*q_)*1.0/k_*z_*-1.0+(q_*q_)*2.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker28_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*192.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*255.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-108.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-98.0+k_*-20.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*16.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*-20.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-131.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-141.0+q_*z_*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*-22.0+1.0/q_*(k_*k_)*z_*48.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*36.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*124.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-38.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-120.0+1.0/(q_*q_)*(k_*k_*k_)*-38.0+k_*(z_*z_)*75.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*150.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-40.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-45.0)*k_*(1.0/30.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker20_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(8.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker46_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*(8.0/3.0)+(q_*q_)*(56.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker36_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*2.0+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0)*(k_*k_)*(1.0/6.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker24_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(8.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(4.0/3.0)+(k_*k_)*(4.0/3.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*(8.0/3.0)+(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(2.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker14_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_+q_*z_*-1.0+k_*(z_*z_)*-1.0+q_*(z_*z_*z_))*(q_*q_)*k_*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker23_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*20.0+(z_*z_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-27.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*9.0+1.0/q_*k_*z_*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*14.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-19.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*10.0+1.0/(q_*q_)*(k_*k_)*2.0+-15.0)*(k_*k_)*-(1.0/20.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker34_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(4.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker33_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-2.0+(q_*q_)*k_*z_*3.0+q_*(k_*k_)*(z_*z_)*-1.0)*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker22_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*2.0+(k_*k_)*(z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(8.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(4.0/3.0)+(k_*k_)*-(4.0/3.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(8.0/3.0)+(q_*q_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*-(2.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker47_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_*q_)*k_*2.0+q_*(k_*k_*k_)*-2.0+(q_*q_*q_*q_)*z_*-1.0+(k_*k_*k_*k_)*z_)*z_*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker3_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_*q_)*k_*2.0+q_*(k_*k_*k_)*-2.0+(q_*q_*q_*q_)*z_*-1.0+(k_*k_*k_*k_)*z_)*z_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker11_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(4.0/3.0)+(q_*q_)*-(4.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker9_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker16_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(8.0/3.0)+(q_*q_)*-(32.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker15_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_*2.0+(q_*q_*q_*q_)*1.0/k_*z_+(q_*q_*q_)*(z_*z_)*-3.0+q_*(k_*k_)*-4.0+(q_*q_)*k_*z_*9.0+q_*(k_*k_)*(z_*z_)*-3.0+(q_*q_*q_)*-2.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker8_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-1.0+(q_*q_)*k_*z_*2.0+q_*(k_*k_)*(z_*z_)*-2.0+(q_*q_)*k_*(z_*z_*z_))*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker63_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*140.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-96.0+(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*105.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*710.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*1050.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-165.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*279.0+1.0/q_*k_*z_*210.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-840.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*384.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*-490.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-840.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*55.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*54.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*78.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-105.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-864.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-250.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-1005.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-210.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*1050.0+1.0/(q_*q_)*(k_*k_)*-154.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*960.0+35.0)*-(1.0/420.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker0_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*(16.0/3.0)+(q_*q_)*(16.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker41_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*(8.0/3.0)+(q_*q_)*(32.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker10_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_*q_)*k_+(q_*q_*q_)*k_*(z_*z_)+q_*(k_*k_*k_)*(z_*z_)*-1.0+q_*(k_*k_*k_)*-1.0+(q_*q_*q_*q_)*z_*-1.0+(k_*k_*k_*k_)*z_)*z_*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker1_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*(8.0/3.0)+(q_*q_)*(8.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker6_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-2.0+(q_*q_)*k_*z_*3.0+q_*(k_*k_)*(z_*z_)*-1.0)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker43_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(k_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*8.0+q_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*3.0+k_*(z_*z_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*6.0)*(1.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker89_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)*(2.0/5.0)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*(82.0/15.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-(32.0/15.0)+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*(18.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(6.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(4.0/3.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-(9.0/5.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-(27.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(6.0/5.0)+1.0/q_*(k_*k_*k_)*z_*-(2.0/5.0)+(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(2.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*3.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker53_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (q_*q_)*16.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker5_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker29_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-2.0+k_*-1.0+q_*z_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*(z_*z_*z_)*-5.0+k_*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*3.0+q_*(z_*z_*z_)*-5.0)*-1.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker81_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*(z_*z_*z_)*-(64.0/7.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,7)*z_*-(128.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_*z_*z_)*8.0+(k_*k_)*(z_*z_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-(46.0/5.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(12.0/35.0)+q_*k_*z_*-10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*(699.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-(18.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(93.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-(26.0/35.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,8)*(32.0/35.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*(39.0/7.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-(386.0/35.0)+1.0/q_*(k_*k_*k_)*z_*-(26.0/5.0)+(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*(102.0/35.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-17.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(z_*z_)*(288.0/35.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker73_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*90.0+(z_*z_)*45.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*90.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-123.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*51.0+1.0/q_*k_*z_*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-96.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*126.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-11.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*42.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*45.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-39.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-270.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*90.0+1.0/(q_*q_)*(k_*k_)*-2.0+-15.0)*-(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker59_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker40_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(16.0/3.0)+(q_*q_)*-(80.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker4_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_*2.0+(q_*q_*q_*q_)*1.0/k_*z_+(q_*q_*q_)*(z_*z_)*-3.0+q_*(k_*k_)*-4.0+(q_*q_)*k_*z_*9.0+q_*(k_*k_)*(z_*z_)*-3.0+(q_*q_*q_)*-2.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker26_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*123.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*-90.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*270.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-42.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-126.0+k_*-45.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*29.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*-25.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-64.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*39.0+q_*z_*120.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*-49.0+1.0/q_*(k_*k_)*z_*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*14.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-90.0+1.0/(q_*q_)*(k_*k_*k_)*2.0+k_*(z_*z_)*75.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*75.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-190.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*120.0)*-(1.0/60.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

