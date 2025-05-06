; The CMD file.
;
; Two parts: 1. Command definition and  2. State entry
; (state entry is after the commands def section)
;
; 1. Command definition
; ---------------------
; Note: The commands are CASE-SENSITIVE, and so are the command names.
; The eight directions are:
;   B, DB, D, DF, F, UF, U, UB     (all CAPS)
;   corresponding to back, down-back, down, downforward, etc.
; The six buttons are:
;   a, b, c, x, y, z               (all lower case)
;   In default key config, abc are are the bottom, and xyz are on the
;   top row. For 2 button characters, we recommend you use a and b.
;   For 6 button characters, use abc for kicks and xyz for punches.
;
; Each [Command] section defines a command that you can use for
; state entry, as well as in the CNS file.
; The command section should look like:
;
;   [Command]
;   Name= "some_name"
;   command = the_command
;   time = time (optional -- defaults to 15 if omitted)
;
; - some_name
;   A name to give that command. You'll use this name to refer to
;   that command in the state entry, as well as the CNS. It is case-
;   sensitive (QCB_a is NOT the same as Qcb_a or QCB_A).
;
; - command
;   list of buttons or directions, separated by commas.
;   Directions and buttons can be preceded by special characters:
;   slash (/) - means the key must be held down
;          egs. command = /D       ;hold the down direction
;               command = /F, a    ;hold fwd while you press a
;   tilde (~) - to detect key releases
;          egs. command = ~a       ;release the a button
;               command = ~D, F, a ;release down, press fwd, then a
;          If you want to detect "charge moves", you can specify
;          the time the key must be held down for (in game-ticks)
;          egs. command = ~30a     ;hold a for at least 30 ticks, then release
;               command = ~30
;   dollar ($) - Direction-only: detect as 4-way
;          egs. command = $D       ;will detect if D, DB or DF is held
;               command = $B       ;will detect if B, DB or UB is held
;   plus (+) - Buttons only: simultaneous press
;          egs. command = a+b      ;press a and b at the same time
;               command = x+y+z    ;press x, y and z at the same time
;   You can combine them:
;     eg. command = ~30$D, a+b     ;hold D, DB or DF for 30 ticks, release,
;                                  ;then press a and b together
;   It's recommended that for most "motion" commads, eg. quarter-circle-fwd,
;   you start off with a "release direction". This matches the way most
;   popular fighting games implement their engine.
;
; - time (optional)
;   Time allowed to do the command, given in game-ticks. Defaults to 15
;   if omitted
;-| Super Motions |------------------------------------------------------

[Command]
Name= "super_golpe_a"
command = ~D, DF, F, D, DF, F, a
time = 20

[Command]
Name= "super_golpe_b"
command = ~D, DF, F, D, DF, F, b
time = 20

[Command]
Name= "super_golpe_c"
command = ~D, DF, F, D, DF, F, c
time = 20

[Command]
Name= "super_misil_x"
command = ~D, DF, F, D, DF, F, x
time = 20

[Command]
Name= "super_misil_y"
command = ~D, DF, F, D, DF, F, y
time = 20

[Command]
Name= "super_misil_z"
command = ~D, DF, F, D, DF, F, z
time = 20

;-| Special Motions |------------------------------------------------------

[Command]
Name= "misil_x"
command = ~D, DF, F, x

[Command]
Name= "misil_y"
command = ~D, DF, F, y

[Command]
Name= "misil_z"
command = ~D, DF, F, z


;-| Double Tap |-----------------------------------------------------------
[Command]
Name= "FF";Required (do not remove)
command = F, F
time = 10

[Command]
Name= "BB";Required (do not remove)
command = B, B
time = 10

;-| 2/3 Button Combination |-----------------------------------------------
[Command]
Name= "recovery";Required (do not remove)
command = a+b
time = 1

[Command]
Name= "ab"
command = a+b
time = 1

;-| Dir + Button |---------------------------------------------------------
[Command]
Name= "fwd_x"
command = /F,x
time = 1

[Command]
Name= "fwd_y"
command = /F,y
time = 1

[Command]
Name= "fwd_z"
command = /F,z
time = 1

[Command]
Name= "fwd_a"
command = /F,a
time = 1

[Command]
Name= "fwd_b"
command = /F,b
time = 1

[Command]
Name= "fwd_c"
command = /F,c
time = 1

[Command]
Name= "downfwd_a"
command = /DF,a
time = 1

[Command]
Name= "downfwd_b"
command = /DF,b
time = 1

[Command]
Name= "back_a"
command = /B,a
time = 1

[Command]
Name= "back_b"
command = /B,b
time = 1

[Command]
Name= "back_c"
command = /B,c
time = 1

[Command]
Name= "down_a"
command = /$D,a
time = 1

[Command]
Name= "down_b"
command = /$D,b
time = 1

[Command]
Name= "down_c"
command = /$D,c
time = 1

[Command]
Name= "fwd_ab"
command = /F, a+b
time = 1

[Command]
Name= "back_ab"
command = /B, a+b
time = 1

;-| Single Button |---------------------------------------------------------
[Command]
Name= "a"
command = a
time = 1

[Command]
Name= "b"
command = b
time = 1

[Command]
Name= "c"
command = c
time = 1

[Command]
Name= "x"
command = x
time = 1

[Command]
Name= "y"
command = y
time = 1

[Command]
Name= "z"
command = z
time = 1

;-| Hold Dir |--------------------------------------------------------------
[Command]
Name= "holdfwd";Required (do not remove)
command = /$F
time = 1

[Command]
Name= "holdback";Required (do not remove)
command = /$B
time = 1

[Command]
Name= "holdup";Required (do not remove)
command = /$U
time = 1

[Command]
Name= "holddown";Required (do not remove)
command = /$D
time = 1

;---------------------------------------------------------------------------
; 2. State entry
; --------------
; This is where you define what commands bring you to what states.
;
; Each state entry block looks like:
;   [State -1]                  ;Don't change this
;   type = ChangeState          ;Don't change this
;   value = new_state_number
;   trigger1=command="command_name"
;   . . .  (any additional triggers)
;
; - new_state_number is the number of the state to change to
; - command_name is the name of the command (from the section above)
; - Useful triggers to know:
;   - statetype
;       S, C or A : current state-type of player (stand, crouch, air)
;   - ctrl
;       0 or 1 : 1 if player has control. Unless "interrupting" another
;                move, you'll want ctrl = 1
;   - stateno
;       number of state player is in - useful for "move interrupts"
;   - movecontact
;       0 or 1 : 1 if player's last attack touched the opponent
;                useful for "move interrupts"
;
; For reference on triggers, see CNS documentation.
;
; Just for your information (skip if you're not interested):
; This part is an extension of the CNS. "State -1" is a special state
; that is executed once every game-tick, regardless of what other state
; you are in.


; Don't remove the following line. It's required by the CMD standard.
[Statedef -1]

;---------------------------------------------------------------------------
;RunBack
[State -1]
type = ChangeState
value = 105
trigger1=command="BB"
trigger1 = statetype = S
trigger1 = ctrl = 1
;---------------------------------------------------------------------------
;RunFwd
[State -1]
type = ChangeState
value = 100
trigger1=command="FF"
trigger1 = statetype = S
trigger1 = ctrl = 1


;---------------------------------------------------------------------------
;Kongoh Throw
[State -1, Kung Fu Throw]
type = ChangeState
value = 800
triggerall = command = "y"
triggerall = statetype = S
triggerall = ctrl
triggerall = stateno != 100
trigger1 = command = "holdfwd"
trigger1 = p2bodydist X < 3
trigger1 = (p2statetype = S) || (p2statetype = C)
trigger1 = p2movetype != H
trigger2 = command = "holdback"
trigger2 = p2bodydist X < 5
trigger2 = (p2statetype = S) || (p2statetype = C)
trigger2 = p2movetype != H



;===========================================================================
; super misiles
[State -1]
type = ChangeState
value = 3000
triggerall=command="super_misil_x"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1
[State -1]
type = ChangeState
value = 3000
triggerall=command="super_misil_y"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1

[State -1]
type = ChangeState
value = 3000
triggerall=command="super_misil_z"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1
Stand_x

;===========================================================================
; super golpes
[State -1]
type = ChangeState
value = 3010
triggerall=command="super_golpe_a"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1
[State -1]
type = ChangeState
value = 3010
triggerall=command="super_golpe_b"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1

[State -1]
type = ChangeState
value = 3010
triggerall=command="super_golpe_c"
triggerall = power >= 1000 ;Level 1
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1
Stand_x


;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
; misiles
[State -1]
type = ChangeState
value = 1000
triggerall=command="misil_x"
triggerall = numproj = 0
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1

[State -1]
type = ChangeState
value = 1010
triggerall=command="misil_y"
triggerall = numproj = 0
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1

[State -1]
type = ChangeState
value = 1020
triggerall=command="misil_z"
triggerall = numproj = 0
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = stateno = [200, 450]
trigger2 = movecontact = 1
Stand_x
;===========================================================================

[State -1]
type = ChangeState
value = 200
triggerall=command="x"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 200
trigger2 = time > 7

;---------------------------------------------------------------------------
;Stand_y
[State -1]
type = ChangeState
value = 210
triggerall=command="y"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 200
trigger2 = movecontact = 1

;---------------------------------------------------------------------------
;Stand_z
[State -1]
type = ChangeState
value = 220
triggerall=command="z"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 200
trigger2 = movecontact = 1
trigger3 = stateno = 210
trigger3 = movecontact = 1

;---------------------------------------------------------------------------
;Stand_a
[State -1]
type = ChangeState
value = 230
triggerall=command="a"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 230
trigger2 = time > 7

;---------------------------------------------------------------------------
;Stand_b
[State -1]
type = ChangeState
value = 240
triggerall=command="b"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 230
trigger2 = movecontact = 1

;---------------------------------------------------------------------------
;Stand_c
[State -1]
type = ChangeState
value = 250
triggerall=command="c"
triggerall=command !="holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = stateno = 230
trigger2 = movecontact = 1
trigger3 = stateno = 240
trigger3 = movecontact = 1

;---------------------------------------------------------------------------
;Crouch_x
[State -1]
type = ChangeState
value = 400
triggerall=command="x"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 400
trigger2 = time > 7

;---------------------------------------------------------------------------
;Crouch_y
[State -1]
type = ChangeState
value = 410
triggerall=command="y"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 400
trigger2 = movecontact = 1

;---------------------------------------------------------------------------
;Crouch_z
[State -1]
type = ChangeState
value = 420
triggerall=command="z"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 400
trigger2 = movecontact = 1
trigger3 = stateno = 410
trigger3 = movecontact = 1

;---------------------------------------------------------------------------
;Crouch_a
[State -1]
type = ChangeState
value = 430
triggerall=command="a"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 430
trigger2 = time > 7

;---------------------------------------------------------------------------
;Crouch_b
[State -1]
type = ChangeState
value = 440
triggerall=command="b"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 430
trigger2 = movecontact = 1

;---------------------------------------------------------------------------
;Crouch_c
[State -1]
type = ChangeState
value = 450
triggerall=command="c"
triggerall=command="holddown"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = stateno = 430
trigger2 = movecontact = 1
trigger3 = stateno = 440
trigger3 = movecontact = 1

;---------------------------------------------------------------------------
Jump_x
[State -1]
type = ChangeState
value = 600
trigger1=command="x"
trigger1 = statetype = A
trigger1 = ctrl = 1
;---------------------------------------------------------------------------
;Jump_y
[State -1]
type = ChangeState
value = 610
trigger1=command="y"
trigger1 = statetype = A
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Jump_z
[State -1]
type = ChangeState
value = 620
trigger1=command="z"
trigger1 = statetype = A
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Jump_a
[State -1]
type = ChangeState
value = 630
trigger1=command="a"
trigger1 = statetype = A
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Jump_b
[State -1]
type = ChangeState
value = 640
trigger1=command="b"
trigger1 = statetype = A
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Jump_c
[State -1]
type = ChangeState
value = 650
trigger1=command="c"
trigger1 = statetype = A
trigger1 = ctrl = 1
;---------------------------------------------------------------------------

