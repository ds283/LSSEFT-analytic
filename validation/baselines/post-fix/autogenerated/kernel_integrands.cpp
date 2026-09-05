// Generated at 2026-Sep-05 21:02:09
//
static int ker0_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-1.0+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*12.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-3.0+1.0/q_*k_*z_*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-12.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*6.0+1.0/(q_*q_)*(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*12.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*3.0+(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-9.0+1.0/q_*k_*z_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*2.0+1.0/(q_*q_)*(k_*k_)+-4.0)*(k_*k_)*-(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker2_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*9.0+1.0/q_*k_*z_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-2.0+1.0/(q_*q_)*(k_*k_)*-1.0)*(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (k_*k_*k_*k_)*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*(k_*k_*k_*k_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_)*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_)*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*z_*12.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*(z_*z_)*58.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*(z_*z_*z_)*-60.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*k_*z_*-24.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*(k_*k_*k_)*z_*-28.0+1.0/(q_*q_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_*z_*z_)*30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(z_*z_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*3.0)*-(1.0/8.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)+q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(7.0/2.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*3.0+1.0/q_*(k_*k_*k_)*z_+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*5.0+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(7.0/2.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*3.0+1.0/q_*(k_*k_*k_)*z_+(q_*q_)*(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-6.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-1.0+1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*5.0+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*3.0+1.0/q_*(k_*k_*k_)*z_+(q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-3.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*-1.0+1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*9.0+q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-2.0+(k_*k_)*7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*3.0+1.0/q_*(k_*k_*k_)*z_+(q_*q_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-11.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-4.0+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*33.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-41.0+1.0/q_*k_*z_*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*24.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-24.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*25.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-48.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-49.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*30.0+1.0/(q_*q_)*(k_*k_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*48.0)*(k_*k_)*(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*3.0+(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-19.0+1.0/q_*k_*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*6.0+1.0/(q_*q_)*(k_*k_)+-4.0)*-(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*19.0+1.0/q_*k_*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-6.0+1.0/(q_*q_)*(k_*k_)*-1.0)*(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(z_*z_*z_)*20.0+1.0/q_*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*(z_*z_)*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(z_*z_*z_)*20.0+1.0/(q_*q_)*k_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*(z_*z_)*-42.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_)*z_*29.0)*(1.0/4.0);
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

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*20.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*17.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-14.0+k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-17.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-11.0+q_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*4.0+1.0/q_*(k_*k_)*z_*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-8.0+1.0/(q_*q_)*(k_*k_*k_)*-3.0+k_*(z_*z_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-3.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-8.0+k_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-8.0+q_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*4.0+1.0/q_*(k_*k_)*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-4.0+1.0/(q_*q_)*(k_*k_*k_)*-2.0+k_*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-7.0);
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

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*(z_*z_*z_)*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,6)*z_*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,7)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*-14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*14.0+k_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*(z_*z_)*-12.0+q_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*-7.0+1.0/q_*(k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*-5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_*z_*z_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*10.0+1.0/(q_*q_)*(k_*k_*k_)*-3.0+k_*(z_*z_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*3.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*(z_*z_*z_)*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,6)*z_*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,7)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*-14.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*14.0+k_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*(z_*z_)*-12.0+q_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*-7.0+1.0/q_*(k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*-5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_*z_*z_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*10.0+1.0/(q_*q_)*(k_*k_*k_)*-3.0+k_*(z_*z_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*3.0)*-1.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-4.0+(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*23.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-11.0+1.0/q_*k_*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*16.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-24.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-19.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*10.0+1.0/(q_*q_)*(k_*k_)*-5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*16.0)*(k_*k_)*-(1.0/4.0);
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*12.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*2.0+1.0/(q_*q_)*(k_*k_*k_*k_)*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*(z_*z_*z_)*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,7)*z_*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_*z_*z_)*4.0+(k_*k_)*(z_*z_)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*24.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,8)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-24.0+1.0/q_*(k_*k_*k_)*z_*-8.0+(q_*q_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(z_*z_)*12.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = (1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*(k_*k_*k_*k_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*(z_*z_)*6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*(z_*z_*z_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*k_*z_*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*(k_*k_*k_)*z_*-4.0+1.0/(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_*z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_))*(k_*k_*k_*k_)*(3.0/16.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*9.0+1.0/q_*k_*z_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-2.0+1.0/(q_*q_)*(k_*k_)*-1.0)*-(1.0/4.0);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*3.0+(z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*-9.0+1.0/q_*k_*z_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*2.0+1.0/(q_*q_)*(k_*k_)+-4.0)*(k_*k_)*(1.0/4.0);
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)+(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-1.0+q_*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(7.0/2.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-3.0+1.0/q_*(k_*k_*k_)*z_*-1.0+(q_*q_)*(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)*(1.0/2.0)+1.0/(q_*q_)*(k_*k_*k_*k_)+(k_*k_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-5.0+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-(7.0/2.0)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-3.0+1.0/q_*(k_*k_*k_)*z_*-1.0+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*6.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-5.0+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-3.0+1.0/q_*(k_*k_*k_)*z_*-1.0+(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*3.0;
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*18.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-9.0+q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*2.0+(k_*k_)*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*-9.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-3.0+1.0/q_*(k_*k_*k_)*z_*-1.0+(q_*q_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*11.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,6)+1.0/(q_*q_)*(k_*k_*k_*k_)*9.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*(z_*z_*z_)*-16.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,7)*z_*-16.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_*z_*z_)*8.0+(k_*k_)*(z_*z_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*15.0+q_*k_*z_*-10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*(z_*z_*z_)*-18.0+(k_*k_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*(z_*z_)*39.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*std::pow(k_,5)*z_*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*(z_*z_*z_)*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,8)*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(q_,5)*k_*z_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*(z_*z_)*15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*std::pow(k_,5)*z_*-39.0+1.0/q_*(k_*k_*k_)*z_*-13.0+(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,6)*13.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-17.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,6)*(z_*z_)*24.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+(z_*z_)*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*-6.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)*19.0+1.0/q_*k_*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*z_*-15.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*-6.0+1.0/(q_*q_)*(k_*k_)*-1.0)*-(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = k_*(1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*(z_*z_)*19.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*(z_*z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_*k_)*z_*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-18.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*-15.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*(z_*z_)*-1.0+q_*z_*8.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)*2.0+1.0/q_*(k_*k_)*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*std::pow(k_,5)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_*k_)*z_*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*std::pow(k_,5)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*(z_*z_*z_)*-6.0+1.0/(q_*q_)*(k_*k_*k_)*-1.0+k_*(z_*z_)*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*5.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*8.0)*-(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(z_*z_*z_)*12.0+1.0/q_*z_*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*(z_*z_)*-10.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*z_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_)*z_*5.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(z_*z_*z_)*12.0+1.0/(q_*q_)*k_*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*k_*(z_*z_)*-26.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*-3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_)*z_*21.0)*(k_*k_*k_)*-(1.0/4.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*(k_*k_*k_*k_)*7.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_)*-30.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_)*10.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*z_*24.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*(z_*z_)*114.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*k_*(z_*z_*z_)*-140.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*k_*z_*-36.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*(k_*k_*k_)*z_*-44.0+1.0/(q_*q_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(z_*z_*z_*z_)*70.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(z_*z_)*30.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*3.0)*(k_*k_*k_*k_)*(1.0/16.0);
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

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/(q_*q_)*std::pow(k_,6)*-1.0+(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/q_*(k_*k_*k_)*z_*8.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*(z_*z_*z_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_)+1.0/q_*k_*z_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*1.0/q_*std::pow(k_,5)*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(k_*k_*k_*k_)*(z_*z_)*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*1.0/(q_*q_)*(k_*k_*k_*k_)*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*(z_*z_)*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*(z_*z_*z_)*2.0+1.0/(q_*q_)*(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*q_*(k_*k_*k_)*(z_*z_*z_)*4.0)*(k_*k_)*-1.0;
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

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-2.0+k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*2.0+q_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-2.0)*2.0;
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-2.0+(q_*q_)*k_*z_*3.0+q_*(k_*k_)*(z_*z_)*-1.0)*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*2.0+q_*k_*z_*4.0+(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*4.0+(q_*q_)*-6.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*-2.0;
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

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*-4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*2.0+(k_*k_)*2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*4.0+(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(q_*k_*(z_*z_*z_)+(q_*q_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-1.0+q_*k_*z_*2.0+(q_*q_*q_)*1.0/k_*z_+(q_*q_)*-1.0)*-4.0;
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*((q_*q_)*(z_*z_)+(k_*k_)*(z_*z_)+q_*k_*z_*-3.0+(q_*q_*q_)*1.0/k_*z_*-1.0+(q_*q_)*2.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = ((q_*q_)*k_+(q_*q_*q_)*z_*-1.0+(q_*q_)*k_*(z_*z_*z_*z_)*-3.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_+(q_*q_)*k_*(z_*z_)*-4.0+q_*(k_*k_)*(z_*z_*z_)*5.0)*1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*-4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-1.0+(q_*q_)*k_*z_*2.0+q_*(k_*k_)*(z_*z_)*-2.0+(q_*q_)*k_*(z_*z_*z_))*-8.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*((q_*q_)*k_*2.0+(q_*q_*q_)*z_*-1.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_*3.0+(q_*q_)*k_*(z_*z_)*-8.0+q_*(k_*k_)*(z_*z_*z_)*3.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker41_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker42_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker43_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker44_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = (k_*k_)*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-6.0+-1.0)*-(1.0/2.0);
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

   double value_ = (k_*k_)*((z_*z_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)*3.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*-6.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)*3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*6.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker46_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker47_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker48_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
 {
   // computed using auto-symmetrize = 0, symmetrize-22 = 1
   using oneloop_momentum_impl::integrand_data;
   integrand_data* data_ = static_cast<integrand_data*>(userdata_);

   double k_ = data_->k * Mpc_units::Mpc;
   double q_ = (data_->IR_cutoff + x_[0] * data_->q_range) * Mpc_units::Mpc;
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)*2.0+(k_*k_)*(z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-2.0+(k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-4.0+(q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*2.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-2.0+k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*2.0+q_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-2.0)*-2.0;
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-2.0+q_*k_*z_*4.0+(k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*-(5.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+(q_*q_)*-(1.0/2.0)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*5.0;
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-2.0+(q_*q_)*k_*z_*3.0+q_*(k_*k_)*(z_*z_)*-1.0)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*4.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-2.0+(k_*k_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-4.0+(q_*q_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*k_*z_*4.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(q_*k_*(z_*z_*z_)+(q_*q_)*(z_*z_)*-2.0+(k_*k_)*(z_*z_)*-1.0+q_*k_*z_*2.0+(q_*q_*q_)*1.0/k_*z_+(q_*q_)*-1.0)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = 1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(k_*k_)*(z_*z_)+(k_*k_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_*k_)*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_*k_)*-1.0+q_*k_*z_*-2.0+(k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_*k_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_*q_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(k_*k_)*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_*k_)*z_*-2.0+(q_*q_)*3.0;
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = k_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*(z_*z_)*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*z_*-2.0+k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*2.0+q_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-1.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-2.0)*-1.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*((q_*q_)*(z_*z_)+(k_*k_)*(z_*z_)+q_*k_*z_*-3.0+(q_*q_*q_)*1.0/k_*z_*-1.0+(q_*q_)*2.0)*-2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = (1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)*-1.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*-2.0+-1.0)*(k_*k_)*(1.0/2.0);
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
   double z_ = 2.0*x_[1] - 1.0;

   double value_ = ((z_*z_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_)+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*(z_*z_)+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*(z_*z_)*2.0)*(k_*k_)*-(1.0/2.0);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*k_*((q_*q_)*k_*2.0+(q_*q_*q_)*z_*-1.0+(q_*q_*q_)*(z_*z_*z_)*3.0+(k_*k_*k_)*(z_*z_)*-2.0+q_*(k_*k_)*z_*3.0+(q_*q_)*k_*(z_*z_)*-8.0+q_*(k_*k_)*(z_*z_*z_)*3.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+q_*k_*(z_*z_)*-2.0+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_*2.0)*k_*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_+(q_*q_*q_)*(z_*z_)*-1.0+q_*(k_*k_)*-1.0+(q_*q_)*k_*z_*2.0+q_*(k_*k_)*(z_*z_)*-2.0+(q_*q_)*k_*(z_*z_*z_))*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dqdx * Mpc_units::Mpc) * value_ * Wick_;

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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_)*(k_*k_)*(z_*z_)*6.0+(q_*q_*q_)*k_*z_*7.0+(q_*q_*q_)*k_*(z_*z_*z_)*-3.0+(q_*q_)*(k_*k_)*-6.0+(q_*q_*q_*q_)*(z_*z_)*-2.0+(k_*k_*k_*k_)*(z_*z_)*2.0+q_*(k_*k_*k_)*(z_*z_*z_)*-3.0+q_*(k_*k_*k_)*z_*-1.0)*-2.0;
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*((k_*k_*k_)*z_*2.0+(q_*q_*q_*q_)*1.0/k_*z_+(q_*q_*q_)*(z_*z_)*-3.0+q_*(k_*k_)*-4.0+(q_*q_)*k_*z_*9.0+q_*(k_*k_)*(z_*z_)*-3.0+(q_*q_*q_)*-2.0)*2.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_+q_*z_*-1.0+k_*(z_*z_)*-1.0+q_*(z_*z_*z_))*(q_*q_)*k_*8.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*-16.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((q_*q_*q_)*k_*z_*5.0+(q_*q_*q_)*k_*(z_*z_*z_)*-1.0+(q_*q_)*(k_*k_)*-3.0+(q_*q_*q_*q_)*(z_*z_)*-2.0+(k_*k_*k_*k_)*(z_*z_)*2.0+q_*(k_*k_*k_)*(z_*z_*z_)*-5.0+(q_*q_)*(k_*k_)*(z_*z_*z_*z_)*3.0+q_*(k_*k_*k_)*z_)*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*4.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = 1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*((k_*k_)*(z_*z_*z_)+(q_*q_)*(z_*z_*z_)+(q_*q_)*z_*-1.0+(k_*k_)*z_*-1.0+q_*k_+q_*k_*(z_*z_*z_*z_)*-1.0)*q_*k_*16.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*-(1.0/2.0);
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

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*-(1.0/2.0);
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

   double value_ = (k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*2.0)*k_*-1.0;
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

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*z_*-1.0+z_*-1.0)*k_*-2.0;
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

   double value_ = (k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*-2.0)*k_*-1.0;
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_*-7.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = q_*(1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)+q_+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*q_*(k_*k_)*-3.0+k_*z_*4.0)*(1.0/2.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3)*(data_->Pk((std::pow(q_*k_*z_*-2.0+(k_*k_)+(q_*q_),(1.0/2.0)))/Mpc_units::Mpc) / Mpc_units::Mpc3);
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

   double value_ = (k_+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_)*(k_*k_*k_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_)*(k_*k_)*z_*4.0+q_*z_*2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(k_*k_*k_)+k_*(z_*z_)*-2.0+1.0/((q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0))*(q_*q_*q_*q_)*k_*(z_*z_)*-2.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_)*k_*-3.0+1.0/(q_*k_*z_*2.0+(k_*k_)*-1.0+(q_*q_)*-1.0)*(q_*q_*q_)*z_*2.0)*k_;
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
   // no z_ integral in this kernel; measure should be jacobian_dq

   double value_ = (k_*k_)*-(8.0/3.0)+(q_*q_)*-(8.0/3.0);
   double Wick_ = (data_->Pk((q_)/Mpc_units::Mpc) / Mpc_units::Mpc3);
   f_[0] = (data_->jacobian_dq * Mpc_units::Mpc) * value_ * Wick_;

   return 0;
 }

static int ker78_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker79_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker80_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker81_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker82_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker83_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker84_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker85_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker86_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker87_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker88_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker89_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker90_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker91_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker92_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker93_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker94_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker95_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker96_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker97_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker98_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker99_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

static int ker100_integrand(const int* ndim_, const cubareal x_[], const int* ncomp_, cubareal f_[], void* userdata_)
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

