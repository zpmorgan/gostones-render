
// ********************************************************************
//  Exemple use
// ********************************************************************

#include "gostones.inc"

camera {location <0,15,-10> right x*image_width/image_height angle 37 look_at <0,0,0>}
light_source {<-5000, 14000, 15000> color rgb <1.0, 0.95, 0.9>*1.1}
plane {y,0 pigment {color rgb 1}}
#local st=seed(18);
object {w_stone(st) translate <   .5,0, 1.5>}
object {w_stone(st) translate <-2.,0, 0>}
object {b_stone(st) translate <  1, 0,-1>}
