#!/usr/bin/env python3
#
# gen_led.py
#

from mako.template import Template
import datetime

version = 0.3

# Gamma corrected; 255 -> 202 -> 152 -> 109 -> 73 -> 44 -> 22 -> 7

# brightness = [ ( 0xff, 0xca, 0x98, 0x6d, 0x49, 0x2c, 0x16, 0x07 ),  # page 0; column 0 to 7
#                ( 0xca, 0xff, 0xca, 0x98, 0x6d, 0x49, 0x2c, 0x16 ),  # page 1; column 0 to 7
#                ( 0x98, 0xca, 0xff, 0xca, 0x98, 0x6d, 0x49, 0x2c ),  # page 2; column 0 to 7
#                ( 0x6d, 0x98, 0xca, 0xff, 0xca, 0x98, 0x6d, 0x49 ),  # page 3; column 0 to 7
#                ( 0x49, 0x6d, 0x98, 0xca, 0xff, 0xca, 0x98, 0x6d ),  # page 4; column 0 to 7
#                ( 0x2c, 0x49, 0x6d, 0x98, 0xca, 0xff, 0xca, 0x98 ),  # page 5; column 0 to 7
#                ( 0x16, 0x2c, 0x49, 0x6d, 0x98, 0xca, 0xff, 0xca ),  # page 6; column 0 to 7
#                ( 0x07, 0x16, 0x2c, 0x49, 0x6d, 0x98, 0xca, 0xff ) ] # page 7; column 0 to 7

# Gamma corrected; 255 -> 149 -> 69 -> 18

brightness = [ ( 0xff, 0x95, 0x45, 0x12, 0x00, 0x12, 0x45, 0x95 ),  # page 0; column 0 to 7
               ( 0x95, 0xff, 0x95, 0x45, 0x12, 0x00, 0x12, 0x45 ),  # page 1; column 0 to 7
               ( 0x45, 0x95, 0xff, 0x95, 0x45, 0x12, 0x00, 0x12 ),  # page 2; column 0 to 7
               ( 0x12, 0x45, 0x95, 0xff, 0x95, 0x45, 0x12, 0x00 ),  # page 3; column 0 to 7
               ( 0x00, 0x12, 0x45, 0x95, 0xff, 0x95, 0x45, 0x12 ),  # page 4; column 0 to 7
               ( 0x12, 0x00, 0x12, 0x45, 0x95, 0xff, 0x95, 0x45 ),  # page 5; column 0 to 7
               ( 0x45, 0x12, 0x00, 0x12, 0x45, 0x95, 0xff, 0x95 ),  # page 6; column 0 to 7
               ( 0x95, 0x45, 0x12, 0x00, 0x12, 0x45, 0x95, 0xff ) ] # page 7; column 0 to 7

tmpl = Template( filename = './gen_led.mako' )
print( tmpl.render( b = brightness, date = datetime.date.today().isoformat(), version = version ) )