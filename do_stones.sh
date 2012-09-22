#!/usr/bin/env bash

povray stone.pov +H300 +W300 Declare=W=0 -Ob.png +UA
povray stone.pov +H300 +W300 Declare=W=1 -Ow1.png +UA
povray stone.pov +H300 +W300 Declare=Seed=33 Declare=W=1 -Ow2.png +UA
povray stone.pov +H300 +W300 Declare=Seed=83 Declare=W=1 -Ow3.png +UA
