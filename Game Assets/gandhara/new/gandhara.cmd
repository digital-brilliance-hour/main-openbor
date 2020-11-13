[Remap]
x = a
y = b
z = c
a = x
b = y
c = z
s = s


[Command]
name = "AI1"
command = U, D, U, D, U, D, U, D
time = 1
[Command]
name = "AI2"
command = U, D, U, D, U, D, U ,D,U
time = 1
[Command]
name = "AI3"
command = U, D, U, D, U, D, U ,D ,U ,D
time = 1
[Command]
name = "AI4"
command = U, D, U, D, U, D, U, D ,b
time = 1
[Command]
name = "AI5"
command = U, D, D, D, U, D, U, D, U
time = 1
[Command]
name = "AI6"
command = U, U, U, D, U, D, U ,D ,U ,D
time = 1
[Command]
name = "AI7"
command = U, D, U, D, U, D, U, D ,x
time = 1
[Command]
name = "AI8"
command = U, D, U, D, U, D, U ,D,U ,y
time = 1
[Command]
name = "AI9"
command = U, D, U, D, U, D, U ,D ,U ,D ,z
time = 1
[Command]
name = "AI10"
command = U, D, U, D, U, D, U, D ,U ,D ,a
time = 1
[Command]
name = "AI11"
command = U, D, U, D, U, D, U ,D,U,D,U,b
time = 1
[Command]
name = "AI12"
command = U, D, U, D, U, D, U ,D ,U ,D,c
time = 1
[Command]
name = "AI13"
command = U, D, U, D, U, D, U, D ,U ,D ,F
time = 1
[Command]
name = "AI14"
command = U, D, U, D, U, D, U ,D,U,D,U,B
time = 1
[Command]
name = "AI15"
command = U, D, U, D, U, D, U ,D ,U ,D,D,D
time = 1
[Command]
name = "AI16"
command = U, F, U, D, U, D, U ,D ,U ,D ,z
time = 1
[Command]
name = "AI17"
command = U, F, U, D, U, D, U, D ,U ,D ,a
time = 1
[Command]
name = "AI18"
command = U, F, U, D, U, D, U ,D,U,D,U,b
time = 1
[Command]
name = "AI19"
command = U, F, U, D, U, D, U ,U ,U ,D ,z
time = 1
[Command]
name = "AI20"
command = U, F, U, D, U, D, U, B ,U ,D ,a
time = 1
[Command]
name = "AI21"
command = U, F, U, D, B, D, U ,D,U,D,U,b
time = 1
[Command]
name = "AI22"
command = U, F, U, D, U, D, U ,U ,U ,D ,z,b
time = 1
[Command]
name = "AI23"
command = U, F, U, D, U, D, U, B ,U ,D ,a,c
time = 1
[Command]
name = "AI24"
command = U, F, U, D, B, D, U ,D,U,D,U,b,a
time = 1
[Command]
name = "AI25"
command = U, F, U, D, U, D, U ,U ,U ,D ,z,b,U
time = 1
[Command]
name = "AI26"
command = U, F, U, D, U, D, U, B ,U ,D ,a,c,D
time = 1
[Command]
name = "AI27"
command = U, F, U, D, B, D, U ,D,U,D,U,b,a,F
time = 1
[Command]
name = "AI28"
command = U, F, U, D, B, D, U ,D,U,D,U,b,a,a,a
time = 1
[Command]
name = "AI29"
command = U, F, U, D, U, D, U ,U ,U ,D ,z,b,U,a,b
time = 1
[Command]
name = "AI30"
command = U, F, U, D, U, D, U, B ,U ,D ,a,c,D,a,c
time = 1
[Command]
name = "AI31"
command = U, F, U, D, B, D, U ,D,U,D,U,b,a,F,a,c
time = 1


;=========================================
;Mugen_2_TsMugen added this commands
;=========================================

[Command]
name    = "call-st"
command = s
time    = 1

;=========================================


; The Gandhara CMD file.

;-| Super Motions |--------------------------------------------------------
;Magia AB
[Command]
name = "magia_ab"
command = ~D, DF, F, x+y
;command = ~D, DF, F, a+b

;Magia Y
[Command]
name = "magia_y"
command = ~D, DB, B, x+y
;command = ~D, DF, F, y

;214X
[Command]
name = "214x"
command = ~F, D, DF, x+y
;command = ~D, DB, B, x

;214Y
[Command]
name = "214y"
command = ~D, DB, B, a+b
;command = ~D, DB, B, y

;214AB
[Command]
name = "214ab"
command = ~D, DF, F, a+b
;command = ~D, DB, B, a+b

;-| Special Motions |------------------------------------------------------
;Magia A
[Command]
name = "magia_a"
command = ~D, DF, F, a

;Magia B
[Command]
name = "magia_b"
command = ~D, DF, F, b

;Magia X
[Command]
name = "magia_x"
command = ~D, DF, F, x

;214A
[Command]
name = "214a"
command = ~D, DB, B, a

;214B
[Command]
name = "214b"
command = ~D, DB, B, b

;623X
[Command]
name = "623x"
command = ~F, D, DF, x

;--------------------
;Charge_Down_up
[Command]
name = "chargedownup_a"
command = ~60$D, U, a
time = 10

[Command]
name = "chargedownup_b"
command = ~60$D, U, b
time = 10

[Command]
name = "chargedownup_c"
command = ~60$D, U, c
time = 10

[Command]
name = "chargedownup_x"
command = ~60$D, U, x
time = 10

[Command]
name = "chargedownup_y"
command = ~60$D, U, y
time = 10

[Command]
name = "chargedownup_z"
command = ~60$D, U, z
time = 10

[Command]
name = "jumpaorb"
command = a

[Command]
name = "jumpaorb"
command = b

;--------------------
;Charge_Back_fwd
[Command]
name = "chargebackfwd_a"
command = ~60$B, F, a
time = 10

[Command]
name = "chargebackfwd_b"
command = ~60$B, F, b
time = 10

[Command]
name = "chargebackfwd_x"
command = ~60$B, F, x
time = 10

[Command]
name = "chargedownup_c"
command = ~60$D, U, c
time = 10

[Command]
name = "chargedownup_x"
command = ~60$D, U, x
time = 10

[Command]
name = "chargedownup_y"
command = ~60$D, U, y
time = 10

[Command]
name = "chargedownup_z"
command = ~60$D, U, z
time = 10



;-| Double Tap |-----------------------------------------------------------
[Command]
name = "FF";Required (do not remove)
command = F, F
time = 10

[Command]
name = "BB";Required (do not remove)
command = B, B
time = 10

;-| 2/3 Button Combination |-----------------------------------------------
[Command]
name = "recovery";Required (do not remove)
command = a+b
time = 1

;-| Dir + Button |---------------------------------------------------------
[Command]
name = "fwd_s"
command = /F,s
time = 1

[Command]
name = "fwd_a"
command = /F,a
time = 1

[Command]
name = "fwd_b"
command = /F,b
time = 1

[Command]
name = "fwd_c"
command = /F,c
time = 1

[Command]
name = "fwd_x"
command = /F,x
time = 1

[Command]
name = "fwd_y"
command = /F,y
time = 1

[Command]
name = "fwd_z"
command = /F,z
time = 1

[Command]
name = "back_a"
command = /B,a
time = 1

[Command]
name = "back_b"
command = /B,b
time = 1

[Command]
name = "back_c"
command = /B,c
time = 1

[Command]
name = "down_a"
command = /$D,a
time = 1

[Command]
name = "down_b"
command = /$D,b
time = 1

[Command]
name = "down_c"
command = /$D,c
time = 1

[Command]
name = "fwd_ab"
command = /F, a+b
time = 1

[Command]
name = "back_ab"
command = /B, a+b
time = 1

;-| Single Button |---------------------------------------------------------
[Command]
name = "s"
command = s
time = 1

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
name = "hold_s"
command = /$s
time = 1

-| Hold Button |-----------------------------------------------------------

[Command]
name = "hold_yb"
command = /y+b
time = 30

[Command]
name = "hold_yb"
command = /x+a
time = 30

[Command]
name = "hold_a"
command = /a
time = 1

[Command]
name = "hold_ab"
command = /a+b
time = 1

[Command]
name = "hold_b"
command = /b
time = 30

[Command]
name = "hold_c"
command = /c
time = 1

[Command]
name = "hold_x"
command = /x
time = 1

[Command]
name = "hold_y"
command = /y
time = 30

[Command]
name = "hold_z"
command = /z
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
name = "holdup";Required (do not remove)
command = /$U
time = 1

[Command]
name = "holddown";Required (do not remove)
command = /$D
time = 1



;=========================================
;Mugen_2_TsMugen added this commands
;=========================================

[Command]
name    = "longjump"
command = D,$U
time    = 18

;=========================================



[Statedef -1]
[State -1,2]
type = Varset
triggerall = var(51) != 1
trigger1 = command = "AI1"
trigger2 = command = "AI2"
trigger3 = command = "AI3"
trigger4 = command = "AI4"
trigger5 = command = "AI5"
trigger6 = command = "AI6"
trigger7 = command = "AI7"
trigger8 = command = "AI8"
trigger9 = command = "AI9"
trigger10 = command = "AI10"
trigger11 = command = "AI11"
trigger12 = command = "AI12"
trigger13 = command = "AI13"
trigger14 = command = "AI14"
trigger15 = command = "AI15"
trigger16 = command = "AI16"
trigger17 = command = "AI17"
trigger18 = command = "AI18"
trigger19 = command = "AI19"
trigger20 = command = "AI20"
trigger21 = command = "AI21"
trigger22 = command = "AI22"
trigger23 = command = "AI23"
trigger24 = command = "AI24"
trigger25 = command = "AI25"
trigger26 = command = "AI26"
trigger27 = command = "AI27"
trigger28 = command = "AI28"
trigger29 = command = "AI29"
trigger30 = command = "AI30"
trigger31 = command = "AI31"
trigger32 = 1
v = 51
value = 1

[state -1, AI]
type = ChangeState
value = Ifelse(EnemyNear,StateType = C,131,130)
triggerall = Var(51) = 1
triggerall = Random <= ifelse (StateType = A, 111, 666) && Ctrl
trigger1 = StateType != A && (Enemy, HitDefAttr = SCA, AA, SA ,HA ,AP, SP, HP)
trigger1 = MoveType = I && ((EnemyNear, MoveType = A  && P2BodyDist X <= 50) || (Enemy, NumProj >= 1)) && Ctrl




[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = A
triggerall = p2movetype != H
triggerall = power >= 1333
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X < 50
value = 3200

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = p2StateType != L
triggerall = p2movetype != A
triggerall = power >= 1333
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X < 50
value = 3400

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = p2StateType != L
triggerall = p2movetype != A
triggerall = power >= 1333
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [81,100]
value = 3300

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = A
triggerall = p2movetype != H
triggerall = power >= 1333
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [51,100]
value = 3000

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != L
triggerall = p2StateType != A
triggerall = p2movetype != A
triggerall = power >= 1333
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X > 100
value = 3100

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = L
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
value = 105322

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = p2StateType != L
triggerall = p2movetype != A
triggerall = p2movetype != H
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X < 3
value = 820

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = p2StateType != L
triggerall = p2movetype != A
triggerall = p2movetype != H
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [1,4]
value = 810

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = p2StateType != L
triggerall = p2movetype != H
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X < 5
value = 800

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = S
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X <= 50
value = 400

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = S
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X <= 80
value = 210

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType != A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X <= 70
value = 410

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [40,70]
value = 200

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [30,80]
value = 230

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2StateType = A
triggerall = p2movetype != H
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X < 80
value = 1010

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2movetype != A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [71,210]
value = 1030

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2movetype != A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [101,120]
value = 1000

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2movetype != A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
trigger1 = p2bodydist X = [81,90]
trigger2 = stateno != 191
trigger2 = p2bodydist X = [111,120]
trigger3 = stateno != 191
trigger3 = p2bodydist X = [131,140]
trigger4 = stateno != 191
trigger4 = p2bodydist X = [161,170]
trigger5 = stateno != 191
trigger5 = p2bodydist X = [191,200]
value = 1005

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2movetype = A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
value = 105321

[State -1 , Crouch L.Punch]
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = p2movetype != A
triggerall = random <= 333
triggerall = P2Life > 0
triggerall = ctrl = 1
trigger1 = stateno != 191
value = 100321


[State -1 , combo 1];しゃがみ弱P連打→強P
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 400
trigger1 = movecontact
value = 410;400 + 10 * (p2bodydist X > 30)

[State -1 , combo 1b];しゃがみ強P→突進(弱,強ランダム)
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 410
trigger1 = movecontact
value = 1000 + 5 * (random > 500)

[State -1 , combo 1c];(突進弱→対空,ゲージがあれば掌底連打)
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 1000
trigger1 = animelem = 5, >0
trigger1 = movehit
value = 1010 + 1990*(power>=1000)

[State -1 , combo 1d];(突進強→ドリルキック)
type = ChangeState
triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 1006
trigger1 = animelem = 5, >0
trigger1 = movehit
value = 1030

[State -1 , combo 1e];(対空,ドリルキック,掌底連打→超ドリルキック)
type = ChangeState
triggerall = var(51) = 1
triggerall = power >= 1000
triggerall = P2Life > 0
triggerall = movehit
trigger1 = stateno = 3002
trigger1 = animelem = 4, >0
trigger2 = stateno = 1011
trigger2 = animelem = 2, >0
trigger3 = stateno = 1031
trigger3 = animelem = 4, >0
value = 3100 +110*(StateType = A)


[State -1 , combo 2];立ち弱P→強P
type = ChangeState
;triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 200
trigger1 = movecontact
value = 210

[State -1 , combo 2b];立ち強P→キック
type = ChangeState
;triggerall = var(51) = 1
triggerall = StateType != A
triggerall = P2Life > 0
trigger1 = stateno = 210
trigger1 = movecontact
value = 231


;===========================================================================

;===========================================================================
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;--Other--------------------------------------------------------------------
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;RunFwd
[State -1]
type = ChangeState
value = 100
trigger1 = command = "FF"
trigger1 = statetype = S
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;RunBack
[State -1]
type = ChangeState
value = 105
trigger1 = command = "BB"
trigger1 = statetype = S
trigger1 = ctrl = 1

;===========================================================================
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;--Hyper--------------------------------------------------------------------
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;--Standing attacks---------------------------------------------------------
;---------------------------------------------------------------------------
;Mortais
[State -1]
type = ChangeState
value = 3400
triggerall = command = "214y"
triggerall = power >= 1000
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006
trigger10 = movecontact
trigger10 = stateno = 3001
trigger11 = movecontact
trigger11 = stateno = 3002
trigger12 = movecontact
trigger12 = stateno = 3302
trigger13 = movecontact
trigger13 = stateno = 3303

;---------------------------------------------------------------------------
;Especial Joelhada
[State -1]
type = ChangeState
value = 3300
triggerall = command = "magia_y"
triggerall = power >= 2000
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006
trigger10 = movecontact
trigger10 = stateno = 3001
trigger11 = movecontact
trigger11 = stateno = 3002
trigger12 = movecontact
trigger12 = stateno = 3302

;---------------------------------------------------------------------------
;SuperMortal
[State -1]
type = ChangeState
value = 3200
triggerall = command = "214x"
triggerall = power >= 1000
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006
trigger10 = movecontact
trigger10 = stateno = 3001
trigger11 = movecontact
trigger11 = stateno = 3002
trigger12 = movecontact
trigger12 = stateno = 3302
trigger13 = movecontact
trigger13 = stateno = 3303
trigger14 = movecontact
trigger14 = stateno = 3401
trigger15 = movecontact
trigger15 = stateno = 3403

;---------------------------------------------------------------------------
;SuperParafuso
[State -1]
type = ChangeState
value = 3100
triggerall = command = "magia_ab"
triggerall = power >= 1000
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006
trigger10 = movecontact
trigger10 = stateno = 3001
trigger11 = movecontact
trigger11 = stateno = 3002
trigger12 = movecontact
trigger12 = stateno = 3302
trigger13 = movecontact
trigger13 = stateno = 3303
trigger14 = movecontact
trigger14 = stateno = 3401
trigger15 = movecontact
trigger15 = stateno = 3403
trigger16 = movecontact
trigger16 = stateno = 3401
trigger17 = movecontact
trigger17 = stateno = 3403

;---------------------------------------------------------------------------
;Muquecas
[State -1]
type = ChangeState
value = 3000
triggerall = command = "214ab"
triggerall = power >= 1000
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006

;---------------------------------------------------------------------------
;--Air attacks--------------------------------------------------------------
;---------------------------------------------------------------------------
;SuperMortal Combo
[State -1]
type = ChangeState
value = 630
triggerall = command = "214x"
;triggerall = power >= 1000
trigger1 = statetype = A
trigger1 = ctrl = 1

;SuperMortal Combo
[State -1]
type = ChangeState
value = 3210
triggerall = command = "214x"
triggerall = power >= 1000
trigger1 = statetype = A
trigger1 = ctrl = 1
trigger2 = stateno = 1011
trigger2 = movecontact
trigger3 = stateno = 1031
trigger3 = movecontact
trigger4 = stateno = 3101
trigger4 = movecontact
trigger5 = stateno = 3110
trigger5 = movecontact

;---------------------------------------------------------------------------
;SuperParafuso Combo
[State -1]
type = ChangeState
value = 630
triggerall = command = "magia_ab"
;triggerall = power >= 1000
trigger1 = statetype = A
trigger1 = ctrl = 1

;SuperParafuso Combo
[State -1]
type = ChangeState
value = 3110
triggerall = command = "magia_ab"
triggerall = power >= 1000
trigger1 = statetype = A
trigger1 = ctrl = 1
trigger2 = stateno = 1011
trigger2 = movecontact
trigger3 = stateno = 1031
trigger3 = movecontact
trigger4 = stateno = 3201
trigger4 = movecontact
trigger5 = stateno = 3203
trigger5 = movecontact
trigger6 = stateno = 3210
trigger6 = movecontact
    
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;--Special------------------------------------------------------------------
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;--Standing attacks---------------------------------------------------------
;---------------------------------------------------------------------------
;Ombrada 
[State -1]
type = ChangeState
value = 1000
triggerall = command = "magia_a"
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410

;Ombrada
[State -1]
type = ChangeState
value = 1005
triggerall = command = "magia_b"
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410

;---------------------------------------------------------------------------
;Mortal
[State -1]
type = ChangeState
value = 1010
triggerall = command = "623x"
trigger1 = statetype != A
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006

;---------------------------------------------------------------------------
;Parafuso
[State -1]
type = ChangeState
value = 1030
triggerall = command = "magia_x"
trigger1 = statetype != L
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 210
trigger4 = movecontact
trigger4 = stateno = 230
trigger5 = movecontact
trigger5 = stateno = 231
trigger6 = movecontact
trigger6 = stateno = 400
trigger7 = movecontact
trigger7 = stateno = 410
trigger8 = movecontact
trigger8 = stateno = 1000
trigger9 = movecontact
trigger9 = stateno = 1006

;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;--THROW--------------------------------------------------------------------
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;--Standing attacks---------------------------------------------------------
;---------------------------------------------------------------------------
[State -1, Throw]
type = ChangeState
value = 800
triggerall = command = "a"
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

;---------------------------------------------------------------------------
[State -1, Throw]
type = ChangeState
value = 810
triggerall = command = "b"
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
;---------------------------------------------------------------------------

[State -1, Throw]
type = ChangeState
value = 820
triggerall = command = "x"
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

;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
;--MOVES--------------------------------------------------------------------
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------

;---------------------------------------------------------------------------
;--Standing attacks---------------------------------------------------------
;---------------------------------------------------------------------------
;Stand_A
[State -1]
type = ChangeState
value = 200
triggerall = command = "a";Place name of command here
triggerall = command != "holddown";Standing moves should have this line
trigger1 = statetype = S
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Stand_B
[State -1]
type = ChangeState
value = 210
triggerall = command = "b"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200

;---------------------------------------------------------------------------
;Stand_X
[State -1]
type = ChangeState
value = 230
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200

;Stand_X Combo
[State -1]
type = ChangeState
value = 231
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 210

;---------------------------------------------------------------------------
;--Crouch attacks-----------------------------------------------------------
;---------------------------------------------------------------------------
;Crouch_A
[State -1]
type = ChangeState
value = 400
triggerall = command = "a";Place name of command here
trigger1 = statetype = C
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;Crouch_B
[State -1]
type = ChangeState
value = 410
triggerall = command = "b"
trigger1 = statetype = C
trigger1 = ctrl = 1
trigger2 = movecontact
trigger2 = stateno = 200
trigger3 = movecontact
trigger3 = stateno = 400

;Taunt
[State -1]
type = ChangeState
value = 185
triggerall = command = "c"
trigger1 = statetype != A
trigger1 = ctrl = 1

;---------------------------------------------------------------------------
;--Air attacks--------------------------------------------------------------
;---------------------------------------------------------------------------
;Jump_A
[State -1]
type = ChangeState
value = 600
trigger1 = command = "jumpaorb"
trigger1 = statetype = A
trigger1 = ctrl = 1

;Jump_X
[State -1]
type = ChangeState
value = 630
trigger1 = command = "x"
trigger1 = statetype = A
trigger1 = ctrl = 1



