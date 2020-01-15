/*
    Defined Constants                   - http://www.caskeys.com/dc/?p=5059
    License (must be included to use)   - http://www.caskeys.com/dc/?p=5067
    
		Original by Damon V. Caskey, modified by Clinton (CRxTRDude) Cañalita
		for use of Cyclohexane Games mods and scripts.
		
		Original license by DC still applies. 

*/
 
#ifndef DEFINED
#define DEFINED                     1
 
/******Adjustments and Settings******/
#define CONF_DRAWMODE               1                                       //Draw scaling modes: 0 = SNK Style, 1 = Capcom style
#define CONF_TRAILMAX               20                                      //Global shadow trail limit.
#define CONF_TRAILCNT               5                                       //Character shadow trail limit.
#define CONF_TRAILDLY               5                                       //Delay (to spawn next trailer, so trailer lasts for CONF_TRAILCNT*CONF_TRAILDLY)
#define CONF_SETBLOCK               1                                       //1 = Automatically set blocking animation based on hit height.
#define CONF_SETFALL                0                                       //1 = Automatically set fall animation based on hit height and other conditions.
#define CONF_SETPAIN                0                                       //1 = Automatically set pain animation based on hit height.
#define CONF_JUMPCON_X              0                                       //1 = Left/Right keys alter X plane veolcity during jump.
#define CONF_JUMPCON_Y              1                                       //1 = Release of Jump key halts Y velocity during jump (i.e. Mario Bros style jump height control).
#define CONF_JUMPCON_Z              0                                       //1 = Up/Down keys alter X plane velocity during jump.
 
/******AI Modes******/
#define AI_CHASE                    openborconstant("AIMOVE1_CHASE")        //Always move toward target.
#define AI_NOMOVE                   openborconstant("AIMOVE1_NOMOVE")       //No movement.
 
/******Animations, custom ID)******/
#define AC_AIRBLOCK                 A_FOLLOW80                              //Air block.
#define AC_AIRBACK                  A_FOLLOW81                              //Air back attack.
#define AC_AIRJ2AL                  A_FOLLOW89                              //Alternate Jumpattack2 (when not moving).
#define AC_AIRJ3AL                  A_FOLLOW90                              //Alternate Jumpattack3 (when not moving).
#define AC_ATKDOWN                  A_FOLLOW82                              //Down attack.
#define AC_BACKSTEP                 A_FSPECIAL2                             //Backward dash.
#define AC_BLOCKBRK                 20                                      //Guard or attack broken.
#define AC_BLOCKNOR                 A_BLOCKP                                //Default guard.
#define AC_BLOCKMID                 A_BLOCKP2                               //Middle guard.
#define AC_BLOCKLOW                 A_BLOCKP3                               //Low guard.
#define AC_BLOCKHIGH                A_BLOCKP4                               //High guard.
#define AC_BLOCKPAR                 A_FOLLOW91                              //Parry/Just defense animation.
#define AC_BLOCKPARA                A_FOLLOW92                              //Air Parry/Just defense animation.
#define AC_CLIMBUPB                 A_FOLLOW95                              //Climb up (wall/object is toward background on Z).
#define AC_CLIMBDNB                 A_FOLLOW96                              //Climb down (wall/object is toward background on Z).
#define AC_CLIMBUP                  A_FOLLOW97                              //Climb up (wall/object is toward foreground on Z).
#define AC_CLIMBDN                  A_FOLLOW98                              //Climb down (wall/object is toward foreground on Z).
#define AC_COLLAPSE                 A_FALL2                                 //Collapse
#define AC_DBJMP                    A_FOLLOW54                              //Double jump, Vertical or generic.
#define AC_DBJMPB                   A_FOLLOW55                              //Double jump, backward.
#define AC_DBJMPF                   A_FOLLOW56                              //Double jump, forward.
#define AC_DBJMPP                   A_FOLLOW57                              //Double jump, pogo.
#define AC_DBJMPW                   A_FOLLOW58                              //Double jump, wall.
#define AC_DIZZY                    A_FOLLOW50                              //Dizzy.
#define AC_DEFPOSE                  A_FOLLOW51                              //Defensive grapple.
#define AC_DODATK                   A_FOLLOW83                              //Dodge attack.
#define AC_DODATKU                  A_FOLLOW84                              //Dodge up attack.
#define AC_DODATKD                  A_FOLLOW85                              //Dodge down attack.
#define AC_DODATKSD                 A_FOLLOW86                              //Dodge attack step down.
#define AC_DODATKSU                 A_FOLLOW87                              //Dodge attack step down.
#define AC_EIMPS                    A_FOLLOW1                               //Impact effect: Small.
#define AC_EIMPM                    A_FOLLOW2                               //Impact effect: Medium.
#define AC_EIMPL                    A_FOLLOW3                               //Impact effect: Large.
#define AC_ESPLA                    A_FOLLOW4                               //Impact effect: Splash.
#define AC_FFORE                    A_FOLLOW52                              //Fatality: Fly into foreground.
#define AC_FWATER                   A_FOLLOW53                              //Fatality: Fall into background water.
#define AC_ICONS                    A_FOLLOW100                             //Icons placeholder.
#define AC_SCENENAP                 A_GET                                   //Taking a nap (ex. Golden Axe bonus stage)
#define AC_SCENESTOMP               A_ATK4                                  //Stomping/kicking innocents (ex. Golden Axe Longmoan stomping peasents)
#define AC_PAINNOR                  A_PAIN                                  //Default pain.
#define AC_PAINMID                  A_PAIN2                                 //Middle pain.
#define AC_PAINLOW                  A_PAIN                                  //Low pain.
#define AC_PAINHIGH                 A_PAIN                                  //High pain.
#define AC_POWUP                    A_FOLLOW94                              //Power up animation.
#define AC_SPLAT                    A_FALL8                                 //Thrown hard onto head.
#define AC_SWEPT                    A_FALL3                                 //Foot sweep.
#define AC_TEAM1                    A_FOLLOW88                              //Team call pose.
#define AC_TOSS                     A_FALL5                                 //Thrown.
 
/******Animations, engine defined******/
#define A_ATKBOTH                   openborconstant("ANI_ATTACKBOTH")
#define A_ATKDOWN                   openborconstant("ANI_ATTACKDOWN")
#define A_ATK2                      openborconstant("ANI_ATTACK2")
#define A_ATK3                      openborconstant("ANI_ATTACK3")
#define A_ATK4                      openborconstant("ANI_ATTACK4")
#define A_ATK5                      openborconstant("ANI_ATTACK5")
#define A_ATK6                      openborconstant("ANI_ATTACK6")
#define A_ATK7                      openborconstant("ANI_ATTACK7")
#define A_ATKUP                     openborconstant("ANI_ATTACKUP")
#define A_ATKBACK                   openborconstant("ANI_ATTACKBACKWARD")
#define A_BLOCK                     openborconstant("ANI_BLOCK")
#define A_BLOCKP                    openborconstant("ANI_BLOCKPAIN")
#define A_BLOCKP2                   openborconstant("ANI_BLOCKPAIN2")
#define A_BLOCKP3                   openborconstant("ANI_BLOCKPAIN3")
#define A_BLOCKP4                   openborconstant("ANI_BLOCKPAIN4")
#define A_BLOCKP5                   openborconstant("ANI_BLOCKPAIN5")
#define A_BURN                      openborconstant("ANI_BURN")
#define A_BURNDIE                   openborconstant("ANI_BURNDIE")
#define A_BURNPAIN                  openborconstant("ANI_BURNPAIN")
#define A_CHARGEATK                 openborconstant("ANI_CHARGEATTACK")
#define A_DEATH                     openborconstant("ANI_DIE")
#define A_DEATH2                    openborconstant("ANI_DIE2")
#define A_DEATH3                    openborconstant("ANI_DIE3")
#define A_DEATH4                    openborconstant("ANI_DIE4")
#define A_DEATH5                    openborconstant("ANI_DIE5")
#define A_DEATH6                    openborconstant("ANI_DIE6")
#define A_DEATH7                    openborconstant("ANI_DIE7")
#define A_DEATH8                    openborconstant("ANI_DIE8")
#define A_DEATH9                    openborconstant("ANI_DIE9")
#define A_DEATH10                   openborconstant("ANI_DIE10")
#define A_DOWN                      openborconstant("ANI_DOWN")
#define A_FALL                      openborconstant("ANI_FALL")
#define A_FALL2                     openborconstant("ANI_FALL2")
#define A_FALL3                     openborconstant("ANI_FALL3")
#define A_FALL4                     openborconstant("ANI_FALL4")
#define A_FALL5                     openborconstant("ANI_FALL5")
#define A_FALL6                     openborconstant("ANI_FALL6")
#define A_FALL7                     openborconstant("ANI_FALL7")
#define A_FALL8                     openborconstant("ANI_FALL8")
#define A_FALL9                     openborconstant("ANI_FALL9")
#define A_FALL10                    openborconstant("ANI_FALL10")
#define A_FOLLOW1                   openborconstant("ANI_FOLLOW1")
#define A_FOLLOW2                   openborconstant("ANI_FOLLOW2")
#define A_FOLLOW3                   openborconstant("ANI_FOLLOW3")
#define A_FOLLOW4                   openborconstant("ANI_FOLLOW4")
#define A_FOLLOW5                   openborconstant("ANI_FOLLOW5")
#define A_FOLLOW6                   openborconstant("ANI_FOLLOW6")
#define A_FOLLOW7                   openborconstant("ANI_FOLLOW7")
#define A_FOLLOW8                   openborconstant("ANI_FOLLOW8")
#define A_FOLLOW9                   openborconstant("ANI_FOLLOW9")
#define A_FOLLOW10                  openborconstant("ANI_FOLLOW10")
#define A_FOLLOW11                  openborconstant("ANI_FOLLOW11")
#define A_FOLLOW12                  openborconstant("ANI_FOLLOW12")
#define A_FOLLOW13                  openborconstant("ANI_FOLLOW13")
#define A_FOLLOW14                  openborconstant("ANI_FOLLOW14")
#define A_FOLLOW15                  openborconstant("ANI_FOLLOW15")
#define A_FOLLOW16                  openborconstant("ANI_FOLLOW16")
#define A_FOLLOW17                  openborconstant("ANI_FOLLOW17")
#define A_FOLLOW18                  openborconstant("ANI_FOLLOW18")
#define A_FOLLOW19                  openborconstant("ANI_FOLLOW19")
#define A_FOLLOW20                  openborconstant("ANI_FOLLOW20")
#define A_FOLLOW21                  openborconstant("ANI_FOLLOW21")
#define A_FOLLOW22                  openborconstant("ANI_FOLLOW22")
#define A_FOLLOW23                  openborconstant("ANI_FOLLOW23")
#define A_FOLLOW24                  openborconstant("ANI_FOLLOW24")
#define A_FOLLOW25                  openborconstant("ANI_FOLLOW25")
#define A_FOLLOW26                  openborconstant("ANI_FOLLOW26")
#define A_FOLLOW27                  openborconstant("ANI_FOLLOW27")
#define A_FOLLOW28                  openborconstant("ANI_FOLLOW28")
#define A_FOLLOW29                  openborconstant("ANI_FOLLOW29")
#define A_FOLLOW30                  openborconstant("ANI_FOLLOW30")
#define A_FOLLOW31                  openborconstant("ANI_FOLLOW31")
#define A_FOLLOW32                  openborconstant("ANI_FOLLOW32")
#define A_FOLLOW33                  openborconstant("ANI_FOLLOW33")
#define A_FOLLOW34                  openborconstant("ANI_FOLLOW34")
#define A_FOLLOW35                  openborconstant("ANI_FOLLOW35")
#define A_FOLLOW36                  openborconstant("ANI_FOLLOW36")
#define A_FOLLOW37                  openborconstant("ANI_FOLLOW37")
#define A_FOLLOW38                  openborconstant("ANI_FOLLOW38")
#define A_FOLLOW39                  openborconstant("ANI_FOLLOW39")
#define A_FOLLOW40                  openborconstant("ANI_FOLLOW40")
#define A_FOLLOW41                  openborconstant("ANI_FOLLOW41")
#define A_FOLLOW42                  openborconstant("ANI_FOLLOW42")
#define A_FOLLOW43                  openborconstant("ANI_FOLLOW43")
#define A_FOLLOW44                  openborconstant("ANI_FOLLOW44")
#define A_FOLLOW45                  openborconstant("ANI_FOLLOW45")
#define A_FOLLOW46                  openborconstant("ANI_FOLLOW46")
#define A_FOLLOW47                  openborconstant("ANI_FOLLOW47")
#define A_FOLLOW48                  openborconstant("ANI_FOLLOW48")
#define A_FOLLOW49                  openborconstant("ANI_FOLLOW49")
#define A_FOLLOW50                  openborconstant("ANI_FOLLOW50")
#define A_FOLLOW51                  openborconstant("ANI_FOLLOW51")
#define A_FOLLOW52                  openborconstant("ANI_FOLLOW52")
#define A_FOLLOW53                  openborconstant("ANI_FOLLOW53")
#define A_FOLLOW54                  openborconstant("ANI_FOLLOW54")
#define A_FOLLOW55                  openborconstant("ANI_FOLLOW55")
#define A_FOLLOW56                  openborconstant("ANI_FOLLOW56")
#define A_FOLLOW57                  openborconstant("ANI_FOLLOW57")
#define A_FOLLOW58                  openborconstant("ANI_FOLLOW58")
#define A_FOLLOW59                  openborconstant("ANI_FOLLOW59")
#define A_FOLLOW60                  openborconstant("ANI_FOLLOW60")
#define A_FOLLOW61                  openborconstant("ANI_FOLLOW61")
#define A_FOLLOW62                  openborconstant("ANI_FOLLOW62")
#define A_FOLLOW63                  openborconstant("ANI_FOLLOW63")
#define A_FOLLOW64                  openborconstant("ANI_FOLLOW64")
#define A_FOLLOW65                  openborconstant("ANI_FOLLOW65")
#define A_FOLLOW66                  openborconstant("ANI_FOLLOW66")
#define A_FOLLOW67                  openborconstant("ANI_FOLLOW67")
#define A_FOLLOW68                  openborconstant("ANI_FOLLOW68")
#define A_FOLLOW69                  openborconstant("ANI_FOLLOW69")
#define A_FOLLOW70                  openborconstant("ANI_FOLLOW70")
#define A_FOLLOW71                  openborconstant("ANI_FOLLOW71")
#define A_FOLLOW72                  openborconstant("ANI_FOLLOW72")
#define A_FOLLOW73                  openborconstant("ANI_FOLLOW73")
#define A_FOLLOW74                  openborconstant("ANI_FOLLOW74")
#define A_FOLLOW75                  openborconstant("ANI_FOLLOW75")
#define A_FOLLOW76                  openborconstant("ANI_FOLLOW76")
#define A_FOLLOW77                  openborconstant("ANI_FOLLOW77")
#define A_FOLLOW78                  openborconstant("ANI_FOLLOW78")
#define A_FOLLOW79                  openborconstant("ANI_FOLLOW79")
#define A_FOLLOW80                  openborconstant("ANI_FOLLOW80")
#define A_FOLLOW81                  openborconstant("ANI_FOLLOW81")
#define A_FOLLOW82                  openborconstant("ANI_FOLLOW82")
#define A_FOLLOW83                  openborconstant("ANI_FOLLOW83")
#define A_FOLLOW84                  openborconstant("ANI_FOLLOW84")
#define A_FOLLOW85                  openborconstant("ANI_FOLLOW85")
#define A_FOLLOW86                  openborconstant("ANI_FOLLOW86")
#define A_FOLLOW87                  openborconstant("ANI_FOLLOW87")
#define A_FOLLOW88                  openborconstant("ANI_FOLLOW88")
#define A_FOLLOW89                  openborconstant("ANI_FOLLOW89")
#define A_FOLLOW90                  openborconstant("ANI_FOLLOW90")
#define A_FOLLOW91                  openborconstant("ANI_FOLLOW91")
#define A_FOLLOW92                  openborconstant("ANI_FOLLOW92")
#define A_FOLLOW93                  openborconstant("ANI_FOLLOW93")
#define A_FOLLOW94                  openborconstant("ANI_FOLLOW94")
#define A_FOLLOW95                  openborconstant("ANI_FOLLOW95")
#define A_FOLLOW96                  openborconstant("ANI_FOLLOW96")
#define A_FOLLOW97                  openborconstant("ANI_FOLLOW97")
#define A_FOLLOW98                  openborconstant("ANI_FOLLOW98")
#define A_FOLLOW99                  openborconstant("ANI_FOLLOW99")
#define A_FOLLOW100                 openborconstant("ANI_FOLLOW100")
#define A_FORWARDJUMP               openborconstant("ANI_FORWARDJUMP")
#define A_FSPECIAL                  openborconstant("ANI_FREESPECIAL")
#define A_FSPECIAL2                 openborconstant("ANI_FREESPECIAL2")
#define A_FSPECIAL3                 openborconstant("ANI_FREESPECIAL3")
#define A_FSPECIAL4                 openborconstant("ANI_FREESPECIAL4")
#define A_FSPECIAL5                 openborconstant("ANI_FREESPECIAL5")
#define A_FSPECIAL6                 openborconstant("ANI_FREESPECIAL6")
#define A_FSPECIAL7                 openborconstant("ANI_FREESPECIAL7")
#define A_FSPECIAL8                 openborconstant("ANI_FREESPECIAL8")
#define A_FSPECIAL9                 openborconstant("ANI_FREESPECIAL9")
#define A_FSPECIAL10                openborconstant("ANI_FREESPECIAL10")
#define A_FSPECIAL11                openborconstant("ANI_FREESPECIAL11")
#define A_FSPECIAL12                openborconstant("ANI_FREESPECIAL12")
#define A_FSPECIAL13                openborconstant("ANI_FREESPECIAL13")
#define A_FSPECIAL14                openborconstant("ANI_FREESPECIAL14")
#define A_FSPECIAL15                openborconstant("ANI_FREESPECIAL15")
#define A_GET                       openborconstant("ANI_GET")
#define A_GRABATK2                  openborconstant("ANI_GRABATTACK2")
#define A_GRABBACK                  openborconstant("ANI_GRABBACKWARD")
#define A_GRABBED                   openborconstant("ANI_GRABBED")
#define A_IDLE                      openborconstant("ANI_IDLE")
#define A_JUMP                      openborconstant("ANI_JUMP")
#define A_JUMPATK                   openborconstant("ANI_JUMPATTACK")
#define A_JUMPATK2                  openborconstant("ANI_JUMPATTACK2")
#define A_JUMPATK3                  openborconstant("ANI_JUMPATTACK3")
#define A_JUMPLAND                  openborconstant("ANI_JUMPLAND")
#define A_PAIN                      openborconstant("ANI_PAIN")
#define A_PAIN2                     openborconstant("ANI_PAIN2")
#define A_PAIN3                     openborconstant("ANI_PAIN3")
#define A_PAIN4                     openborconstant("ANI_PAIN4")
#define A_PAIN5                     openborconstant("ANI_PAIN5")
#define A_PAIN6                     openborconstant("ANI_PAIN6")
#define A_PAIN7                     openborconstant("ANI_PAIN7")
#define A_PAIN8                     openborconstant("ANI_PAIN8")
#define A_PAIN9                     openborconstant("ANI_PAIN9")
#define A_PAIN10                    openborconstant("ANI_PAIN10")
#define A_RESPAWN                   openborconstant("ANI_RESPAWN")
#define A_RISE                      openborconstant("ANI_RISE")
#define A_RISEATK                   openborconstant("ANI_RISEATTACK")
#define A_RUN                       openborconstant("ANI_RUN")
#define A_RUNATK                    openborconstant("ANI_RUNATTACK")
#define A_RUNJUMP                   openborconstant("ANI_RUNJUMP")
#define A_RUNJUMPATK                openborconstant("ANI_RUNJUMPATTACK")
#define A_SHOCKDIE                  openborconstant("ANI_SHOCKDIE")
#define A_SHOCKPAIN                 openborconstant("ANI_SHOCKPAIN")
#define A_SLEEP                     openborconstant("ANI_SLEEP")
#define A_SPAWN                     openborconstant("ANI_SPAWN")
#define A_SPECIAL                   openborconstant("ANI_SPECIAL")
#define A_SPECIAL2                  openborconstant("ANI_SPECIAL2")
#define A_UP                        openborconstant("ANI_UP")
#define A_WALK                      openborconstant("ANI_WALK")
#define A_WALKOFF                   openborconstant("ANI_WALKOFF")
 
/******Attack Types******/
#define ATK_1                       openborconstant("ATK_NORMAL")
#define ATK_2                       openborconstant("ATK_NORMAL2")
#define ATK_3                       openborconstant("ATK_NORMAL3")
#define ATK_4                       openborconstant("ATK_NORMAL4")
#define ATK_5                       openborconstant("ATK_NORMAL5")
#define ATK_6                       openborconstant("ATK_NORMAL6")
#define ATK_7                       openborconstant("ATK_NORMAL7")
#define ATK_8                       openborconstant("ATK_NORMAL8")
#define ATK_9                       openborconstant("ATK_NORMAL9")
#define ATK_10                      openborconstant("ATK_NORMAL10")
#define ATK_BURN                    openborconstant("ATK_BURN")
#define ATK_SHOCK                   openborconstant("ATK_SHOCK")
 
/*****Color Maps*****/
#define MAP_KO                      1                                       //KO.
#define MAP_BURN                    2                                       //Burn.
#define MAP_SHOCK                   3                                       //Shock.
#define MAP_FREEZE                  4                                       //Freeze.
#define MAP_POISON                  5                                       //Poison.
 
/******Color RGB, common******/
#define RGB_BLACK                   rgbcolor(0, 0, 0)                       //Black.
#define RGB_BLUE                    rgbcolor(0, 0, 255)                     //Blue.
#define RGB_GRAY                    rgbcolor(128, 128, 128)                 //Gray
#define RGB_GREEN                   rgbcolor(0, 255, 0)                     //Green.
#define RGB_RED                     rgbcolor(255, 0, 0)                     //Red.
#define RGB_ORANGE                  rgbcolor(255, 69, 0)                    //Orange.
#define RGB_VIOLET                  rgbcolor(51, 0, 51)                     //Deep Purple/Violet
#define RGB_WHITE                   rgbcolor(255, 255, 255)                 //White.
#define RGB_YELLOW                  rgbcolor(255, 255, 0)                   //Yellow.
 
/******Color RGB, special*****/
#define RGB_BURN                    RGB_ORANGE                              //Burn tint.
#define RGB_POISON                  RGB_GREEN                               //Poison tint.
#define RGB_SHOCK                   RGB_WHITE                               //Shock tint.
 
/******Direction, absolute)******/
#define DIR_LEFT                    0                                       //Facing left.
#define DIR_RIGHT                   1                                       //Facing right.
 
/******Direction, adjustment)******/
#define DIR_ADJ_LEFT                -2                                      //Force target to face left.
#define DIR_ADJ_NONE                0                                       //Do not change target facing.
#define DIR_ADJ_OPP                 -1                                      //Force target to face opposite direction of designated anchor.
#define DIR_ADJ_RIGHT               2                                       //Force target to face right.
#define DIR_ADJ_SAME                1                                       //Force target to face same direction as designated anchor.
 
/******Entity Index******/
#define ENT_INDEX_0                 0
#define ENT_INDEX_1                 1
#define ENT_INDEX_2                 2
#define ENT_INDEX_3                 3
#define ENT_INDEX_4                 4
#define ENT_INDEX_5                 5
 
/******Entity Reference******/
#define ENT_SELF                    0
 
/******Entity Types*******/
#define TYPE_ENEMY                  openborconstant("TYPE_ENEMY")
#define TYPE_ITEM                   openborconstant("TYPE_ITEM")
#define TYPE_NPC                    openborconstant("TYPE_NPC")
#define TYPE_NONE                   openborconstant("TYPE_NONE")
#define TYPE_OBSTACLE               openborconstant("TYPE_OBSTACLE")        
#define TYPE_PLAYER                 openborconstant("TYPE_PLAYER")
 
/******Flags, general use******/
#define FLAG_NONE                   0
 
#define FLAG_MODE_0                 0
#define FLAG_MODE_1                 1
#define FLAG_MODE_2                 2
#define FLAG_MODE_3                 3
#define FLAG_MODE_4                 4
#define FLAG_MODE_5                 5
#define FLAG_MODE_6                 6
#define FLAG_MODE_7                 7
#define FLAG_MODE_8                 8
#define FLAG_MODE_9                 9
#define FLAG_MODE_10                10
 
/******Flags, specfic settings******/
#define SOUND_PLAY_100              1                                       //Always play sound.
#define SOUND_FILE_RAND             -1                                      //Choose random file from sound group.
#define SOUND_DELAY_DEF             0                                       //In progress - avoid playing certain sounds in quick succession. 
#define SOUND_SUB_NONE              0
 
/******Icons******/
#define ICON_AI                     0
#define ICON_AIPAIN                 1
 
/******Keys (ID)******/
#define KEY_ANY                     "anybutton"                             //Any key.
#define KEY_ATK1                    "attack"                                //Attack 1.
#define KEY_ATK2                    "attack2"                               //Attack 2.
#define KEY_ATK3                    "attack3"                               //Attack 3.
#define KEY_ATK4                    "attack4"                               //Attack 4.
#define KEY_ESC                     "esc"                                   //Escape.
#define KEY_JUMP                    "jump"                                  //Jump.
#define KEY_MDOWN                   "movedown"                              //Move down.
#define KEY_MLEFT                   "moveleft"                              //Move left.
#define KEY_MRIGHT                  "moveright"                             //Move right.
#define KEY_MUP                     "moveup"                                //Move up.
#define KEY_SCREENSHOT              "screenshot"                            //Screenshot.
#define KEY_SPECIAL                 "special"                               //Special.
#define KEY_START                   "start"                                 //Start.
 
/******Keys (Status)******/
#define KEY_STAT_DOWN               1                                       //Initial key trigger.
#define KEY_STAT_PRESS              0                                       //Key being held.
#define KEY_STAT_UP                 2                                       //Key release.
 
/******Properties, engine defined)******/
#define PROP_DIRECTION              "direction"                             //X axis facing.                                            
#define PROP_VELOCITY_ALL           "velocity"                              //Movement speed.
#define PROP_VELOCITY_X             "xdir"                                  //X axis movement speed.
#define PROP_VELOCITY_Y             "tossv"                                 //Y axis movement speed.
#define PROP_VELOCITY_Z             "zdir"                                  //Z axis movement speed.
 
/******System Constants******/
#define SYS_FRONTZ                  openborconstant("FRONTPANEL_Z")

/******System Variants (all engine defined)*******/
#define SYS_PAUSED									openborvariant("game_paused")
#define SYS_INLEVEL									openborvariant("in_level")

#define SYS_INMENU									openborvariant("in_menuscreen")
#define SYS_INTITLE									openborvariant("in_titlescreen")
#define SYS_INSELECT								openborvariant("in_selectscreen")
#define	SYS_INCREDITS								openborvariant("in_enginecreditsscreen") 

#define SYS_TIME										openborvariant("elapsed_time")
#define SYS_SCENE										openborvariant("current_scene")
 
#endif