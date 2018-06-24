#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <cmath>
#include <glm/vec3.hpp>
#include "../framework/sphere.h"
#include "../framework/box.h"
#include "../framework/color.hpp"
#include "../framework/shape.h"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


TEST_CASE ("Sphere tests", "[Sphere]"){

  glm::vec3 mid {0.0,0.0,0.0};
  double radius {4.5};
  Color color {1.0f,0.0f,1.0f};
  std::string name = "sphere2";
  
  Sphere s1 {mid, radius, name, color};

  SECTION("constructor tests"){
    REQUIRE(s1.mid().x==mid.x);
    REQUIRE(s1.mid().y==mid.y);
    REQUIRE(s1.mid().z==mid.z);

    REQUIRE(s1.radius()==4.5);

  }

  SECTION("method tests"){
    REQUIRE(s1.area()==Approx(254.4690049408));
    REQUIRE(s1.volume()==Approx(381.7035074112));
  }

  SECTION("color and name tests"){
    REQUIRE(s1.color().r==1.0f);
    REQUIRE(s1.name().compare("sphere2")==0.0);

  }
}

TEST_CASE ("box tests", "[box]"){
  glm::vec3 min {1.0,1.0,1.0};
  glm::vec3 max{1.0,-3.0,2.0};
  Color color {1.0f,0.0f,1.0f};
  std::string name = "box1";

  Box b1 {min, max, name, color};

  SECTION("constructor tests"){
    REQUIRE(b1.min().x==min.x);
    REQUIRE(b1.min().y==min.y);
    REQUIRE(b1.min().z==min.z);

    REQUIRE(b1.max().x==max.x);
    REQUIRE(b1.max().y==max.y);
    REQUIRE(b1.max().z==max.z);}


   SECTION("method tests")  {

    REQUIRE(b1.area()==Approx(8.0));
    REQUIRE(b1.volume()==Approx(0.0));
    }

  SECTION("color and name tests"){
    REQUIRE(b1.color().b == 1.0f);
    REQUIRE(b1.name().compare("box1")==0.0);
    
  }


}

TEST_CASE("intersect_ray_sphere ")
{
// Ray
glm::vec3 ray_origin {0.0f, 0.0f, 0.0f};
// ray direction has to be normalized !
// you can use :
// v = glm :: normalize ( some_vector )
glm::vec3 ray_direction {0.0f, 0.0f, 1.0f};
// Sphere
glm::vec3 sphere_center {0.0f,0.0f, 5.0f};
float sphere_radius {1.0f};
float distance = 0.0f;
auto result = glm :: intersectRaySphere (
        ray_origin , ray_direction ,
        sphere_center ,
        sphere_radius * sphere_radius , // squared radius !!!
        distance );

    REQUIRE ( distance == Approx (4.0 ));


//Custom spheres
glm::vec3 mid4{0.0,0.0,5.0};
double radius4{1.0};
Color color4{1.0f,0.0f,0.0f};
Sphere s4{mid4,radius4,"Sphere2",color4};

float distance2 = 0.0f;
REQUIRE(!s4.intersect(Ray{},distance));
REQUIRE(distance == Approx(-4.0f));

glm::vec3 mid5{0.0,0.0,-5.0};
double radius5{1.0};
Color color5{1.0f,1.0f,0.0f};
Sphere s5{mid5,radius5,"Sphere3",color5};

REQUIRE(s5.intersect(Ray{},distance));

}

TEST_CASE("destructor")
{
std::cout<<"================================\n";
Color red{255,0,0};
glm::vec3 position{0.0f,0.0f,0.0f};
Sphere* s1 = new Sphere{position,1.2f,"sphere0",red};
Shape* s2 = new Sphere{position,1.2f,"sphere1",red};

s1->print(std::cout);
s2->print(std::cout);

delete s1;
delete s2;
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}




