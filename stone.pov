
// ********************************************************************
//  Exemple use
//  povray stone.pov +H300 +W300 Declare=Seed=33 Declare=W=0 -Ow2.png
// ********************************************************************

  // stone_rad = 2.25/2;
#include "gostones.inc"
camera {location <0,15,0> right x*image_width/image_height angle 9.4 look_at <0,0,0>}
light_source {<-5000, 10000, 5000> color rgb <1.0, 0.95, 0.9>*1.1}
light_source {<-5000, 500, -5000> color rgb <1.0, 0.95, 0.9>*.1}
light_source {<5000, 500, -5000> color rgb <1.0, 0.95, 0.9>*.1}
light_source {<5000, 500, 5000> color rgb <1.0, 0.95, 0.9>*.1}
light_source {<-5000, 500, 5000> color rgb <1.0, 0.95, 0.9>*.1}
//plane {y,0 pigment {color rgb 1}}

#ifndef (W)
  #declare W = 0;
#end

#ifndef (Seed)
  #declare Seed = 0;
#end

#local st=seed(Seed);
#if (W>0)
   object {w_stone(st) translate <   .0,0, 0>}
#else
   object {b_stone(st) translate <   .0,0, 0>}
#end
//object {w_stone(st) translate <   .0,0, 0>}
