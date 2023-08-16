#include "colors.inc"
camera {
    location <-10, 3, -10>
    look_at <0, 0, 0>
    angle 50
}

cylinder {
    <0,0,1>, <0, 0, 2>, 2
    pigment { color Med_Purple }
}


light_source {
    <5, 5, -5>, color White
}
