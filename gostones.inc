/* gostones.inc
 * Copyright (C) 2003 Nicolas Rougier
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this software; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

// ********************************************************************
// How to use:
//  Include this file and define parameters you want to change:
//   (scale: 1 pov unit = 1 centimeter)
//
//   #declare stone_rad = 2.25/2;
//   #declare stone_hgt = .75;
//   #declare stone_top_roundnes = .5;
//   #declare stone_edge_roundnes = .4;
//
//   t_blackstone: blackstone texture
//   t_whitestone  whitestone texture
//
// Then call b_stone(0) or w_stone(st) macro, this will create the stone
// goban centered at origin and lying on floor. The st paremeter is a random
// seed for randomizing white texture. You can use something like:
//   #declare st=seed(18);  before calling w_stone(st).
// ********************************************************************
#version 3.5;
#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"


// ********************************************************************
//  Textures
// ********************************************************************
#ifndef (t_whitestone)
  #declare t_whitestone = texture {
    pigment {
      marble
      color_map {
        [0.0 rgb 0.90]
        [0.4 rgb 1.00]
      }
      scale 0.3
      warp {turbulence 0.5}
      scale <1.3,1.4,7>
    }
    finish {specular .25 roughness .05}
  }
#end

#ifndef (t_blackstone)
  #declare t_blackstone = texture {
    pigment{rgb 0.005}
    finish {specular 0.75 roughness .05}
  }
#end


// ********************************************************************
//  Dimensions:
//  -----------
//   Goban settings from "Making a goban and stones, bowls"
//    from http://www.igoweb.org/~pahle/go-stuff/goban.html
// ********************************************************************
//    Dimensions                  SI (mm)   Imperial (inch)   Japanese
//     - Goban width               424.4    16 23/32          1.5 shaku
//     - Goban length              454.5    17 29/32          1.4 shaku
//     - Goban thickness           151.5     5 31/32          0.5 shaku
//     - Line spacing width-wise    22.0        7/8           7.26 bu
//     - Line spacing length-wise   23.7       15/16          7.82 bu
//     - Line thickness              1.0       >1/32          0.30 bu
//     - Hoshi marker diameter       4.0        5/32          0.12 bu
//     - Stones diameter            22.5       29/32          7.50 bu
// 
//                            (1 inch=25.4 mm. 1 shaku= 100 bu =303 mm)
// ********************************************************************
#ifndef (stone_rad)
  #declare stone_rad = 2.25/2;
#end
#ifndef (stone_hgt)
  #declare stone_hgt = .75;
#end
#ifndef (stone_top_roundness)
  #declare stone_top_roundnes = .5;
#end
#ifndef (stone_edge_roundness)
  #declare stone_edge_roundnes = .4;
#end


// ********************************************************************
//  Macro for stone shape
// ********************************************************************
#macro stone() 
    lathe {
        bezier_spline 8
        <0,stone_hgt/2>
		<stone_top_roundnes*stone_rad,stone_hgt/2>
		<stone_rad,stone_edge_roundnes*stone_hgt/2> 
		<stone_rad,0>

		<0,-stone_hgt/2>
		<stone_top_roundnes*stone_rad,-stone_hgt/2>
		<stone_rad,-stone_edge_roundnes*stone_hgt/2>
		<stone_rad,0>
		translate y*stone_hgt/2
    }
#end

// ********************************************************************
//  Macro for whitestone
// ********************************************************************
#macro w_stone(st)
  object {
	stone()
    texture {t_whitestone translate rand(st)*10 scale stone_rad/1.125 rotate y*rand(st)*360}
  }
#end // macro w_stone(st)

// ********************************************************************
//  Macro for blackstone
// ********************************************************************
#macro b_stone(st)
  object { stone()
             texture {t_blackstone}
           }
#end // macro b_stone(st)


// ********************************************************************
//  Exemple use
// ********************************************************************
/*
camera {location <0,15,-10> right x*image_width/image_height angle 37 look_at <0,0,0>}
light_source {<-5000, 14000, 15000> color rgb <1.0, 0.95, 0.9>*2.3}
plane {y,0 pigment {color rgb 1}}
#local st=seed(18);
object {w_stone(st) translate <   .5,0, 1.5>}
object {w_stone(st) translate <-2.,0, 0>}
object {b_stone(st) translate <  1, 0,-1>}
*/
