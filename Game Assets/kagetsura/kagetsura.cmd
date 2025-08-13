;***********************************************************************************
;KAGETSURA SENGOKU 140 POR CIENTO DISFRUTALO ERES LIBRE DE COGER LO QUE DESEES.
; Made in Spain by Juan Carlos http://eternalmugen.cjb.net
;************************************************************************************

[Command]
name = "estrella"
command = ~D, DF, F, a


[Command]
name = "estrella"
command = ~D, DB, B, a

[Command]
name = "magia2"
command = ~D, DF, F, b


[Command]
name = "magia2"
command = ~D, DB, B, b

[Command]
name = "magia2"
command = a+z

[Command]
name = "bomba_kagetsura"
command = ~D, DF, F, y


[Command]
name = "bomba_kagetsura"
command = ~D, DB, B, y



[Command]
name = "plato"
command =~D, DF, F, z


[Command]
name = "plato"
command = ~D, DB, B, z

[Command]
name = "teletransportacion"
command = a+c

[Command]
name = "teletransportacion"
command = b+c


[Command]
name = "art_ninja2"
command =~D, DF, F, c


[Command]
name = "art_ninja2"
command = ~D, DB, B, c


[Command]
name = "super_trueno"
command = ~D, DF, F, x


[Command]
name = "super_trueno"
command = ~D, DB, B, x



[Command]
name = "combo"
command = b+x


;-| Special Motions |------------------------------------------------------
[Command]
name = "upper_x"
command = ~F, D, DF, x

[Command]
name = "upper_y"
command = ~F, D, DF, y

[Command]
name = "upper_xy"
command = ~F, D, DF, x+y

[Command]
name = "QCF_x"
command = ~D, DF, F, x

[Command]
name = "QCF_y"
command = ~D, DF, F, y

[Command]
name = "QCF_xy"
command = ~D, DF, F, x+y



[Command]
name = "QCB_b"
command = ~D, DF, F, b

[Command]
name = "FF_ab"
command = F, F, a+b

[Command]
name = "FF_a"
command = F, F, a

[Command]
name = "FF_b"
command = F, F, b

;-| Double Tap |-----------------------------------------------------------


[Command]
name = "rapid_shine"     ;Required (do not remove)
command = F,F,a
time = 10

[Command]
name = "rapida_patada"     ;Required (do not remove)
command = F,F,b
time = 10


[Command]
name = "FF"     ;Required (do not remove)
command = F,F
time = 10


[Command]
name = "BB"     ;Required (do not remove)
command = B, B
time = 10

;-| 2/3 Button Combination |-----------------------------------------------
[Command]
name = "recovery";Required (do not remove)
command = x+y
time = 1

[Command]
name = "magia1";Required (do not remove)
command = a+b
time = 1

[Command]
name = "ayudantes";Required (do not remove)
command = c+x
time = 1


[Command]
name = "art_ninja3";Required (do not remove)
command = a+x
time = 1


[Command]
name = "daga";Required (do not remove)
command = y+z
time = 1


;-| Dir + Button |---------------------------------------------------------
[Command]
name = "down_a"
command = /$D,a
time = 1

[Command]
name = "down_b"
command = /$D,b
time = 1

[Command]
name = "back_a"
command = /B,a
time = 1

;-| Single Button |---------------------------------------------------------
[Command]
name = "a"
command = a
time = 1

[Command]
name = "b"
command = b
time = 1

[Command]
name = "c"
command = c
time = 1

[Command]
name = "x"
command = x
time = 1

[Command]
name = "y"
command = y
time = 1

[Command]
name = "z"
command = z
time = 1

[Command]
name = "start"
command = s
time = 1

;-| Hold Dir |--------------------------------------------------------------
[Command]
name = "holdfwd";Required (do not remove)
command = /$F
time = 1

[Command]
name = "holdback";Required (do not remove)
command = /$B
time = 1

[Command]
name = "holdup" ;Required (do not remove)
command = /$U
time = 1

[Command]
name = "holddown";Required (do not remove)
command = /$D
time = 1


[Command]
name = "holda"
command = /$a
time = 1

[Command]
name = "holdb"
command = /$b
time = 1

[Command]
name = "holdc"
command = /$c
time = 1


[Command]
name = "hold_a"
command = /$a
time = 1

[Command]
name = "hold_b"
command = /$b
time = 1

[Command]
name = "hold_c"
command = /$c
time = 1

;---------------------------------------------------------------------------
; 2. State entry
; --------------
; This is where you define what commands bring you to what states.
;
; Each state entry block looks like:
;   [State -1, Label]           ;Change Label to any name you want to use to
;                               ;identify the state with.
;   type = ChangeState          ;Don't change this
;   value = new_state_number
;   trigger1 = command = command_name
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
; Note: The order of state entry is important.
;   State entry with a certain command must come before another state
;   entry with a command that is the subset of the first.
;   For example, command "fwd_a" must be listed before "a", and
;   "fwd_ab" should come before both of the others.
;
; For reference on triggers, see CNS documentation.
;
; Just for your information (skip if you're not interested):
; This part is an extension of the CNS. "State -1" is a special state
; that is executed once every game-tick, regardless of what other state
; you are in.


; Don't remove the following line. It's required by the CMD standard.
[Statedef -1]

;===========================================================================
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------

[State -1]
type = ChangeState
value = 2755
triggerall = StateType != A
triggerall = power < 3000
trigger1 = command = "hold_a"
trigger1 = command = "hold_b"
trigger1 = command = "hold_c"
trigger1 = statetype = S
trigger1 = ctrl = 1

[State -1, Ninjitsu]
type = ChangeState
trigger1 = P2statetype != A
trigger1 = statetype != A
value = 4700
triggerall = command = "teletransportacion"
trigger1 = statetype = S
trigger1 = ctrl


[State -1, Bomba_kagetsura]
type = ChangeState
value = 9000
triggerall = command = "bomba_kagetsura"
triggerall = power >= 1000
triggerall = NumHelper(3005) = 0
triggerall = statetype != A
trigger1 = ctrl
trigger2 = hitdefattr = SC, NA, SA, HA
trigger2 = stateno != [9000, 9100]
trigger2 = movecontact

[State -1]
type = ChangeState
triggerall = command = "ayudantes"
triggerall = NumHelper(4010)=0
triggerall = NumHelper(4017)=0
triggerall = NumHelper(4013)=0
triggerall = NumHelper(4410)=0
triggerall = NumExplod(3200) = 0
triggerall = NumExplod(3210) = 0
triggerall = NumExplod(3501) != 0
triggerall = NumHelper(3550) = 0
triggerall = stateno !=4140
trigger1 = statetype = S
trigger1 = ctrl = 1
value = 3510



[State -1, Stand Light Kick]
type = ChangeState
value = 231
triggerall = power >= 500
triggerall = statetype != A
triggerall = command = "rapid_shine"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl


[State -1, Stand Light Kick]
type = ChangeState
value = 221
triggerall = statetype != A
triggerall = command = "rapida_patada"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl

[State -1]
type = ChangeState
value = 5210
triggerall = canrecover = 1
triggerall = Var(9) = 1
triggerall = random < 999
triggerall = life > 0
trigger1 = time > 30
trigger1 = stateno = 5050

[State -1]
type = ChangeState
value = 5201
triggerall = canrecover = 1
triggerall = Var(9) = 1
triggerall = random < 999
triggerall = life > 0
trigger1 = stateno = 5100
trigger1 = Pos Y < -20
persistent = 0


[State -1]
type = ChangeState
value = 130
triggerall = Var(9) = 1 
triggerall = random < 999
triggerall = P2movetype = A
triggerall = statetype != A
triggerall = P2statetype != C
trigger1 = ctrl
trigger2 = stateno = 52
[State -1]
type = ChangeState
value = 131
triggerall = Var(9) = 1
triggerall = random < 999
triggerall = P2movetype = A
triggerall = statetype != A
triggerall = P2statetype = C
trigger1 = ctrl
trigger2 = stateno = 52
[State -1]
type = ChangeState
value = 132
triggerall = Var(9) = 1 
triggerall = random < 999
triggerall = P2movetype = A
triggerall = statetype = A
trigger1 = ctrl
trigger2 = stateno = 5210

[State -1]
type = ChangeState
value = 152
triggerall = var(9) = 1
triggerall = Statetype != A
triggerall = P2statetype = C
triggerall = P2Movetype = A
trigger1 = stateno = 150
trigger2 = stateno = 151

[State -1]
type = ChangeState
value = 150
triggerall = var(9) = 1
triggerall = Statetype != A
triggerall = P2statetype != C
triggerall = P2Movetype = A
trigger1 = stateno = 152
trigger2 = stateno = 153

[State -1]
type = ChangeState
value = 150
triggerall = var(9) = 1
triggerall = Statetype != A
triggerall = Pos Y > -1
triggerall = P2statetype != C
triggerall = P2Movetype = A
trigger1 = stateno = 154
trigger2 = stateno = 155
[State -1]
type = ChangeState
value = 152
triggerall = var(9) = 1
triggerall = Statetype != A
triggerall = Pos Y > -1
triggerall = P2statetype = C
triggerall = P2Movetype = A
trigger1 = stateno = 154
trigger2 = stateno = 155



[State -1, Super rayo]
type = ChangeState
value = 3920
triggerall = p2stateno !=5300
triggerall = NumHelper(4017)!=1
triggerall = NumHelper(4010)!=1
triggerall = NumHelper(4013)!=1
triggerall = NumHelper(4410)!=1
triggerall = p2stateno !=5110
triggerall = p2stateno !=5120
triggerall = p2stateno !=800
triggerall = p2stateno !=900
triggerall = power >=1000
triggerall = command = "super_trueno"
trigger1 = (p2statetype = S) || (p2statetype = C)
trigger1 = p2movetype != H
trigger1 = statetype != A
trigger1 = ctrl


[State -1, Combo]
type = ChangeState
value = 3990
triggerall = NumHelper(4410)!=1
triggerall = power >=1000
triggerall = command = "combo"
triggerall = statetype = S
triggerall = ctrl
triggerall = stateno != 100
trigger1 = p2bodydist X <= 20
trigger1 = (p2statetype = S) || (p2statetype = C)
trigger1 = p2movetype != H
trigger2 = p2bodydist X <= 20
trigger2 = (p2statetype = S) || (p2statetype = C)
trigger2 = p2movetype != H

[State -1]
type = ChangeState
value = 1200
triggerall = command = "c"
triggerall = statetype != A
trigger1 = statetype = S
trigger1 = ctrl
trigger1 = command = "holdfwd"
trigger1 = p2bodydist X < 3
trigger1 = (p2statetype = S) || (p2statetype = C)
trigger1= p2movetype != H
trigger2 = command = "holdback"
trigger2 = p2bodydist X < 5
trigger2 = (p2statetype = S) || (p2statetype = C)
trigger2 = p2movetype != H

[State -1, estrella]
type = ChangeState
value = 3260
triggerall = NumHelper(3005)!=1
triggerall = NumProjID(271)!=1
triggerall = NumProjID(272)!=1
triggerall = power >=200
triggerall = statetype !=A
triggerall = command = "estrella"
triggerall = p2stateno != 5110
triggerall = p2stateno != 5120
triggerall = p2stateno != 5101
trigger1 = statetype = S
trigger1 = ctrl

[State -1, estrella]
type = ChangeState
value = 3262
triggerall = NumHelper(3005)!=1
triggerall = NumProjID(271)!=1
triggerall = NumProjID(270)!=1
triggerall = power >=200
triggerall = statetype !=A
triggerall = command = "daga"
triggerall = p2stateno != 5110
triggerall = p2stateno != 5120
triggerall = p2stateno != 5101
trigger1 = statetype = S
trigger1 = ctrl

[State -1, estrella]
type = ChangeState
value = 3261
triggerall = NumHelper(3005)!=1
triggerall = NumProjID(270)!=1
triggerall = NumProjID(272)!=1
triggerall = power >=200
triggerall = statetype !=A
triggerall = command = "plato"
triggerall = p2stateno != 5110
triggerall = p2stateno != 5120
trigger1 = statetype = S
trigger1 = ctrl

[State -1, Stand Light Kick]
type = ChangeState
value = 3000
triggerall = p2bodydist x = (1,100)
triggerall = NumHelper(6011)!=1
triggerall = life >=76
triggerall = statetype !=A
triggerall = command = "magia1"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, Stand Light Kick]
type = ChangeState
value = 3100
triggerall = p2stateno !=5110
triggerall = p2stateno !=5120
triggerall = p2stateno !=800
triggerall = p2stateno !=900
triggerall = NumHelper(4110)!=1
triggerall = life >=50
triggerall = power >=1000
triggerall = statetype !=A
triggerall = command = "magia2"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, Stand Light Kick]
type = ChangeState
value = 3109
triggerall = p2bodydist X = (0,200)
triggerall = NumHelper(4017)!=1
triggerall = NumHelper(4010)!=1
triggerall = NumHelper(4013)!=1
triggerall = NumHelper(4410)!=1
triggerall = p2stateno !=5110
triggerall = p2stateno !=5120
triggerall = p2stateno !=800
triggerall = p2stateno !=900
triggerall = NumHelper(6018)!=1
triggerall = power >=2000
triggerall = statetype !=A
triggerall = command = "art_ninja2"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, Stand Light Kick]
type = ChangeState
value = 1799
triggerall = p2statetype !=A
triggerall = NumHelper(4017)!=1
triggerall = NumHelper(4010)!=1
triggerall = NumHelper(4013)!=1
triggerall = NumHelper(4410)!=1
triggerall = p2stateno !=5110
triggerall = p2stateno !=5120
triggerall = p2stateno !=800
triggerall = p2stateno !=900
triggerall = NumHelper(6018)!=1
triggerall = power >=1000
triggerall = statetype !=A
triggerall = command = "art_ninja3"
trigger1 = statetype = S
trigger1 = ctrl

;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
[State -1, Correr]
type = ChangeState
value = 100
triggerall = statetype = S
triggerall = ctrl
triggerall = stateno != 105
triggerall = stateno != 100
trigger1 = command = "FF"
;---------------------------------------------------------------------------
;Run Back
;後退ダッシュ
[State -1, Run Back]
type = ChangeState
value = 105
trigger1 = command = "BB"
trigger1 = statetype = S
trigger1 = ctrl

;---------------------------------------------------------------------------
;Kung Fu Throw
;投げ
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
;---------------------------------------------------------------------------
;Stand Light Punch
;立ち弱パンチ
[State -1, Stand Light Punch]
type = ChangeState
value = 200
triggerall = command = "a"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = stateno = 204
trigger2 = time < 10
trigger12 = stateno = 1901
trigger12 = MoveContact


[State -1]
type = ChangeState
value = 201
triggerall = command = "a"
triggerall = command != "holddown"
trigger1 = stateno = 200
trigger1 = MoveContact
trigger1 = time < 20
trigger12 = stateno = 1901
trigger12 = MoveContact

[State -1]
type = ChangeState
value = 203
triggerall = command = "a"
triggerall = command != "holddown"
trigger1 = stateno = 201
trigger1 = MoveContact
;trigger1 = time < 20
trigger2 = stateno = 210
trigger2 = MoveContact
;trigger2 = time < 20
trigger12 = stateno = 1901
trigger12 = MoveContact

;---------------------------------------------------------------------------
;Stand Strong Punch
;立ち強パンチ
[State -1, Stand Strong Punch]
type = ChangeState
value = 280
triggerall = command = "b"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = stateno = 204
trigger2 = time < 10
trigger12 = stateno = 1901
trigger12 = MoveContact

[State -1]
type = ChangeState
value = 281
triggerall = command = "b"
triggerall = command != "holddown"
trigger1 = stateno = 280
trigger1 = MoveContact
trigger1 = time < 20
trigger12 = stateno = 1901
trigger12 = MoveContact

[State -1]
type = ChangeState
value = 290
triggerall = command = "b"
triggerall = command != "holddown"
trigger1 = stateno = 281
trigger1 = MoveContact
;trigger1 = time < 20
trigger2 = stateno = 210
trigger2 = MoveContact
;trigger2 = time < 20
trigger12 = stateno = 1901
trigger12 = MoveContact
;---------------------------------------------------------------------------
;Stand Light Kick
;立ち弱キック
[State -1, Stand Light Kick]
type = ChangeState
value = 230
triggerall = command = "y"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl


;---------------------------------------------------------------------------
;Standing Strong Kick
;立ち強キック
[State -1, Standing Strong Kick]
type = ChangeState
value = 240
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 200) && time > 5
trigger3 = (stateno = 230) && time > 6

;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;Standing Strong Kick
;立ち強キック
[State -1, Standing Strong Kick]
type = ChangeState
value = 250
triggerall = command = "z"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 200) && time > 5
trigger3 = (stateno = 230) && time > 6

;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;Standing Strong Kick
;立ち強キック
[State -1, Standing Strong Kick]
type = ChangeState
value = 220;260
triggerall = command = "c"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 200) && time > 5
trigger3 = (stateno = 230) && time > 6

;---------------------------------------------------------------------------

;Taunt
;挑発
[State -1, Taunt]
type = ChangeState
value = 195
triggerall = command = "start"
trigger1 = statetype != A
trigger1 = ctrl


;Jump Light Punch
;空中弱パンチ
[State -1, Jump Light Punch]
type = ChangeState
value = 600
triggerall = command = "c"
trigger1 = statetype = A
trigger1 = ctrl


;---------------------------------------------------------------------------
;Jump Strong Punch
[State -1, Jump Strong Punch]
type = ChangeState
value = 610
triggerall = command = "y"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600 || stateno = 630 ;jump_x or jump_a
trigger2 = movecontact

;---------------------------------------------------------------------------
;Jump Light Kick
[State -1, Jump Light Kick]
type = ChangeState
value = 630
triggerall = command = "a"
trigger1 = statetype = A
trigger1 = ctrl

;---------------------------------------------------------------------------
;Jump Strong Kick
;空中強キック
[State -1, Jump Strong Kick]
type = ChangeState
value = 610
triggerall = command = "b"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600 || stateno = 630 ;jump_x or jump_a
trigger2 = movecontact


