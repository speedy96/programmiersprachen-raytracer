#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "tests.hpp"
#include <cmath>
#include <glm/vec3.hpp>
#include "sphere.h"

TEST_CASE ("Sphere tests", "[Sphere]"){

  glm::vec3 mid {0.0,0.0,0.0};
  double radius {4.5};
  Sphere s1 {mid, radius};

  SECTION("constructor tests"){
    REQUIRE(s1.mid().x==mid.x);
    REQUIRE(s1.mid().y==mid.y);
    REQUIRE(s1.mid().z==mid.z);

    REQUIRE(s1.rad()==4.5);

    REQUIRE(b1.min().x==mid.x);
    REQUIRE(b1.min().y==mid.y);
    REQUIRE(b1.min().z== mid.z);

    REQUIRE(b1.max().x==max.x);
    REQUIRE(b1.max().y==max.y);
    REQUIRE(b1.max().z== max.z);

  }

  SECTION("method tests"){
    REQUIRE(s2.area()==Approx(153.938));
    REQUIRE(s2.volume()==Approx(179.594));
  }
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



