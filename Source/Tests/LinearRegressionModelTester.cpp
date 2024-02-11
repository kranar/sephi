#include <doctest/doctest.h>
#include "Rover/LinearRegressionModel.hpp"

using namespace Eigen;
using namespace Rover;

TEST_SUITE("LinearRegressionModel") {
  TEST_CASE("construction") {
    auto parameters = VectorXd(2);
    parameters << 1.5, -0.5;
    auto model = LinearRegressionModel(parameters);
    REQUIRE(model.get_parameters() == parameters);
  }

  TEST_CASE("evaluate") {
    auto parameters = VectorXf(2);
    parameters << 2.0f, 3.0f;
    auto model = LinearRegressionModel(parameters);
    SUBCASE("x = 1") {
      auto regressors = VectorXf(1);
      regressors << 1.0f;
      auto result = model.evaluate(regressors);
      CHECK(result == doctest::Approx(5.0f));
    }
    SUBCASE("x = 0") {
      auto regressors = VectorXf(1);
      regressors << 0.0f;
      auto result = model.evaluate(regressors);
      CHECK(result == doctest::Approx(3.0f));
    }
  }
}
