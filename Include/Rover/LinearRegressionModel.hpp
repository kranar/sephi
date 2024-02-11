#ifndef ROVER_LINEAR_REGRESSION_MODEL_HPP
#define ROVER_LINEAR_REGRESSION_MODEL_HPP
#include <vector>

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

      /**
       * Constructs a LinearRegressionModel.
       * @param parameters The parameters to the linear regression model.
       */
      explicit LinearRegressionModel(std::vector<Scalar> parameters);

      /** Returns this model's parameters. */
      const std::vector<Scalar>& get_parameters() const;

      /**
       * Evaluates this model on a list of regressors.
       * @param regressors The list of regressors to evaluate.
       * @return The evaluation of this model to the specified
       *         <i>regressor</i>s.
       */
      Scalar evaluate(const std::vector<Scalar>& regressors) const;

    private:
      std::vector<Scalar> m_parameters;
  };

  template<typename S>
  LinearRegressionModel<S>::LinearRegressionModel(
    std::vector<Scalar> parameters)
    : m_parameters(std::move(parameters)) {}

  template<typename S>
  const std::vector<typename LinearRegressionModel<S>::Scalar>&
      LinearRegressionModel<S>::get_parameters() const {
    return m_parameters;
  }

  template<typename S>
  LinearRegressionModel<S>::Scalar LinearRegressionModel<S>::evaluate(
      const std::vector<Scalar>& regressors) const {
    auto result = m_parameters[0];
    for(auto i = std::size_t(0); i < regressors.size(); ++i) {
      result += m_parameters[i + 1] * regressors[i];
    }
    return result;
  }
}

#endif
