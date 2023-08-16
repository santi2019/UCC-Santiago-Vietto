#include "colors.inc"

camera {
    location <0, 0, -5>
    look_at <0, 0, 0>
    angle 30
}

box {
    <0, 0, 0>, <1, 1, 1>
    texture {
        pigment {
            color Yellow
        }
    }
}
 
triangle {
    <0, 1, -1>, <0, 1, 2>, <1, 0, 1>
    texture {
        pigment {
            color Red
        }
    }
}

cylinder {
    <0, -2, 0>,
    <0, 2, 0>,
    2
    open
    texture {
        pigment {
            color Yellow
        }
    }
}    

polygon {
    30,
    <-0.8, 0.0>, <-0.8, 1.0>,
    <-0.3, 1.0>, <-0.3, 0.5>,
    <-0.7, 0.5>, <-0.7, 0.0>,
    <-0.8, 0.0>,
    <-0.7, 0.6>, <-0.7, 0.9>,
    <-0.4, 0.9>, <-0.4, 0.6>,
    <-0.7, 0.6>
    <-0.25, 0.0>, <-0.25, 1.0>,
    < 0.25, 1.0>, < 0.25, 0.0>,
    <-0.25, 0.0>,
    <-0.15, 0.1>, <-0.15, 0.9>,
    < 0.15, 0.9>, < 0.15, 0.1>,
    <-0.15, 0.1>,
    <0.45, 0.0>, <0.30, 1.0>,
    <0.40, 1.0>, <0.55, 0.1>,
    <0.70, 1.0>, <0.80, 1.0>,
    <0.65, 0.0>,
    <0.45, 0.0>
    pigment { color rgb <1, 0, 0> }
}
  
cone {
    <0, -2, 0>, 3
    <0, 2, 0>, 1
    texture { 
        pigment {
            color Blue
        }
    }
}

torus {
    4, 1
    texture { 
        pigment {
            color Red
        }
    }
    rotate <-30, 0, 0>
}


light_source {
    <2, 3, -3>, White
}
