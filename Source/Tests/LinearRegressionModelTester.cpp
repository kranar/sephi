#include <doctest/doctest.h>
#include "Rover/LinearRegressionModel.hpp"

using namespace Rover;

TEST_SUITE("LinearRegressionModel") {
  TEST_CASE("construction") {
    auto parameters = std::vector<float>();
    parameters.push_back(1.5f);
    parameters.push_back(-0.5f);
    auto model = LinearRegressionModel(parameters);
    REQUIRE(model.get_parameters() == parameters);
  }

  TEST_CASE("evaluate") {
    auto parameters = std::vector<float>();
    parameters.push_back(2.0f);
    parameters.push_back(3.0f);
    auto model = LinearRegressionModel(parameters);
    SUBCASE("x = 1") {
      auto regressors = std::vector<float>();
      regressors.push_back(1.0f);
      auto result = model.evaluate(regressors);
      CHECK(result == doctest::Approx(5.0f));
    }
    SUBCASE("x = 0") {
      auto regressors = std::vector<float>();
      regressors.push_back(0.0f);
      auto result = model.evaluate(regressors);
      CHECK(result == doctest::Approx(2.0f));
    }
  }
}
