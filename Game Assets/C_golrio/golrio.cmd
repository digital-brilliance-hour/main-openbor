
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

[Remap]
x = x
y = y
z = z
a = a
b = b
c = c
s = s

[Defaults]
command.time = 20
command.buffer.time = 1

[Command]
name = "46321"
command = ~B, F, DF, D, DB, a+b
time = 30

[Command]
name = "46321"
command = ~B, F, DF, D, DB, B,a+b
time = 30

[Command]
name = "46321"
command = ~B, F, D, DB, a+b
time = 20

[Command]
name = "46321"
command = ~B, F, D, B, a+b
time = 20

[Command]
name = "236236"
command = ~D, DF, F, D, DF, F,a+b
time = 30

[Command]
name = "236236"
command = ~D, F, D, F, a+b
time = 20

[Command]
name = "214214"
command = ~D, DB, B, D, DB, B,a+b
time = 30

[Command]
name = "214214"
command = ~D, B, D, B, a+b
time = 20

;==オリジナル要素===============================================

[Command]
name = "Golboros"
command = D, D, z
time = 15
;


[Command]
name = "BUKUU"
command = ~D, DF, F, z
;time = 15
;


[Command]
name = "SENPEI"
command = ~D, DB, B, z
;time = 15




;-| Special Motions |------------------------------------------------------
[Command]
name = "623_a"
command = ~F, D, DF, a

[Command]
name = "623_b"
command = ~F, D, DF, b

[Command]
name = "236_x"
command = ~D, DF, F, x

[Command]
name = "236_y"
command = ~D, DF, F, y

[Command]
name = "214_x"
command = ~D, DB, B, x

[Command]
name = "214_y"
command = ~D, DB, B, y

[Command]
name = "2364_a"
command = ~D, DF, F, B,a

[Command]
name = "2364_b"
command = ~D, DF, F, B,b

[Command]
name = "2146_a"
command = ~D,DB,B,F,a

[Command]
name = "2146_b"
command = ~D,DB,B,F,b



;-| Double Tap |-----------------------------------------------------------
[Command]
name = "FF"     ;Required (do not remove)
command = F, F
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



;-| Dir + Button |---------------------------------------------------------
[Command]
name = "down_a"
command = /$D,a
time = 1

[Command]
name = "down_b"
command = /$D,b
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



;==オリジナル要素===============================================

[Command]
name = "holdz"
command = /z
time = 1
;ゲージ溜め


;==============================================================





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
name = "holdx";Required (do not remove)
command = /$x
time = 1

[Command]
name = "holdy";Required (do not remove)
command = /$y
time = 1

[Command]
name = "holda";Required (do not remove)
command = /$a
time = 1

[Command]
name = "holdb";Required (do not remove)
command = /$b
time = 1



;AI起動用
[command]
name="fwd"
command=F
time=1
[command]
name="back"
command=B
time=1
[command]
name="up"
command=U
time=1
[command]
name="down"
command=D
time=1















;=======================================================================
[Statedef -1]


[State -1,AI起動]
type = varset
triggerall = !ishelper
triggerall = RoundState < 2 || (RoundState=2&&ctrl)
triggerall = var(59) < 1
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
trigger30 = NumHelper(40000+ID)
trigger30 = Helper(40000+ID),var(59) > 0
;trigger31 = 1     ;一番左の;を外せば常時AI起動
var(59) = 1
IgnoreHitPause = 1




;ラウンド終了後、AIスイッチOFF
[State -3, AI]
Type = varSet
triggerall = var(59) = 1
trigger1 = StateNo = [195,197]
trigger1 = Win = 1
trigger2 = Lose = 1
trigger3 = DrawGame = 1
trigger4 = RoundState = 4
V = 59
Value = -1
IgnoreHitPause = 1

;２ラウンド目開始後、AIスイッチON
[State -3, AI]
Type = varSet
trigger1 = var(59) = -1
trigger1 = RoundState = 2
V = 59
Value = 1
IgnoreHitPause = 1



[State -3, AI起動用ヘルパー]
type=helper
triggerall=!ishelper
triggerall=RoundState<2||(RoundState=2&&ctrl)
trigger1=!NumHelper(40000+id)
trigger1=alive
trigger1=var(59)<=0
helpertype=normal
name="AI"
stateno=40000
ID=40000+id
pos=9999,9999
keyctrl=1
pausemovetime=999999999
supermovetime=999999999
persistent = 0

[State -3, ↑が余計なことしないように]
type=changestate
trigger1= ishelper
trigger1= ishelper(40000+root,id)
trigger1= stateno!=40000
value=40000

[State -3,enemynearの判別]
Type = varSet
trigger1 = Numenemy = 1
;trigger2 = Numenemy = 2
trigger2 = Numenemy > 1
trigger2 = enemynear,Life > 0
V = 56
Value = 0
IgnoreHitPause = 1
SuperMoveTime = 999999
PauseMoveTime = 999999

[State -3,enemynearの判別
Type = varSet
trigger1 = Numenemy > 1
trigger1 = enemynear,Life = 0
V = 56
Value = 1
IgnoreHitPause = 1
SuperMoveTime = 999999
PauseMoveTime = 999999




[State -3,行動分岐]
Type = varRandom
;triggerall = var(59)
triggerall = StateNo != 120
trigger1 = Time = 1
trigger2 = Time %60= 1
trigger2 = StateNo != 0 && StateNo != 50 && StateNo != 110 && StateNo != 115 && StateNo != 5210
trigger3 = Time %20= 0
trigger3 = StateNo = 0 || StateNo = 110 || StateNo = 115||stateno = 1100||stateno = 630
trigger4 = Time %10= 0
trigger4 = StateNo = 50 || StateNo = 5210
V = 54
Range = 0,99
IgnoreHitPause = 1
SuperMoveTime = 999999
PauseMoveTime = 999999



;ラウンド始めにヘルパー数を調べる
[State -3,ヘル数タッグ用]
Type = varset
triggerall = var(59)
triggerall = var(30) = 0
trigger1 = Numenemy > 1
;trigger1 = Numenemy = 2
trigger1 = enemy(0),NumHelper+enemy(1),NumHelper > 0
trigger1 = RoundState = 2
trigger1 = time = 0
V = 30
Value = enemy(0),NumHelper+enemy(1),NumHelper



[State -3,ヘル数シングル用]
Type = varset
triggerall = var(59)
triggerall = var(31) = 0
trigger1 = Numenemy = 1
trigger1 = enemy,NumHelper > 0
trigger1 = RoundState = 2
trigger1 = time = 0
V = 30
Value = enemy,NumHelper





;ラウンド始めにプロジェクト数を調べる
[State -3,プロ数タッグ用]
Type = varset
triggerall = var(59)
triggerall = var(31) = 0
trigger1 = Numenemy > 1
;trigger1 = Numenemy = 2
trigger1 = enemy(0),Numproj+enemy(1),Numproj > 0
trigger1 = RoundState = 2
trigger1 = time = 0
V = 31
Value = enemy(0),Numproj+enemy(1),Numproj



[State -3,プロ数シングル用]
Type = varset
triggerall = var(59)
triggerall = var(31) = 0
trigger1 = Numenemy = 1
trigger1 = enemy,Numproj > 0
trigger1 = RoundState = 2
trigger1 = time = 0
V = 31
Value = enemy,Numproj







[state -3,リセット]
Type = varset
trigger1 = var(59) <= 0
V = 30
Value = 0


[state -3,リセット]
Type = varset
trigger1 = var(59) <= 0
V = 31
Value = 0



;===================================================================================
;ガード不可かもしれないので暴れる
[State -1,ガード不可暴れ]
Type = ChangeState
value = ifelse(power >= 1000,2000,ifelse(random < 333,1100,1230))
triggerall = var(59) = 1
triggerall = palno != 12
triggerall = ctrl
triggerall = InGuardDist
triggerall = StateType != A
trigger1 = stateno = [120,140]
trigger1 = var(43) > 30
trigger1 =! enemynear(var(56)),HitDefAttr = ,NT,ST,HT
trigger1 = enemynear(var(56)),statetype != A
trigger1 = enemy,NumHelper > var(30) || enemy,numproj > var(31)


[State -1, かわせたらいいなぁ]
Type = changestate
triggerall = palno != 12
triggerall = var(59) > 0
triggerall = StateType != A
triggerall = var(8) > 1
trigger1 = enemynear(var(56)),movetype = A
trigger1 =! enemynear(var(56)),HitDefAttr = ,NT,ST,HT
trigger1 = numhelper(30000)
trigger1 = helper(30000),var(1) = 1
trigger1 = random < 200
value = 700
IgnoreHitPause = 1


[State -1,ガード？]
Type = ChangeState
value = 120
triggerall = palno != 12
triggerall = var(59) = 1
triggerall = ctrl
triggerall = InGuardDist
trigger1 = var(44) > 20
trigger2 = var(46) = 1
trigger2 =! enemynear(var(56)),HitDefAttr = ,NT,ST,HT
IgnoreHitPause = 1



[State -1,投げ回避間に合え]
Type = ChangeState
value = ifelse(power >= 1000,2000,1100)
triggerall = palno != 12
triggerall = var(59) = 1
triggerall = ctrl
trigger1 = var(46) = 1
trigger1 = enemynear(var(56)),HitDefAttr = ,NT,ST,HT
IgnoreHitPause = 1





;適当に暴れる
[State -1,ガード投げ暴れ]
Type = ChangeState
Value = 1230
triggerall = var(59) = 1
triggerall = alive 
triggerall = enemynear(var(56)),HitDefAttr = ,NT,ST,HT
triggerall = stateno = [120,140]
triggerall = random < 333
trigger1 = enemy,NumHelper > 0
trigger1 = enemy,NumHelper > var(30) 
trigger2 = enemy,numproj > 0
trigger2 = enemy,numproj > var(31)




;端で固められたら脱出



[State -1 , 脱出0]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = stateno != 191
triggerall = ctrl
triggerall = power >= 3000
;triggerall = enemynear(var(56)),Life = [1,3000]
triggerall = pos Y > -60
triggerall = enemynear(var(56)),stateno != [5100,5210]
triggerall = var(38) && var(39)
trigger1 = BackEdgeBodyDist < 40
trigger1 = random < 500
trigger1 = p2bodydist X < 50
trigger1 = p2bodydist Y > -30
value = 2200




[State -1 , 脱出1]
type = ChangeState
triggerall = var(59) = 1
triggerall = enemynear(var(56)),movetype = A
triggerall = StateType != A
triggerall = power > 1000
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = BackEdgeBodyDist < 40
trigger1 = p2bodydist X < 150
trigger1 = random < 200
value = 2000


[State -1 , 脱出2]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = BackEdgeBodyDist < 40
trigger1 = p2bodydist X < 100
trigger1 = enemynear(var(56)),statetype = A
trigger1 = random < 400
trigger2 = BackEdgeBodyDist < 20
trigger2 = p2bodydist X < 100
trigger2 = enemynear(var(56)),movetype = A
trigger2 = random < 150
value = 1100



[State -1 , 脱出3]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),stateno != 5120
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = BackEdgeBodyDist < 20
trigger1 = p2bodydist X < 25
value = 800








;====================================================================================




[State -1,投げをジャンプ回避]
Type = ChangeState
Value = 39
triggerall = palno != 12
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),MoveType = A
triggerall = enemynear(var(56)),HitDefAttr = ,NT,ST,HT
triggerall = Ctrl
trigger1 = InGuardDist
trigger1 = P2BodyDist X <= 100
trigger1 = var(54) = [0,40]
trigger2 = P2BodyDist X=[-50,50]
trigger2 = NumHelper(30000)>0
trigger2 = Helper(30000),InguardDist
trigger2 = Facing*enemynear(var(56)),Facing!=-1 || P2Dist X<0
trigger2 = random < 250
IgnoreHitPause = 1




;ガード
[State -1,ガード]
Type = ChangeState
Value = 120
triggerall = palno != 12
triggerall = var(59) = 1
triggerall = Ctrl
triggerall = numenemy 
triggerall = StateNo!=[120,159]
trigger1 = InGuardDist
trigger1 =! enemynear(var(56)),HitDefAttr = ,NT,ST,HT  
trigger1 = var(54) = [0,65]
trigger2 = enemy,NumHelper > 0
trigger2 = enemy,NumHelper > var(30)
trigger2 = InGuardDist 
trigger2 = var(54) = [0,75]
trigger3 = enemy,numproj > 0
trigger3 = enemy,numproj > var(31)
trigger3 = InGuardDist
trigger3 = var(54) = [0,75]
trigger4 =! enemynear(var(56)),HitDefAttr= ,NT,ST,HT
trigger4 = P2BodyDist X=[-50,50]
trigger4 = NumHelper(30000)>0
trigger4 = Helper(30000),InguardDist
trigger4 = Facing*enemynear(var(56)),Facing!=-1 || P2Dist X<0
trigger4 = var(54) = [0,80]
IgnoreHitPause = 1



;=============================================


[State -1, Golboros]
type = ChangeState
value = 7000
triggerall = var(59) = 1
triggerall = var(0) = 0
triggerall = statetype != A
triggerall = ctrl
triggerall = roundstate = 2
triggerall = power >= var(17)
triggerall = numhelper(7000) < var(4)
trigger1 = enemynear(var(56)),movetype = H
trigger1 = enemynear(var(56)),stateno = [120,159]
trigger1 = p2bodydist X = [-5,60]
trigger1 = random <100
trigger2 = backedgedist < 40
trigger2 = random < 100
trigger2 = enemynear(var(56)),movetype = A
trigger2 = p2bodydist X = [-5,80]
trigger3 = fvar(7)=3 || fvar(7)=5 || fvar(7)= 6|| fvar(7)=7
trigger3 = random < 500

[State -1, Golboros]
type = ChangeState
value = 7000
triggerall = var(59) = 1
triggerall = var(0) = 1
triggerall = ctrl
triggerall = roundstate = 2
triggerall = power >= var(17)
triggerall = numhelper(7000) < var(4)
trigger1 = enemynear(var(56)),movetype = H
trigger1 = enemynear(var(56)),stateno = [120,159]
trigger1 = p2bodydist X = [-5,60]
trigger1 = random < 100
trigger2 = backedgedist < 40
trigger2 = random < 100
trigger2 = enemynear(var(56)),movetype = A
trigger2 = p2bodydist X = [-5,80]
trigger3 = fvar(7)=3 || fvar(7)=5 || fvar(7)= 6|| fvar(7)=7
trigger3 = random < 500


[State -1, AI舞空術]
type = ChangeState
value = 8000
triggerall = var(59) = 1
triggerall = ctrl
triggerall = roundstate = 2
triggerall = power >= 1000
triggerall = var(0) = 0
triggerall = var(6) = 1 || var(6) >= 3
trigger1 = random < 50
trigger1 = enemynear(var(56)),statetype = A
trigger1 = P2bodydist X = [40,200]
trigger2 = fvar(7)=1 || fvar(7)=4 || fvar(7)=5 || fvar(7)=7
trigger2 = random < 500
trigger3 = random > 994

[State -1, AI尖兵インストール]
type = ChangeState
value = 8100
triggerall = var(59) = 1
triggerall = statetype != A
triggerall = ctrl
triggerall = power >= 1000
triggerall = roundstate = 2
triggerall = var(2) = 0
triggerall = var(6) >= 2
trigger1 = random < 15
trigger2 = enemynear(var(56)),movetype = A
trigger2 = p2bodydist X > 140
trigger2 = random < 50
trigger3 = fvar(7)=2 || fvar(7)=4 || fvar(7)=6 || fvar(7)=7
trigger3 = random < 500

[State -1, AI尖兵インストール]
type = ChangeState
value = 8100
triggerall = var(59) = 1
triggerall = var(0) = 1
triggerall = ctrl
triggerall = power >= 1000
triggerall = roundstate = 2
triggerall = var(2) = 0
triggerall = var(6) >= 2
trigger1 = random < 7
trigger2 = enemynear(var(56)),movetype = A
trigger2 = p2bodydist X > 100
trigger2 = random < 50
trigger3 = fvar(7)=2 || fvar(7)=4 || fvar(7)=6 || fvar(7)=7
trigger3 = random < 500


;=================================================
;風車撃の後の追撃


[State -1 , AI追撃1]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = enemynear(var(56)),statetype = A
triggerall = enemynear(var(56)),movetype != H
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = p2bodydist X < 25
trigger1 = p2bodydist Y = [-60,20]
trigger1 = stateno = 1101
value = 850



[State -1 , AI追撃2]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = enemynear(var(56)),statetype = A
triggerall = enemynear(var(56)),movetype = H
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [-5,85]
trigger1 = p2bodydist Y = [-30,70]
trigger1 = stateno = 1101
value = 640


[State -1 , AI追撃3]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = stateno = 1101
triggerall = var(38) && var(39)
trigger1 = enemynear(var(56)),statetype = A
trigger1 = enemynear(var(56)),movetype = H
trigger1 = p2bodydist X = [-5,85]
trigger1 = p2bodydist Y = [70,100]
trigger2 = p2bodydist X = [-20,-6]
trigger2 = p2bodydist Y = [60,100]
value = 630

;====================================================



[State -1 , AI10]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = random <= 333
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = (stateno = 400) && time > 7
trigger1 = p2bodydist X = [31,45]
trigger1 = movecontact
trigger2 = (stateno = 430) && time > 9
trigger2 = p2bodydist X = [31,45]
trigger2 = movecontact
value = 410


[State -1 , AI11]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = (stateno = 400) && time > 7
trigger1 = p2bodydist X = [0,30]
trigger1 = movecontact
value = 400



[State -1 , AI12]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = numenemy
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),statetype != L
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = (stateno = 400) && time > 7
trigger1 = enemynear(var(56)),Const(size.height) > 50
trigger1 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger1 = p2bodydist X = [31,55]
trigger1 = movecontact
trigger2 = (stateno = 430) && time > 9
trigger2 = enemynear(var(56)),Const(size.height) > 50
trigger2 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger2 = p2bodydist X = [31,55]
trigger2 = movecontact
value = 440




[State -1 , AI13]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),life>0
triggerall = enemynear(var(56)),pos Y >= 0
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),stateno != 5120
trigger1 = (stateno = 400) && time > 7
trigger1 = p2bodydist X = [0,95]
trigger1 = movecontact
trigger2 = (stateno = 430) && time > 9
trigger2 = p2bodydist X = [0,95]
trigger2 = movehit
trigger2 = random < 333
value = 430


[State -1 , AI14]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = var(38) && var(39)
triggerall = alive
trigger1 = stateno = 200 || stateno = 205
trigger1 = time > 9
trigger1 = movecontact
trigger1 = P2bodydist X < 35
value = 200


[State -1 , AI15]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),pos Y >= 0 
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,50]
trigger1 = (stateno = 230) && time > 9
trigger1 = movecontact
value = 230


[State -1 , AI16]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = (stateno = [200,205]) && time > 9
trigger1 = p2bodydist X = [36,80]
trigger1 = movecontact
trigger1 = random < 200
trigger2 = (stateno = 230) && time > 9
trigger2 = p2bodydist X = [36,80]
trigger2 = movecontact
trigger2 = random < 200
value = 210


[State -1 , AI17]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != C
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = alive
triggerall = var(38) && var(39)
trigger1 = (stateno = [200,205]) && time > 9
trigger1 = p2bodydist X = [36,80]
trigger1 = movecontact
trigger2 = (stateno = 230) && time > 9
trigger2 = p2bodydist X = [36,80]
trigger2 = movecontact
value = 240





[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = alive
triggerall = P2bodydist X = [-5,35]
triggerall = p2bodydist Y = [40,100]
triggerall = random < 333
triggerall = movecontact
triggerall = var(38) && var(39)
trigger1 = stateno = 600
trigger1 = time >= 20
trigger2 = stateno = 630
trigger2 = time >= 20
value = 630



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = alive
triggerall = P2bodydist X = [-5,35]
triggerall = p2bodydist Y = [0,60]
triggerall = random < 333
triggerall = movecontact
triggerall = enemynear(var(56)),statetype = A
triggerall = var(38) && var(39)
trigger1 = stateno = 600
trigger1 = time >= 20
value = 600



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = alive
triggerall = P2bodydist X = [36,50]
triggerall = p2bodydist Y = [0,60]
triggerall = movecontact
triggerall = var(38) && var(39)
trigger1 = stateno = 600
trigger1 = time >= 20
trigger2 = stateno = 630
trigger2 = time >= 20
value = 610



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = vel Y >= 0
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = alive
triggerall = P2bodydist X = [36,75]
triggerall = p2bodydist Y = [0,80]
triggerall = movecontact
triggerall = var(38) && var(39)
trigger1 = stateno = 600
trigger1 = time >= 20
trigger2 = stateno = 630
trigger2 = time >= 20
value = 640






;=====================================================

[State -1 ,AI1]
type = ChangeState
triggerall = var(59) = 1
triggerall = !(enemynear(var(56)),ishelper)
triggerall = enemynear(var(56)),statetype != L
triggerall = StateType != A
triggerall = power >= 3000
;triggerall = enemynear(var(56)),Life = [1,3000]
triggerall = stateno != 191
triggerall = enemynear(var(56)),stateno != [5100,5210]
triggerall = ctrl
triggerall = pos Y > -60
trigger1 = life >= lifemax / 2
trigger1 = random < 100
trigger1 = p2bodydist X < 50
trigger1 = p2bodydist Y > -30
trigger2 = p2bodydist X < 50
trigger2 = p2bodydist Y > -30
trigger2 = random < 800
trigger2 = enemynear(var(56)),movetype = H
trigger3 = life < lifemax / 2
trigger3 = random < 500
trigger3 = p2bodydist X < 50
trigger3 = p2bodydist Y > -30
value = 2200



[State -1 , AI3]
type = ChangeState
triggerall = var(59) = 1
triggerall = enemynear(var(56)),movetype = A
triggerall = StateType != A
triggerall = power > 1200
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
;trigger1 = life > 300
trigger1 = p2bodydist X < 150
trigger1 = var(54) < 20
trigger2 = numpartner
trigger2 = partner,movetype = H
trigger2 = p2bodydist X < 150
trigger2 = var(54) < 60 && !(stateno = [120,159])
trigger3 = BackEdgeBodyDist < 40
trigger3 = p2bodydist X < 100
trigger3 = var(54) < 50
value = 2000



[State -1 , AI4]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = power >= 2000
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = var(54) = [10,35]
trigger1 = enemynear(var(56)),statetype = A
trigger1 = p2bodydist X = [10,40]
trigger1 = p2bodydist Y < -30
value = 2100



[State -1 , AI5]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),stateno != 5120
triggerall = random <= 400 || life < 500 && enemynear(var(56)),life < 200
triggerall = stateno != 191
triggerall = ctrl
trigger1 = p2bodydist X < 5
trigger2 = p2bodydist X = [10,15]
trigger3 = p2bodydist X = [20,24]
trigger4 = p2bodydist X = [11,19]
trigger5 = p2bodydist X < 25
trigger5 = enemynear(var(56)),stateno = [120,159]
value = 800




[State -1 , AI6]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = numenemy
triggerall = enemynear(var(56)),statetype = A
triggerall = enemynear(var(56)),movetype != H
triggerall = stateno != 191
triggerall = ctrl
triggerall = pos Y < -20
trigger1 = p2bodydist X < 25
trigger1 = p2bodydist Y = [-60,20]
value = 850



[State -1 , AI8]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl && prevstateno != 2204
triggerall = enemynear(var(56)),statetype != L
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [-5,40]
trigger1 = enemynear(var(56)),movetype = A
trigger1 = random <= 333;(1000-life)/2
trigger2 = enemynear(var(56)),stateno = 40
trigger2 = p2bodydist X = [5,90]
trigger2 = random <= 333
trigger3 = enemynear(var(56)),vel Y < 0 && enemynear(var(56)),vel X > 0
trigger3 = p2bodydist X = [1,80]
trigger3 = random <= 333
trigger4 = p2bodydist Y < -100
trigger4 = p2bodydist X = [5,90]
trigger4 = random <= 333
trigger5 = BackEdgeBodyDist < 40
trigger5 = p2bodydist X  = [5,90]
trigger5 = enemynear(var(56)),statetype = A
trigger6 = enemynear(var(56)),statetype = A
trigger6 = enemynear(var(56)),movetype = H
trigger6 = p2bodydist X = [10,90]
trigger6 = p2bodydist Y = [-60,60]
trigger7 = enemynear(var(56)),movetype = H
trigger7 = enemynear(var(56)),statetype = A
trigger7 = p2bodydist X = [36,80]
trigger7 = enemynear(var(56)),pos Y = [-140,-15]
trigger7 = prevstateno = 615
trigger8 = numpartner
trigger8 = partner,movetype = H
trigger8 = P2bodydist X = [0,30]
value = 1100



[State -1 , AI12]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = numenemy
triggerall = enemynear(var(56)),statetype = C
triggerall = enemynear(var(56)),movetype = H
triggerall = enemynear(var(56)),statetype != L
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = numtarget(610) || numtarget(640)
triggerall = var(38) && var(39)
trigger1 = enemynear(var(56)),Const(size.height) > 50
trigger1 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger1 = p2bodydist X = [35,60]
trigger1 = p2bodydist Y > -40
trigger2 = p2bodydist X = [20,34]
trigger2 = p2bodydist Y > -20
value = 440




[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = C
triggerall = enemynear(var(56)),movetype = H
triggerall = enemynear(var(56)),statetype != L
triggerall = stateno != 191
triggerall = ctrl
triggerall = enemynear(var(56)),stateno != 5120
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,90]
trigger1 = numtarget(610) || numtarget(640)
value = 430




[State -1 , AI9]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
;triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),movetype = H
triggerall = enemynear(var(56)),statetype != L
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [-5,35]
trigger1 = p2bodydist Y = [-30,50]
value = 215







;=================================================================


;前転
[State -1,ゴロリ]
type = ChangeState
value = 700
triggerall = Alive
triggerall = roundstate = 2
triggerall = var(59) = 1
triggerall = statetype != A
triggerall = ctrl
triggerall = var(8) > 1
triggerall = var(44) <= 0
trigger1 = p2bodydist X = [0,40]
trigger1   = enemynear(var(56)),MoveType = A
trigger1   = random <= ifelse(numenemy = 1,150,10)
trigger2 = enemynear(var(56)),stateType != L
trigger2 = p2bodydist X = [120,320]
trigger2   = random < 100
trigger3 = p2bodydist X = [60,160]
trigger3   = enemynear(var(56)),MoveType = A
trigger3   = random <= 100
trigger3 = power >= 3000
trigger4 = enemynear(var(56)),stateType != L
trigger4 = p2bodydist X = [120,320]
trigger4   = random < 200 
trigger4 = power >= 3000
trigger5 = enemynear(var(56)),stateType != L
trigger5  = enemy,numproj > var(31) || enemy,numhelper > var(30)
trigger5 = p2bodydist X > 150
trigger5   = random <= 250 && InGuardDist
trigger6 = enemynear(var(56)),stateType != L
trigger6 = p2bodydist X = [120,160]
trigger6   = enemynear(var(56)),MoveType = A
trigger6   = random <= 100
trigger7 = p2bodydist X = [0,30]
trigger7   = enemynear(var(56)),stateType = L
trigger7   = random <= 300
trigger7 = frontedgedist > 60
trigger8 = p2bodydist X = [0,50]
trigger8   = enemynear(var(56)),stateType = L || enemynear(var(56)),moveType = A || prevstateno = [5110,5120]
trigger8   = random <= 333
trigger8 = backedgedist < 40
trigger9 = p2bodydist X > 120
trigger9 = var(47) = 1
trigger9 = random < 500





;前転
[State -1,ゴロリ]
type = ChangeState
value = 700
triggerall = Alive
triggerall = roundstate = 2
triggerall = var(59) = 1
triggerall = statetype != A
triggerall = var(8) > 1
triggerall = (stateno = 150) || (stateno = 152)
triggerall = var(44) <= 20
trigger1 = power >= 1500
trigger1   = random <= 20
trigger2 = backedgedist < 30
trigger2 = power >= 500
trigger2 = random < 100




;バックステップ
[State -1]
type = ChangeState
value = 107
triggerall = Alive
triggerall = roundstate = 2
triggerall = var(59) = 1
triggerall = Facing = enemynear(var(56)),Facing
triggerall = statetype != A
triggerall = var(8) > 1
triggerall = ctrl
triggerall = enemynear(var(56)),vel X < 1
trigger1   = enemynear(var(56)),MoveType = A
trigger1   = random < 300
trigger1 = enemynear(var(56)),p2bodydist X = [30,100]
;trigger1 = p2bodydist X = [30,110]
trigger1 = BackEdgeDist > 60
trigger2 = numpartner
trigger2 = ctrl
trigger2 	= life < (const(data.life)/3)
trigger2 	= life < Partner,life
trigger2   = random >= 300
trigger2 = p2bodydist X = [0,100]
trigger2 = BackEdgeDist > 60
trigger2   = enemynear(var(56)),MoveType != H
trigger3 = enemynear(var(56)),movetype = A
trigger3 = backedgedist > 80
trigger3 = random < 200
trigger3 = P2bodydist X = [0,100]
trigger4 = backedgedist > 60
trigger4 = P2bodydist X = [-5,40]
trigger4 = enemynear(var(56)),stateno = 5120
trigger4 = random < 800
trigger5 = stateno = 195 || prevstateno = 195
trigger5 = enemynear(var(56)),movetype = A
trigger5 = P2bodydist X = [-5,40]




;パワー溜め
[State -2]
type = ChangeState
value = 710
triggerall = Alive
triggerall = roundstate = 2
triggerall = var(59) = 1
triggerall = statetype != A
triggerall = ctrl
triggerall = var(8) = 1 || var(8) = 3
triggerall = power < PowerMax
trigger1 = p2bodydist X = [120,320]
trigger1 = enemynear(var(56)),MoveType != A
trigger1 = random <= 800
trigger1 = enemy,NumHelper > var(30) || enemy,numproj > var(31)
trigger2 = p2bodydist Y <= -130
trigger2 = enemynear(var(56)),MoveType != A
trigger2 = random <= 800
trigger2 = enemy,NumHelper > var(30) || enemy,numproj > var(31)
trigger3 = enemynear(var(56)),statetype = L
trigger3 = enemynear(var(56)),MoveType != A
trigger3 = random <= 800
trigger3 = enemy,NumHelper > var(30) || enemy,numproj > var(31)
trigger4 = numenemy > 1
trigger4 = enemynear(0),movetype = H && enemynear(1),movetype = H
trigger4 = P2bodydist X > 120 || P2bodydist Y < -10
trigger4 = numpartner
trigger4 = partner,alive
trigger5 = numenemy = 1
trigger5 = enemynear(var(56)),statetype = L
trigger5 = P2bodydist X > 80
trigger5 = random < 400
trigger6 = prevstateno = 810
trigger6 = enemynear(var(56)),movetype = H
trigger7 = enemynear(var(56)),pos Y <= -240 && var(0) = 0





;================================================================

[State -1 , AI10]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = random <= 333
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,50]
value = 410


[State -1 , AI11]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = random <= 333
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,50]
value = 400



[State -1 , AI12]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = numenemy
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),statetype != L
triggerall = random <= 333
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
trigger1 = enemynear(var(56)),Const(size.height) > 50
trigger1 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger1 = p2bodydist X = [35,60]
trigger1 = p2bodydist Y > -40
trigger2 = p2bodydist X = [20,34]
trigger2 = p2bodydist Y > -20
value = 440




[State -1 , AI13]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),life>0
triggerall = enemynear(var(56)),pos Y >= 0
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
triggerall = enemynear(var(56)),stateno != 5120
trigger1 = random <= 333
trigger1 = enemynear(var(56)),Const(size.height) > 50
trigger1 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger1 = p2bodydist X <= 15
trigger2 = enemynear(var(56)),Const(size.height) > 50
trigger2 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger2 = random <= 200
trigger2 = p2bodydist X = [21,35]
trigger3 = random <= 200
trigger3 = enemynear(var(56)),Const(size.height) > 50
trigger3 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger3 = p2bodydist X = [41,55]
trigger4 = enemynear(var(56)),Const(size.height) > 50
trigger4 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger4 = random <= 200
trigger4 = p2bodydist X = [61,75]
trigger5 = enemynear(var(56)),Const(size.height) > 50
trigger5 = enemynear(var(56)),Const(size.head.pos.y) <= -70
trigger5 = random <= 200
trigger5 = p2bodydist X = [81,95]
trigger6 = random <= 500
trigger6 = enemynear(var(56)),Const(size.height) <= 50
trigger6 = enemynear(var(56)),Const(size.head.pos.y) > -70
trigger6 = p2bodydist X = [21,95]
trigger7 = enemynear(var(56)),movetype = H
trigger7 = enemynear(var(56)),Const(size.height) <= 50
trigger7 = enemynear(var(56)),Const(size.head.pos.y) > -70
trigger7 = p2bodydist X = [21,95]
value = 430


[State -1 , AI14]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),movetype = I
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = stateno != 191
triggerall = ctrl
triggerall = var(38) && var(39)
trigger1 = random < 400
trigger1 = p2bodydist X < 30
trigger2 = random <= 150
trigger2 = p2bodydist X = [51,60]
trigger3 = random <= 200
trigger3 = p2bodydist X = [71,80]
value = 200


[State -1 , AI15]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != A
triggerall = random <= 499
triggerall = enemynear(var(56)),pos Y >= 0 
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [10,60]
trigger2 = (stateno = 230) && time > 9
value = 230


[State -1 , AI16]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = random <= 333
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,50]
trigger2 = p2bodydist X = [61,70]
trigger3 = p2bodydist X = [81,90]
trigger4 = prevstateno = 215
trigger4 = p2bodydist X = [36,80]
trigger4 = enemynear(var(56)),movetype = H
value = 210


[State -1 , AI17]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype = S
triggerall = enemynear(var(56)),movetype != H
triggerall = enemynear(var(56)),movetype != A
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = random <= 150
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = var(38) && var(39)
trigger1 = p2bodydist X = [0,25]
trigger2 = p2bodydist X = [35,45]
trigger3 = p2bodydist X = [55,65]
value = 240



[State -1 , AI18]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = var(47) = 0
triggerall = enemynear(var(56)),life > 0
triggerall = enemy,NumHelper <= var(30) || enemy,numproj <= var(31) 
;triggerall = enemynear(var(56)),movetype != A
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = numprojID(1000) < 2
triggerall = !numhelper(7000)
trigger1 = random < ifelse(!numprojID(1000),200,50)
trigger1 = p2bodydist X > 180
trigger2 = p2bodydist X > 150
trigger2 = random > ifelse(!numprojID(1000),500,150)
trigger2 = enemynear(var(56)),statetype = L
value = 1000


[State -1 , AI19]
type = null;ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = stateno = 1001
triggerall = animtime = 0
trigger1 = numenemy > 1
trigger1 = enemynear(0),movetype != H || enemynear(1),movetype != H
trigger2 = numenemy = 1
trigger2 = enemynear(var(56)),statetype != L
trigger3 = p2life <= 0
value = 1002


[State -1 , AI20]
type = ChangeState
triggerall = var(59) = 1
triggerall = enemynear(var(56)),life > 0
triggerall = StateType != A
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != A && enemy, NumProj <= var(31) && enemy,NumHelper <= var(30)
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = enemynear(var(56)),movetype = H
trigger1 = enemynear(var(56)),statetype = A
trigger1 = enemynear(var(56)),pos Y < -90 && P2bodydist X = [150,220]
trigger2 = numpartner
trigger2 = partner,movetype = H
trigger2 = p2bodydist X = [30,150]
trigger2 = var(54) > 60
trigger3 = numpartner
trigger3 = enemynear(var(56)),movetype = H
trigger3 = var(54) > 60
trigger4 = numprojID(1000) > 0
trigger4 = random < 333
trigger5 = var(47) = 1
trigger5 = P2bodydist X > 180
trigger5 = random < 333
value = 1200



[State -1 , AI21]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),life > 0
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != A && enemy, NumProj <= var(31) && enemy,NumHelper <= var(30)
triggerall = random <= 5
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = p2bodydist X < 130
value = 1210




[State -1 , AI22]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemynear(var(56)),life > 0
triggerall = enemynear(var(56)),statetype != L
triggerall = enemynear(var(56)),movetype != A && enemy, NumProj <= var(31) && enemy,NumHelper <= var(30)
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = random <= 100
trigger1 = p2bodydist X = [100,150]
trigger2 = P2bodydist X = [40,60]
trigger2 = random < 200
value = 1220


[State -1 , AI23]
type = ChangeState
triggerall = var(59) = 1
triggerall = enemynear(var(56)),life > 0
triggerall = StateType != A
triggerall = enemynear(var(56)),movetype != A && enemy, NumProj <= var(31) && enemy,NumHelper <= var(30)
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = enemynear(var(56)),statetype != L
trigger1 = random <= 333
trigger1 = p2bodydist X < 100
trigger2 = enemynear(var(56)),statetype = L
trigger2 = p2bodydist X = [0,100]
trigger2 = random <= 200
value = 1230



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = enemynear(var(56)),movetype != A
triggerall = var(0) = 0
triggerall = var(38) && var(39)
trigger1 = (Facing * (enemynear(var(56)),Facing) = 1)&&(P2bodydist X > 0 ||(Backedgedist > enemynear(var(56)),Backedgedist))
;trigger1 = p2bodydist X = [-10,-80]
trigger1 = vel Y > 0
trigger2 = p2bodydist X = [-10,-5]
trigger2 = vel Y > 0
trigger3 = vel Y < 0
trigger3 = P2bodydist X = [-5,40]
trigger3 = p2bodydist Y = [40,100]
trigger3 = random < 100
value = 630



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = vel Y < 0
triggerall = enemynear(var(56)),statetype = A
triggerall = var(0) = 0
triggerall = var(38) && var(39)
trigger1 = vel X > 0 
trigger1 = p2bodydist X = [-5,55]
trigger1 = p2bodydist Y = [0,60]
trigger2 = vel X <= 0
trigger2 = p2bodydist X = [-5,35]
trigger2 = p2bodydist Y = [0,60]
value = 600



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = vel Y >= 0
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = var(0) = 0
triggerall = var(38) && var(39)
trigger1 = vel X > 0 
trigger1 = p2bodydist X = [-5,60]
trigger1 = p2bodydist Y = [0,100]
trigger2 = vel X <= 0
trigger2 = p2bodydist X = [-5,45]
trigger2 = p2bodydist Y = [0,100]
value = 610



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType = A
triggerall = ctrl = 1
triggerall = vel Y >= 0
triggerall = enemynear(var(56)),Const(size.height) > 50
triggerall = enemynear(var(56)),Const(size.head.pos.y) <= -70
triggerall = var(0) = 0
triggerall = var(38) && var(39)
trigger1 = vel X > 0 
trigger1 = p2bodydist X = [0,80]
trigger1 = p2bodydist Y = [0,80]
trigger2 = vel X <= 0
trigger2 = p2bodydist X = [0,65]
trigger2 = p2bodydist Y = [0,80]
value = 640



[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = var(35) < 300
triggerall = numenemy
triggerall = StateType = A
triggerall = !win
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = (Facing * (enemynear(var(56)),Facing) = 1)&&(P2bodydist X > 0 ||(Backedgedist > enemynear(var(56)),Backedgedist))
triggerall = var(0) >= 1
triggerall = P2bodydist X < 0
triggerall = var(38) && var(39)
trigger1 = var(54) = [5,35]
trigger2 = var(54) = [60,85]
value = 630




[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = numenemy
triggerall = var(35) < 300
triggerall = StateType = A
triggerall = random <= 400
triggerall = !win
triggerall = ctrl = 1
triggerall = var(36) <= 10
triggerall = var(0) >= 1
triggerall = P2bodydist X >= 0
triggerall = var(38) && var(39)
trigger1 = vel Y > 0
trigger1 = enemynear(var(56)),statetype = A
trigger2 = var(52)
trigger2 = enemynear(var(56)),statetype = A
value = ifelse(random<499,610,640)

[State -1 , AI]
type = ChangeState
triggerall = var(59) = 1
triggerall = var(35) < 300
triggerall = numenemy
triggerall = StateType = A
triggerall = random <= 400
triggerall = ctrl = 1
triggerall = !win
triggerall = var(0) >= 1
triggerall = P2bodydist X >= 0
triggerall = var(38) && var(39)
trigger1 = enemynear(var(56)),statetype = S
trigger2 = enemynear(var(56)),statetype = C
value = ifelse(random<499,610,630)







;==================================================================


[State -1 , AIrun]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = enemy,NumHelper <= var(30)
triggerall = enemy,numproj <= var(31) 
triggerall = enemynear(var(56)),movetype != A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = random < 200
trigger1 = p2bodydist X > 120
trigger2 = numprojID(1000) > 0
trigger2 = random < 333
trigger3 = var(47) = 1
trigger3 = random < 400
trigger3 = p2bodydist X > 120
value = 99


[State -1 , AIBrun]
type = ChangeState
triggerall = var(59) = 1
triggerall = var(8) <= 1
triggerall = StateType != A
triggerall = enemy,NumHelper <= var(30)
triggerall = enemy,numproj <= var(31) 
triggerall = enemynear(var(56)),statetype = L
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = random < 333
trigger1 = p2bodydist X = [0,30]
value = 105




[State -1 , AIwalk]
type = ChangeState
triggerall = var(59) = 1
triggerall = numenemy
triggerall = StateType != A
;triggerall = enemy,NumHelper <= var(30)
;triggerall = enemy,numproj <= var(31) 
triggerall = enemynear(var(56)),movetype != A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = random < 250
trigger1 = p2bodydist X > 150
trigger2 = p2bodydist X > 100
trigger2 = random < 333
trigger3 = var(47) = 1
trigger3 = random < 500
trigger3 = p2bodydist X > 100
value = 19


[State -1 , AIBwalk]
type = ChangeState
triggerall = var(59) = 1
triggerall = numenemy
triggerall = StateType != A
triggerall = enemy,NumHelper <= var(30)
triggerall = enemy,numproj <= var(31) 
triggerall = enemynear(var(56)),statetype = L
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
trigger1 = random < 200
trigger1 = p2bodydist X = [0,20]
value = 18




[State -1 , AIjump]
type = ChangeState
triggerall = var(59) = 1
triggerall = StateType != A
triggerall = P2Life > 0
triggerall = stateno != 191
triggerall = ctrl = 1
triggerall = enemynear(var(56)),statetype != A || enemynear(var(56)),statetype != L
trigger1 = p2bodydist X = [0,120]
trigger1 = random < 50
trigger2 = p2bodydist X = [50,120]
trigger2 = enemy,NumHelper > var(30) || enemy,numproj > var(31)
trigger2 = random < 100
trigger3 = enemynear(var(56)),movetype = A
trigger3 = p2bodydist X = [0,120]
trigger3 = random < 100
trigger4 = enemy,NumHelper > var(30) || enemy,numproj > var(31)
trigger4 = InGuardDist
trigger4 = random < 70
value = 39



;================================================================================








;覇王亀腹脚
[State -1, Light Kung Fu Palm]
type = ChangeState
value = 2000
triggerall = var(59) <= 0
triggerall = power >= 1000
triggerall = statetype != A
triggerall = command = "46321"
trigger1 = ctrl

;回天風車撃
[State -1, Light Kung Fu Palm]
type = ChangeState
value = 2100
triggerall = var(59) <= 0
triggerall = power >= 2000
triggerall = statetype != A
triggerall = command = "236236"
trigger1 = ctrl

;ブラジルＦｅａｓｔ！！
[State -1, Light Kung Fu Palm]
type = ChangeState
value = 2200
triggerall = var(59) <= 0
triggerall = power >= 3000
triggerall = statetype != A
triggerall = command = "214214"
trigger1 = ctrl

;熱投拳
[State -1, Light Kung Fu Palm]
type = ChangeState
value = 1000
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "214_x" || command = "214_y"
trigger1 = ctrl

;風車撃
[State -1, Light Kung Fu Upper]
type = ChangeState
value = 1100
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "623_a" || command = "623_b"
trigger1 = ctrl

;亀腹脚
[State -1, Light Kung Fu Blow]
type = ChangeState
value = 1200
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "2364_a"
trigger1 = ctrl

;亀腹脚
[State -1, Light Kung Fu Blow]
type = ChangeState
value = 1210
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "2364_b"
trigger1 = ctrl

;亀腹脚
[State -1, Light Kung Fu Blow]
type = ChangeState
value = 1220
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "2146_a"
trigger1 = ctrl

;亀腹脚
[State -1, Light Kung Fu Blow]
type = ChangeState
value = 1230
triggerall = var(59) <= 0
triggerall = statetype != A
triggerall = command = "2146_b"
trigger1 = ctrl




;==========================================================================



[State -1, Golboros]
type = ChangeState
value = 7000
triggerall = var(59) <= 0
triggerall = power >= var(17)
triggerall = command = "Golboros"
triggerall = numhelper(7000) < var(4)
triggerall = ctrl
trigger1 = var(0) = 0
trigger1 = statetype != A
trigger2 = var(0) = 1



[State -1, 舞空術]
type = ChangeState
value = 8000
triggerall = var(59) <= 0
triggerall = var(0) = 0
triggerall = power >= 1000
triggerall = command = "BUKUU"
triggerall = var(6) = 1 || var(6) >= 3
trigger1 = ctrl



[State -1, 勝手にｶｧﾝ]
type = ChangeState
value = 8100
triggerall = var(59) <= 0
triggerall = var(2) = 0
triggerall = power >= 1000
triggerall = command = "SENPEI"
triggerall = var(6) >= 2
triggerall = ctrl
trigger1 = var(0) = 0
trigger1 = statetype != A
trigger2 = var(0) = 1






;前転
[State -1]
type = ChangeState
value = 700
triggerall = var(59) <= 0
triggerall = var(8) >= 2
triggerall = command = "c"
trigger1 = statetype != A
trigger1 = ctrl
trigger2 = (stateno = 150) || (stateno = 152)
trigger2 = power >= 500



;パワー溜め
[State -1]
type = ChangeState
value = 710
triggerall = var(59) <= 0
triggerall = (var(8) = 1) || (var(8) = 3)
trigger1 = command = "holdz"
trigger1 = statetype != A
trigger1 = ctrl
trigger1 = power < PowerMax







;===========================================================================
;---------------------------------------------------------------------------
;Run Fwd
;ダッシュ
[State -1, Run Fwd]
type = ChangeState
value = 100
triggerall = var(59) <= 0
trigger1 = command = "FF"
trigger1 = statetype = S
trigger1 = ctrl

;---------------------------------------------------------------------------
;Run Back
;後退ダッシュ
[State -1, Run Back]
type = ChangeState
value = 105
triggerall = var(59) <= 0
triggerall = var(8) <= 1
trigger1 = command = "BB"
trigger1 = statetype = S
trigger1 = ctrl



;Run Back
;バックステップ
[State -1, Run Back]
type = ChangeState
value = 107
triggerall = var(59) <= 0
triggerall = var(8) > 1
trigger1 = command = "BB"
trigger1 = statetype = S
trigger1 = ctrl




;投げ
[State -1, Kung Fu Throw]
type = ChangeState
value = 800
triggerall = var(59) <= 0
triggerall = command = "y"
triggerall = statetype = S
triggerall = ctrl
triggerall = stateno != 100
trigger1 = command = "holdfwd"
trigger1 = p2bodydist X < 20
trigger1 = (p2statetype = S) || (p2statetype = C)
trigger1 = p2movetype != H
trigger2 = command = "holdback"
trigger2 = p2bodydist X < 25
trigger2 = (p2statetype = S) || (p2statetype = C)
trigger2 = p2movetype != H
;---------------------------------------------------------------------------
;投げ
[State -1, Kung Fu Throw]
type = ChangeState
value = 850
triggerall = var(59) <= 0
triggerall = command = "y"
triggerall = pos Y < -20
triggerall = statetype = A
triggerall = ctrl
trigger1 = command = "holdfwd"
trigger1 = p2bodydist X < 20
trigger1 = (p2statetype = A)
trigger1 = p2movetype != H
trigger2 = command = "holdback"
trigger2 = p2bodydist X < 25
trigger2 = (p2statetype = A)
trigger2 = p2movetype != H

;===========================================================================
;---------------------------------------------------------------------------
;Stand Light Punch
;立ち弱パンチ
[State -1, Stand Light Punch]
type = ChangeState
value = 200
triggerall = var(59) <= 0
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = stateno = 200 || stateno = 205
trigger2 = time > 9

;---------------------------------------------------------------------------
;Stand Strong Punch
;立ち強パンチ
[State -1, Stand Strong Punch]
type = ChangeState
value = 210
triggerall = var(59) <= 0
triggerall = command = "y"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 200) && time > 9
trigger3 = (stateno = 230) && time > 9

;---------------------------------------------------------------------------
;Stand Light Kick
;立ち弱キック
[State -1, Stand Light Kick]
type = ChangeState
value = 230
triggerall = var(59) <= 0
triggerall = command = "a"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 230) && time > 9

;---------------------------------------------------------------------------
;Standing Strong Kick
;立ち強キック
[State -1, Standing Strong Kick]
type = ChangeState
value = 240
triggerall = var(59) <= 0
triggerall = command = "b"
triggerall = command != "holddown"
trigger1 = statetype = S
trigger1 = ctrl
trigger2 = (stateno = 200) && time > 9
trigger3 = (stateno = 230) && time > 9

;---------------------------------------------------------------------------
;Taunt
;挑発
[State -1, Taunt]
type = ChangeState
value = 195
triggerall = var(59) <= 0
triggerall = command = "start"
trigger1 = statetype != A
trigger1 = ctrl

;---------------------------------------------------------------------------
;Crouching Light Punch
;しゃがみ弱パンチ
[State -1, Crouching Light Punch]
type = ChangeState
value = 400
triggerall = var(59) <= 0
triggerall = command = "x"
triggerall = command = "holddown"
trigger1 = statetype = C
trigger1 = ctrl
trigger2 = (stateno = 400) && time > 7

;---------------------------------------------------------------------------
;Crouching Strong Punch
;しゃがみ強パンチ
[State -1, Crouching Strong Punch]
type = ChangeState
value = 410
triggerall = var(59) <= 0
triggerall = command = "y"
triggerall = command = "holddown"
trigger1 = statetype = C
trigger1 = ctrl
trigger2 = (stateno = 400) && time > 7
trigger3 = (stateno = 430) && time > 9
;---------------------------------------------------------------------------
;Crouching Light Kick
;しゃがみ弱キック
[State -1, Crouching Light Kick]
type = ChangeState
value = 430
triggerall = var(59) <= 0
triggerall = command = "a"
triggerall = command = "holddown"
trigger1 = statetype = C
trigger1 = ctrl
trigger2 = (stateno = 400) && time > 7
trigger3 = (stateno = 430) && time > 9
;---------------------------------------------------------------------------
;Crouching Strong Kick
;しゃがみ強キック
[State -1, Crouching Strong Kick]
type = ChangeState
value = 440
triggerall = var(59) <= 0
triggerall = command = "b"
triggerall = command = "holddown"
trigger1 = statetype = C
trigger1 = ctrl
trigger2 = (stateno = 400) && time > 7
trigger3 = (stateno = 430) && time > 9

;---------------------------------------------------------------------------
;Jump Light Punch
;空中弱パンチ
[State -1, Jump Light Punch]
type = ChangeState
value = 600
triggerall = var(59) <= 0
triggerall = command = "x"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600
trigger2 = time >= 20
;---------------------------------------------------------------------------
;Jump Strong Punch
[State -1, Jump Strong Punch]
type = ChangeState
value = 610
triggerall = var(59) <= 0
triggerall = command = "y"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600
trigger2 = time >= 20
trigger3 = stateno = 630
trigger3 = time >= 20
;---------------------------------------------------------------------------
;Jump Light Kick
[State -1, Jump Light Kick]
type = ChangeState
value = 630
triggerall = var(59) <= 0
triggerall = command = "a"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600
trigger2 = time >= 20
trigger3 = stateno = 630
trigger3 = time >= 20
;---------------------------------------------------------------------------
;Jump Strong Kick
;空中強キック
[State -1, Jump Strong Kick]
type = ChangeState
value = 640
triggerall = var(59) <= 0
triggerall = command = "b"
trigger1 = statetype = A
trigger1 = ctrl
trigger2 = stateno = 600
trigger2 = time >= 20
trigger3 = stateno = 630
trigger3 = time >= 20



















; AI
[Statedef 40000]
anim=40000;なにも表示しないｱﾆﾒでもいいけど入れなくても全然問題ない
ctrl=0

[State 40000]
type = assertspecial
trigger1 = 1
flag = invisible

[State 40000,間違いで本体が来たら立ちへ移行]
type=selfstate
trigger1=!ishelper
value=0

[State 40000,プレイヤー判定]
type=varset
trigger1=command="a"&&root,command="a"
trigger2=command="b"&&root,command="b"
trigger3=command="c"&&root,command="c"
trigger4=command="x"&&root,command="x"
trigger5=command="y"&&root,command="y"
trigger6=command="z"&&root,command="z"
trigger7=command="start"&&root,command="start"
trigger8=command="fwd"&&root,command="fwd"
trigger9=command="back"&&root,command="back"
trigger10=command="up"&&root,command="up"
trigger11=command="down"&&root,command="down"
var(59)=-11

[State 40000,プレイヤー判定]
type=parentvarset
trigger1=command="a"&&root,command="a"
trigger2=command="b"&&root,command="b"
trigger3=command="c"&&root,command="c"
trigger4=command="x"&&root,command="x"
trigger5=command="y"&&root,command="y"
trigger6=command="z"&&root,command="z"
trigger7=command="start"&&root,command="start"
trigger8=command="fwd"&&root,command="fwd"
trigger9=command="back"&&root,command="back"
trigger10=command="up"&&root,command="up"
trigger11=command="down"&&root,command="down"
var(59)=-11

[State 40000,立ったら消失]
Type = DestroySelf
triggerall=isHelper
trigger1=root,var(59)!=0||var(59)=-11
trigger2=command="a"&&root,command="a"
trigger3=command="b"&&root,command="b"
trigger4=command="c"&&root,command="c"
trigger5=command="x"&&root,command="x"
trigger6=command="y"&&root,command="y"
trigger7=command="z"&&root,command="z"
trigger8=command="start"&&root,command="start"
trigger9=command="fwd"&&root,command="fwd"
trigger10=command="back"&&root,command="back"
trigger11=command="up"&&root,command="up"
trigger12=command="down"&&root,command="down"

[State 40000,AIﾌﾗｸﾞON]
Type=varset
triggerall=var(59)!=-11
trigger1=root,command="a"
trigger2=root,command="b"
trigger3=root,command="c"
trigger4=root,command="x"
trigger5=root,command="y"
trigger6=root,command="z"
trigger7=root,command="start"
trigger8=root,command="fwd"&&(roundstate=2&&root,ctrl)
trigger9=root,command="back"&&(roundstate=2&&root,ctrl)
trigger10=root,command="up"&&(roundstate=2&&root,ctrl)
trigger11=root,command="down"&&(roundstate=2&&root,ctrl)
var(59)=1








