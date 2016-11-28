# -*-Shell-script-*-
#
# my_led_brightness.kll
#

Name = my_led_brightness;
Version = ${version};
Author = "Keisuke Shimizu";
KLL = 0.3d;

# Modified Date

Date = ${date};

ISSILedBrightness1 = "
0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C1-1 -> C1-16 */
0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C2-1 -> C2-16 */
0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C3-1 -> C3-16 */
0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C4-1 -> C4-16 */
0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C5-1 -> C5-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C6-1 -> C6-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C7-1 -> C7-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C8-1 -> C8-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C9-1 -> C9-16 */
";

% for p in range( 8 ):
MyLedBrightness${p} = "
${hex(b[p][6])}, ${hex(b[p][1])}, ${hex(b[p][3])}, ${hex(b[p][4])}, ${hex(b[p][7])}, ${hex(b[p][3])}, ${hex(b[p][7])}, ${hex(b[p][3])}, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C1-1 -> C1-16 */
${hex(b[p][5])}, ${hex(b[p][0])}, ${hex(b[p][2])}, ${hex(b[p][3])}, ${hex(b[p][7])}, ${hex(b[p][2])}, ${hex(b[p][6])}, ${hex(b[p][2])}, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C2-1 -> C2-16 */
${hex(b[p][4])}, ${hex(b[p][6])}, ${hex(b[p][1])}, ${hex(b[p][2])}, ${hex(b[p][6])}, ${hex(b[p][1])}, ${hex(b[p][6])}, ${hex(b[p][1])}, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C3-1 -> C3-16 */
${hex(b[p][3])}, ${hex(b[p][5])}, ${hex(b[p][0])}, ${hex(b[p][1])}, ${hex(b[p][5])}, ${hex(b[p][0])}, ${hex(b[p][4])}, ${hex(b[p][0])}, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C4-1 -> C4-16 */
${hex(b[p][2])}, ${hex(b[p][4])}, ${hex(b[p][5])}, ${hex(b[p][0])}, ${hex(b[p][4])}, ${hex(b[p][7])}, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C5-1 -> C5-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C6-1 -> C6-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C7-1 -> C7-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C8-1 -> C8-16 */
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* C9-1 -> C9-16 */
";
% endfor