#include "colors.inc"
camera {
    location <-1.7, -1.7, -6>
    look_at <0, 0, 0>
    angle 50
}

box {
    <-0.5,1.0,3.5>, <0.5,2.5,4.5>
    pigment { color Green }
}

box {
    <-0.5,-0.5,3.5>, <1.5,0.5,4.5>
    pigment { color Red }
}

sphere {
    <-2, 0, 4>, 1
    pigment { color Med_Purple }
}


light_source {
    <-5, 5, 2.5>, color White
}
