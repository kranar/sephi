#ifndef ROVER_LINEAR_REGRESSION_MODEL_HPP
#define ROVER_LINEAR_REGRESSION_MODEL_HPP
#include <Eigen/Dense>

namespace Rover {

  /**
   * Implements a linear regression model.
   * @param <S> The type of scalar to use.
   */
  template<typename S>
  class LinearRegressionModel {
    public:

      /** The type of scalar to use. */
      using Scalar = S;

      /** The type used for the vector of parameters or regressors. */
      using Vector = Eigen::Vector<Scalar, Eigen::Dynamic>;

      /**
       * Constructs a LinearRegressionModel.
       * @param parameters The parameters to the linear regression model.
       */
      explicit LinearRegressionModel(Vector parameters);

      /** Returns this model's parameters. */
      const Vector& get_parameters() const;

      /**
       * Evaluates this model on a list of regressors.
       * @param regressors The list of regressors to evaluate.
       * @return The evaluation of this model to the specified
       *         <i>regressor</i>s.
       */
      Scalar evaluate(const Vector& regressors) const;

    private:
      Vector m_parameters;
  };

  template<typename S>
  LinearRegressionModel<S>::LinearRegressionModel(Vector parameters)
    : m_parameters(std::move(parameters)) {}

  template<typename S>
  const typename LinearRegressionModel<S>::Vector&
      LinearRegressionModel<S>::get_parameters() const {
    return m_parameters;
  }

  template<typename S>
  LinearRegressionModel<S>::Scalar
      LinearRegressionModel<S>::evaluate(const Vector& regressors) const {
    return m_parameters.head(m_parameters.size() - 1).dot(regressors) +
      m_parameters(m_parameters.size() - 1);
  }
}

#endif
